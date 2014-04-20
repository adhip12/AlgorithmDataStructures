#include "TreeNode.h"
#include "TreeUtil.h"
#include <string.h>

Data *CreateData (void *key, void *val)
{
	size_t keySize = sizeof(key);
	size_t valSize = sizeof(val);
	Data *data = (Data *) malloc (keySize + valSize);
	if (data == NULL) {
		return NULL;
	}
	memset (data, 0, keySize + valSize);
	data->key = (int *) key;
	data->val = (int *) val;
	return data;
}


TreeNode *CreateTreeNode (Data *data)
{
	TreeNode *node = NULL;
	if (data != NULL) {
		node = (TreeNode *) malloc (sizeof(TreeNode));
		node->left = NULL;
		node->right = NULL;
		node->data = data;
	}
	return node;
}

void BSTInsertRecurse(TreeNode *root, TreeNode *node, comp_func compare)
{
	if (root != NULL) {  
		/* Compare the Root_key and Node_key */
		if (compare (root->data->key, node->data->key) == FALSE) {
			if (root->left == NULL) {
				root->left = node;
			} else {
				BSTInsertRecurse (root->left, node, compare);
			}
		} else if ((compare (root->data->key, node->data->key) == TRUE) ||
			   (compare (root->data->key, node->data->key) == EQUAL)) {
			if (root->right == NULL) {
				root->right = node;
			} else {
				BSTInsertRecurse (root->right, node, compare);
			}
		}  
	}
}

TreeNode *BSTFindElement (TreeNode *root, void *key, comp_func compare)
{
	while (root != NULL) {  
		if (compare (root->data->key, key) == FALSE) {
			root = root->left;
		} else if (compare(root->data->key, key) == TRUE) {
			root = root->right;
		} else {
			return root;	
		}
	}
	return NULL;
}

void InorderTraversal (TreeNode *root)
{
	if (root != NULL) {
		InorderTraversal(root->left);
		printf ("%d ", *(int *)root->data->key);
		InorderTraversal(root->right);
	}
}

Bool CompareDataSizeAndCheckForKey (BST *tree, void *key)
{
#if 0
	size_t keySize = sizeof(key);
	if (tree->keySize != keySize) {
		return FALSE;
	}
#endif
	return TRUE; 

}
