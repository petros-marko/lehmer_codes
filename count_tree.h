#ifndef COUNT_TREE
#define COUNT_TREE
typedef struct node {
	int count;
	char * value;
	struct node * left, * right;
} count_tree_t;

//Build Count Tree based on an array
count_tree_t * build_tree(char * array, int len);
//Reset the counts of a tree
void reset_counts(count_tree_t * tree);
//Find the k-th item in the Count Tree
char find_kth_and_update(count_tree_t * tree, int idx);
//Free the memory allocated for a Count Tree
void free_tree(count_tree_t * tree);
#endif
