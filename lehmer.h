#ifndef LEHMER
#define LEHMER

#include "count_tree.h"
//Get the i-th Lehmer Code of length len
//If n >= len!, wrap around and start from the beginning
void get_lehmer_code(int n, int * dst, int len);

//Get the permutation described by the given Code using a pre-existing Count Tree
void get_permutation_from_lehmer_with_tree(int * code, int len, count_tree_t * tree, char * dst);

//Get the permutation described by the given Code
void get_permutation_from_lehmer(int * code, char * arr, int len, char * dst);

//Get the n-th permutation using an existing Count Tree
void get_permutation_with_tree(int n, count_tree_t * tree, char * dst);

//Get the n-th permutation
void get_permutation(int n, char * arr, int len, char * dst);
#endif
