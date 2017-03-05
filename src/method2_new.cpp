#include "gcre.h"

joined_res join_method2_new(join_config& conf, vector<uid_ref>& uids,
  vector<int>& join_gene_signs, vec2d_d& value_table, vec2d_u64& case_mask,
  paths_vec* paths0, paths_vec* paths1, paths_vec* paths_res, uint64_t total_paths){

  std::cout.imbue(std::locale("en_US.UTF8"));

  bool keep_paths = paths_res != NULL;

  if(keep_paths){
    paths_res->size = total_paths;
    paths_res->width_ul = paths1->width_ul;
    paths_res->num_cases = conf.num_cases;
    paths_res->pos.resize(paths_res->size, vec_u64(paths_res->width_ul, 0));
    paths_res->neg.resize(paths_res->size, vec_u64(paths_res->width_ul, 0));
    paths_res->con.resize(paths_res->size, vec_u64(paths_res->width_ul, 0));
    printf("  ** resized stored paths: %d x %d\n", paths_res->size, paths_res->width_ul);
  }

  int vlen = (int) ceil(conf.num_cases/64.0);
  int vlen2 = (int) ceil(conf.num_controls/64.0);

  vec2d_u64 &paths_pos1 = paths0->pos;
  vec2d_u64 &paths_pos2 = paths1->pos;
  vec2d_u64 &paths_neg1 = paths0->neg;
  vec2d_u64 &paths_neg2 = paths1->neg;
  vec2d_u64 &paths_conflict1 = paths0->con;
  vec2d_u64 &paths_conflict2 = paths1->con;

  // priority queue for the indices of the top K paths in the data
  priority_queue<Score> scores;
  // dummy score to avoid empty check
  scores.push(Score());

  // TODO conf.nthreads
  int nthreads = 1;

  int flipped_pivot_length = paths_pos2.size();
  int prev_src = -1;
  int total_srcs = 0;
  int path_idx = 0;

  long total_comps = 0;
  long zero_comps = 0;

  for(int i = 0; i < uids.size(); i++){
    // Check if source node has changed
    uid_ref& uid = uids[i];
    if(uid.src != prev_src){
      prev_src = uid.src;
      total_srcs++;
      // if((total_srcs % 100) == 0){
      //   Rcout << "    " <<  total_srcs << " source nodes for paths of length " << path_length << " and their permutations have been processed!" << std::endl;
      //   checkUserInterrupt();
      // }
    }

    if(uid.count == 0) continue;
    int sign;
    if(conf.path_length > 3) sign = join_gene_signs[i];

    // Get the data of the first path
    std::vector<uint64_t> &path_pos1 = paths_pos1[i];
    std::vector<uint64_t> &path_neg1 = paths_neg1[i];
    std::vector<uint64_t> &path_conflict1 = paths_conflict1[i];

    for(int j = uid.location; j < (uid.location + uid.count); j++){
      int tid = 0;

      if(conf.path_length < 3) sign = join_gene_signs[j];

      if(conf.path_length == 3){
        int sign2 = join_gene_signs[i];
        int sign3 = join_gene_signs[j];
        sign = ((sign2 == -1 && sign3 == 1) || (sign2 == 1 && sign3 == -1)) ? -1 : 1;
      }

      vec_u64 joined_pos(path_pos1.size());
      vec_u64 joined_neg(path_pos1.size());
      vec_u64 joined_conflict(path_pos1.size());

      // TODO ??
      std::vector<uint64_t> &path_pos2 = (sign == 1) ? paths_pos2[j] : paths_neg2[j];
      std::vector<uint64_t> &path_neg2 = (sign == 1) ? paths_neg2[j] : paths_pos2[j];
      std::vector<uint64_t> &path_conflict2 = paths_conflict2[j];

      for(int k = 0; k < vlen + vlen2; k++){
        uint64_t temp_pos = path_pos1[k] | path_pos2[k];
        uint64_t temp_neg = path_neg1[k] | path_neg2[k];

        total_comps += 1;
        if(temp_pos == 0 || temp_neg == 0)
          zero_comps += 1;

        uint64_t temp_conflict = (path_conflict1[k] | path_conflict2[k]) | (temp_pos & temp_neg);
        joined_conflict[k] = temp_conflict;
        joined_pos[k] = temp_pos ^ (temp_conflict & temp_pos);
        joined_neg[k] = temp_neg ^ (temp_conflict & temp_neg);
      }

      if(keep_paths){
        paths_res->pos[path_idx] = joined_pos;
        paths_res->neg[path_idx] = joined_neg;
        paths_res->con[path_idx] = joined_conflict;
      }

      path_idx += 1;

      int cases_pos = 0;
      int cases_neg = 0;
      int controls_pos = 0;
      int controls_neg = 0;
      for(int k = 0; k < vlen; k++){
        cases_pos += __builtin_popcountll(joined_pos[k]);
        controls_neg += __builtin_popcountll(joined_neg[k]);
      }
      for(int k = vlen; k < vlen + vlen2; k++){
        controls_pos += __builtin_popcountll(joined_pos[k]);
        cases_neg += __builtin_popcountll(joined_neg[k]);
      }

      int cases = cases_pos + cases_neg;
      int controls = controls_pos + controls_neg;

      double score = value_table[cases][controls];
      double flipped_score = value_table[controls][cases];

      if(score > scores.top().score){
        scores.push(Score(score, i, j));
        if(scores.size() > conf.top_k)
          scores.pop();
      }
      if(flipped_score > scores.top().score){
        scores.push(Score(flipped_score, i, j + flipped_pivot_length));
        if(scores.size() > conf.top_k)
          scores.pop();
      }

      for(int m = 0; m < conf.iterations; m++){

        double perm_score = 0;
        double perm_flipped_score = 0;

        vec_u64& caseorcontrol = case_mask[m];
        int cases_pos_m = 0;
        int controls_pos_m = 0;
        int cases_neg_m = 0;
        int controls_neg_m = 0;

        for(int k = 0; k < vlen; k++){
          uint64_t permuted_path_k = joined_pos[k] & caseorcontrol[k];
          cases_pos_m += __builtin_popcountll(permuted_path_k);
          permuted_path_k = joined_neg[k] & caseorcontrol[k];
          controls_neg_m += __builtin_popcountll(permuted_path_k);
        }
        for(int k = vlen; k < vlen + vlen2; k++){
          uint64_t permuted_path_k = joined_pos[k] & caseorcontrol[k];
          controls_pos_m += __builtin_popcountll(permuted_path_k);
          permuted_path_k = joined_neg[k] & caseorcontrol[k];
          cases_neg_m += __builtin_popcountll(permuted_path_k);
        }

        int new_cases = cases_pos_m + cases_neg_m + (controls_pos - controls_pos_m) + (controls_neg - controls_neg_m);
        int new_controls = controls_pos_m + controls_neg_m + (cases_pos - cases_pos_m) + (cases_neg - cases_neg_m);

        perm_score = value_table[new_cases][new_controls];
        perm_flipped_score = value_table[new_controls][new_cases];
      }
    }

  }

  joined_res res;
  res.permuted_scores.resize(conf.iterations, 0);
  res.scores.clear();
  while(!scores.empty()){
    res.scores.push_back(scores.top());
    scores.pop();
  }

  return res;
}
