#include <typeinfo>
#include <sstream>
#include "gcre.h"

using namespace std;

static char* get_opt(char** begin, char** end, const string& option) {
  char** itr = find(begin, end, option);
  if (itr != end && ++itr != end) {
    return *itr;
  }
  return 0;
}

static bool has_opt(char** begin, char** end, const string& option) {
  return find(begin, end, option) != end;
}

static void read_vec(istream& fdata, vec2d_u64& vec){
  string line, val;

  getline(fdata, line, ':');
  cout << line << ": ";
  getline(fdata, line, ' ');
  int width = stoi(line);
  getline(fdata, line);
  stringstream buf(line);
  while (getline(buf, val, ' ')) {
    if(vec.size() == 0 || vec.back().size() == width)
      vec.push_back(vec_u64());
    vec.back().push_back(stoul(val));
  }
  cout << vec.size() << endl;
}

int main(int argc, char* argv[]) {
  char** arge = argc + argv;
  
  string file;
  if(has_opt(argv, arge, "-f")){
    file = string(get_opt(argv, arge, "-f"));
  } else {
    cout << "need data file (-f)" << endl;
    return 1;
  }
  cout << "using data file: " << file << endl;

  // PATH 4
  // CASE 1537
  // CTRL 1537
  // TOTL 1276368

  int width;
  string line, val, v;
  stringstream buf, ub;
  ifstream fdata(file);

  getline(fdata, line);
  int path_length = stoi(line.substr(5));
  getline(fdata, line);
  int num_cases = stoi(line.substr(5));
  getline(fdata, line);
  int num_controls = stoi(line.substr(5));
  getline(fdata, line);
  uint64_t total_paths = stoul(line.substr(5));

  printf("\nheader:\n\n");
  printf("   path_length : %d\n", path_length);
  printf("     num_cases : %d\n", num_cases);
  printf("  num_controls : %d\n", num_controls);
  printf("   total_paths : %lu\n", total_paths);
  printf("\n");

  vector<uid_ref> uids;
  getline(fdata, line, ' ');
  cout << line << ": ";
  getline(fdata, line);
  buf.str(line);
  buf.clear();
  while (getline(buf, val, ' ')) {
    uid_ref uid;
    ub.str(val);
    ub.clear();
    getline(ub, v, ':');
    uid.src = stoi(v);
    getline(ub, v, ':');
    uid.trg = stoi(v);
    getline(ub, v, ':');
    uid.count = stoi(v);
    getline(ub, v, ':');
    uid.location = stoi(v);
    uids.push_back(uid);
  }
  cout << uids.size() << endl;

  vector<int> signs;
  getline(fdata, line, ' ');
  cout << line << ": ";
  getline(fdata, line);
  buf.str(line);
  buf.clear();
  while (getline(buf, val, ' ')) {
    signs.push_back(stoi(val));
  }
  cout << signs.size() << endl;

  vec2d_d value_table;
  getline(fdata, line, ':');
  cout << line << ": ";
  getline(fdata, line, ' ');
  width = stoi(line);
  getline(fdata, line);
  buf.str(line);
  buf.clear();
  while (getline(buf, val, ' ')) {
    if(value_table.size() == 0 || value_table.back().size() == width)
      value_table.push_back(vector<double>());
    value_table.back().push_back(stod(val));
  }
  cout << value_table.size() << endl;

  vec2d_i cases;
  getline(fdata, line, ':');
  cout << line << ": ";
  getline(fdata, line, ' ');
  width = stoi(line);
  getline(fdata, line);
  buf.str(line);
  buf.clear();
  while (getline(buf, val, ' ')) {
    if(cases.size() == 0 || cases.back().size() == width)
      cases.push_back(vector<int>());
    cases.back().push_back(stoi(val));
  }
  cout << cases.size() << endl;

  vec2d_u64 paths0pos;
  read_vec(fdata, paths0pos);

  vec2d_u64 paths0neg;
  read_vec(fdata, paths0neg);

  vec2d_u64 paths1pos;
  read_vec(fdata, paths1pos);

  vec2d_u64 paths1neg;
  read_vec(fdata, paths1neg);

  getline(fdata, line);
  cout << line << endl;

  printf("done\n");
}