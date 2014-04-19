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

void BSTInsertRecurse(TreeNode *root, TreeNode *node)
{
	if (root != NULL) {  
		if (node->data->key < root->data->key) {
			if (root->left == NULL) {
				root->left = node;
			} else {
				BSTInsertRecurse (root->left, node);
			}
		} else {
			if (root->right == NULL) {
				root->right = node;
			} else {
				BSTInsertRecurse (root->right, node);
			}
		}
	}
}

TreeNode *BSTFindRecurse (TreeNode *root, void *key)
{
	if (root != NULL) {  
		if (key < root->data->key) {
			BSTFindRecurse (root->left, key);
			return root;
		} else {
			BSTFindRecurse (root->right, key);
			return root;
		}
	}
	return NULL;
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
