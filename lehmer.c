#include "lehmer.h"
#include "count_tree.h"

void get_lehmer_code(int n, int * dst, int len){
	for(int i = len - 1; i >= 0; i--){
		dst[i] = n % (len - i);
		n /= (len - i);
	}
}

void get_permutation_from_lehmer_with_tree(int * code, int len, count_tree_t * tree, char * dst){
	for(int i = 0; i < len; i++){
		int current = code[i];
		dst[i] = find_kth_and_update(tree, current);
	}
	reset_counts(tree);
}

void get_permutation_from_lehmer(int * code, char * arr, int len, char * dst){
	count_tree_t * tree = build_tree(arr, len);
	get_permutation_from_lehmer_with_tree(code, len, tree, dst);
	free_tree(tree);
}

void get_permutation(int n, char * arr, int len, char * dst){
	int code[len];
	get_lehmer_code(n, code, len);
	get_permutation_from_lehmer(code, arr, len, dst);
}

void get_permutation_with_tree(int n, count_tree_t * tree, char * dst){
	int len = tree->count;
	int code[len];
	get_lehmer_code(n, code, len);
	get_permutation_from_lehmer_with_tree(code, len, tree, dst);
	reset_counts(tree);
}
