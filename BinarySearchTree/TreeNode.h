#ifndef treenode_hh
#define treenode_hh

#include <stdlib.h>
#include <stddef.h>
#include "TreeUtil.h"

typedef Bool (*comp_func) (void *key1, void *key2);


//Declare a Tree Node
typedef struct data_t {
	void *val;
	void *key;
}Data;

typedef struct tree_node_t {
	struct tree_node_t *left;
	struct tree_node_t * right;
	Data	*data;
}TreeNode;

//Declare a LL Node 
typedef struct node_t {
	struct tree_node_t *next;
	Data *data;
	
}Node;

//Tree root, and function definitions on the Tree
typedef struct binary_search_tree_t {
	TreeNode *root;
	size_t keySize;
	Bool (*comp_func) (void *key1, void * key2);
//	bool (*comparator) (void *key1, void *key2);
}BST;

Bool BSTInsert (BST *root, void *key, void *val);
BST *BSTCreateTree (comp_func comp, size_t keySize);
TreeNode *BSTFind (BST *root, void *key, int size);
Bool BSTDelete (BST *root, void *key, int size);
void BSTraverse (BST *root, int traverseType);

Bool CompareDataSizeAndCheckForKey(BST *tree, void *key); 
TreeNode *CreateTreeNode (Data *data); 
Data *CreateData(void *key, void *val);
void BSTInsertRecurse(TreeNode *root, TreeNode *node);
TreeNode *BSTFindRecurse(TreeNode *root, void *key);
#endif
