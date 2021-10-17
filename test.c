#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "lehmer.h"

int main(){

	char * arr = strdup("ABCD");
	int len = strlen(arr);
	count_tree_t * tree = build_tree(arr, len);
	char dst[4];
	for(int i = 0; i < 24; i++){
		get_permutation_with_tree(i, tree, dst);
		for(int j = 0; j < 4; j++){
			printf("%c", dst[j]);
		}
		printf("\n");
	}

	free_tree(tree);
	return 0;
}
