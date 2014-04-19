#include "TreeNode.h"
#include "TreeUtil.h"

Bool Key1LessThanKey2(void *key1, void *key2);

int main()
{
	int a[8] = {8, 4, 2, 12, 11, 13, 5, 6};
	TreeNode *node1;
	int find[2] = {6,7};
	BST *t1 = BSTCreateTree (Key1LessThanKey2, sizeof(int));
	Bool success = BSTInsert (t1,  &a[0], &a[0]);
	success = BSTInsert (t1, &a[1], (void *)"string1");
	success = BSTInsert (t1, &a[2], (void *)"string 2");
	success = BSTInsert (t1, &a[3], (void *)"string 3");
	success = BSTInsert (t1, &a[4], (void *)"string 3");
	success = BSTInsert (t1, &a[5], (void *)"string 3");
	success = BSTInsert (t1, &a[6], (void *)"string 3");
	success = BSTInsert (t1, &a[7], (void *)"string 3");
	TreeInorderTraversal (t1);
#if 0
	node1 = BSTFind(t1, &find[0]);
	if (node1) 
		printf("Found node1\n");
	else
		printf("NOt Found node1\n");
	
	node1 = BSTFind(t1, &find[1]);
	if (node1) 
		printf("Found node1\n");
	else
		printf("NOt Found node1\n");
#endif	
	//success = BSTInsert (t1, 4, 4);
	//success = BSTInsert (t1, 12, 8);

	printf("t1 must be pointing to its root %p", t1);

}

Bool Key1LessThanKey2 (void *key1, void *key2)
{
	int k1 = *(int *)key1;
	int k2 = *(int *)key2;
	if (k1 < k2)
		return TRUE;
	else if (k1 > k2)
		return FALSE;
	else
		return EQUAL;
}	
