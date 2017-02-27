// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// parsePaths
void parsePaths(IntegerMatrix data, int nCases, int nControls, std::string file_path);
RcppExport SEXP geneticsCRE_parsePaths(SEXP dataSEXP, SEXP nCasesSEXP, SEXP nControlsSEXP, SEXP file_pathSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type data(dataSEXP);
    Rcpp::traits::input_parameter< int >::type nCases(nCasesSEXP);
    Rcpp::traits::input_parameter< int >::type nControls(nControlsSEXP);
    Rcpp::traits::input_parameter< std::string >::type file_path(file_pathSEXP);
    parsePaths(data, nCases, nControls, file_path);
    return R_NilValue;
END_RCPP
}
// JoinIndicesMethod1
List JoinIndicesMethod1(IntegerVector srcuid, IntegerVector trguids2, List uids_CountLoc, IntegerVector joining_gene_sign, NumericMatrix ValueTable, int nCases, int nControls, int K, int iterations, IntegerMatrix CaseORControl, int method, int pathLength, int nthreads, std::string pos_path1, std::string pos_path2, std::string dest_path_pos);
RcppExport SEXP geneticsCRE_JoinIndicesMethod1(SEXP srcuidSEXP, SEXP trguids2SEXP, SEXP uids_CountLocSEXP, SEXP joining_gene_signSEXP, SEXP ValueTableSEXP, SEXP nCasesSEXP, SEXP nControlsSEXP, SEXP KSEXP, SEXP iterationsSEXP, SEXP CaseORControlSEXP, SEXP methodSEXP, SEXP pathLengthSEXP, SEXP nthreadsSEXP, SEXP pos_path1SEXP, SEXP pos_path2SEXP, SEXP dest_path_posSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerVector >::type srcuid(srcuidSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type trguids2(trguids2SEXP);
    Rcpp::traits::input_parameter< List >::type uids_CountLoc(uids_CountLocSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type joining_gene_sign(joining_gene_signSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type ValueTable(ValueTableSEXP);
    Rcpp::traits::input_parameter< int >::type nCases(nCasesSEXP);
    Rcpp::traits::input_parameter< int >::type nControls(nControlsSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< int >::type iterations(iterationsSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type CaseORControl(CaseORControlSEXP);
    Rcpp::traits::input_parameter< int >::type method(methodSEXP);
    Rcpp::traits::input_parameter< int >::type pathLength(pathLengthSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< std::string >::type pos_path1(pos_path1SEXP);
    Rcpp::traits::input_parameter< std::string >::type pos_path2(pos_path2SEXP);
    Rcpp::traits::input_parameter< std::string >::type dest_path_pos(dest_path_posSEXP);
    rcpp_result_gen = Rcpp::wrap(JoinIndicesMethod1(srcuid, trguids2, uids_CountLoc, joining_gene_sign, ValueTable, nCases, nControls, K, iterations, CaseORControl, method, pathLength, nthreads, pos_path1, pos_path2, dest_path_pos));
    return rcpp_result_gen;
END_RCPP
}
// JoinIndicesMethod2
List JoinIndicesMethod2(IntegerVector srcuid, IntegerVector trguids2, List uids_CountLoc, IntegerVector joining_gene_sign, NumericMatrix ValueTable, int nCases, int nControls, int K, int iterations, IntegerMatrix CaseORControl, int method, int pathLength, int nthreads, std::string pos_path1, std::string neg_path1, std::string conflict_path1, std::string pos_path2, std::string neg_path2, std::string conflict_path2, std::string dest_path_pos, std::string dest_path_neg, std::string dest_path_conflict);
RcppExport SEXP geneticsCRE_JoinIndicesMethod2(SEXP srcuidSEXP, SEXP trguids2SEXP, SEXP uids_CountLocSEXP, SEXP joining_gene_signSEXP, SEXP ValueTableSEXP, SEXP nCasesSEXP, SEXP nControlsSEXP, SEXP KSEXP, SEXP iterationsSEXP, SEXP CaseORControlSEXP, SEXP methodSEXP, SEXP pathLengthSEXP, SEXP nthreadsSEXP, SEXP pos_path1SEXP, SEXP neg_path1SEXP, SEXP conflict_path1SEXP, SEXP pos_path2SEXP, SEXP neg_path2SEXP, SEXP conflict_path2SEXP, SEXP dest_path_posSEXP, SEXP dest_path_negSEXP, SEXP dest_path_conflictSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerVector >::type srcuid(srcuidSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type trguids2(trguids2SEXP);
    Rcpp::traits::input_parameter< List >::type uids_CountLoc(uids_CountLocSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type joining_gene_sign(joining_gene_signSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type ValueTable(ValueTableSEXP);
    Rcpp::traits::input_parameter< int >::type nCases(nCasesSEXP);
    Rcpp::traits::input_parameter< int >::type nControls(nControlsSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< int >::type iterations(iterationsSEXP);
    Rcpp::traits::input_parameter< IntegerMatrix >::type CaseORControl(CaseORControlSEXP);
    Rcpp::traits::input_parameter< int >::type method(methodSEXP);
    Rcpp::traits::input_parameter< int >::type pathLength(pathLengthSEXP);
    Rcpp::traits::input_parameter< int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< std::string >::type pos_path1(pos_path1SEXP);
    Rcpp::traits::input_parameter< std::string >::type neg_path1(neg_path1SEXP);
    Rcpp::traits::input_parameter< std::string >::type conflict_path1(conflict_path1SEXP);
    Rcpp::traits::input_parameter< std::string >::type pos_path2(pos_path2SEXP);
    Rcpp::traits::input_parameter< std::string >::type neg_path2(neg_path2SEXP);
    Rcpp::traits::input_parameter< std::string >::type conflict_path2(conflict_path2SEXP);
    Rcpp::traits::input_parameter< std::string >::type dest_path_pos(dest_path_posSEXP);
    Rcpp::traits::input_parameter< std::string >::type dest_path_neg(dest_path_negSEXP);
    Rcpp::traits::input_parameter< std::string >::type dest_path_conflict(dest_path_conflictSEXP);
    rcpp_result_gen = Rcpp::wrap(JoinIndicesMethod2(srcuid, trguids2, uids_CountLoc, joining_gene_sign, ValueTable, nCases, nControls, K, iterations, CaseORControl, method, pathLength, nthreads, pos_path1, neg_path1, conflict_path1, pos_path2, neg_path2, conflict_path2, dest_path_pos, dest_path_neg, dest_path_conflict));
    return rcpp_result_gen;
END_RCPP
}
// getMatchingList
Rcpp::List getMatchingList(Rcpp::IntegerVector uids, Rcpp::IntegerVector counts, Rcpp::IntegerVector location);
RcppExport SEXP geneticsCRE_getMatchingList(SEXP uidsSEXP, SEXP countsSEXP, SEXP locationSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type uids(uidsSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type counts(countsSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type location(locationSEXP);
    rcpp_result_gen = Rcpp::wrap(getMatchingList(uids, counts, location));
    return rcpp_result_gen;
END_RCPP
}
