#include <stdlib.h>
#include "count_tree.h"

count_tree_t * make_node(int count, char value, count_tree_t * left, count_tree_t * right){
	count_tree_t * res = malloc(sizeof(count_tree_t));
	res->count = count;
	if(value){
		res->value = malloc(sizeof(char));
		*(res->value) =  value;
	}
	else
		res->value = NULL;
	res->left = left;
	res->right = right;
	return res;
}

count_tree_t * build_tree(char * array, int len){
	if(len == 0)
		return NULL;
	if(len == 1){
		return make_node(1, array[0], NULL, NULL);
	}
	count_tree_t * left = build_tree(array, len / 2);
	count_tree_t * right = build_tree(array + (len / 2), len - (len / 2));
	return make_node((left? left->count:0) + (right? right->count:0), 0, left, right);
}

void reset_counts(count_tree_t * tree){
	if(!tree)
		return;
	if(!tree->left && !tree->right){
		tree->count = 1;
		return;
	}
	reset_counts(tree->left);
	reset_counts(tree->right);
	tree->count = (tree->left? tree->left->count:0) + (tree->right? tree->right->count:0);
}

char find_kth_and_update(count_tree_t * tree, int idx){
	if(!tree->count && !tree->value) return 0;
	tree->count = tree->count - 1;
	if(tree->value){
		return *(tree->value);
	}
	int left_count = tree->left? tree->left->count:0;
	int right_count = tree->right? tree->right->count:0;
	if(left_count > idx){
		return find_kth_and_update(tree->left, idx);		
	}
	return find_kth_and_update(tree->right, idx - left_count);
}

void free_tree(count_tree_t * tree){
	if(!tree)
		return;
	free_tree(tree->left);
	free_tree(tree->right);
	if(tree->value)
		free(tree->value);
	free(tree);
}
