#include "TreeNode.h"

BST *BSTCreateTree (comp_func compare, size_t keySize)
{
	BST *tree = (BST *) malloc (sizeof (BST));
	if (tree == NULL) {
		return NULL;
	}
	tree->root = NULL;
	tree->comp_func = compare;
	tree->keySize = keySize;
	return tree;
}

Bool BSTInsert(BST *tree, void *key, void *val)
{
	TreeNode *node = NULL;
	Data 	 *data = NULL;
	Bool	success = FALSE;

	if (CompareDataSizeAndCheckForKey(tree, key) == FALSE) {
		return INVALID_DATA_SIZE;
	}

	// Create a Node
	data = CreateData (key, val);
	if (data == NULL) {
		return FALSE;
	} else {
		node = CreateTreeNode (data);
		if (node == NULL) {
			return FALSE;
		}
	}

	//If Root is NULL, we don't have an element. So, the root points to the first Node
	if (tree->root == NULL) {
		tree->root = node;
		return TRUE;
	} 

	// Recurse through Left and Right nodes to insert element.
	BSTInsertRecurse (tree->root, node, tree->comp_func);

	return TRUE;
}

TreeNode *BSTFind (BST *tree, void *key)
{
	if (tree) {
		if (tree->root == NULL) {
			return NULL;
		}
	} else {
		return NULL;
	}
	if (CompareDataSizeAndCheckForKey(tree, key) == FALSE) {
		return NULL;
	}
	return BSTFindElement(tree->root, key, tree->comp_func);

}

void TreeInorderTraversal (BST *tree)
{
	InorderTraversal (tree->root);
}


Bool BSTDelete(BST *root, void *key, int size)
{
	return TRUE;

}
