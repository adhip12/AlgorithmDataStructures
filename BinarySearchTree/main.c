#include "TreeNode.h"
#include "TreeUtil.h"
#include <stdio.h>

Bool Key1GreaterThanKey2(void *key1, void *key2);

int main()
{
	int a[4] = {8, 4, 2, 12};

	BST *t1 = BSTCreateTree (Key1GreaterThanKey2, sizeof(int));
	Bool success = BSTInsert (t1,  &a[0], &a[0]);
	success = BSTInsert (t1, &a[1], (void *)"string1");
	success = BSTInsert (t1, &a[2], (void *)"string 2");
	//success = BSTInsert (t1, 4, 4);
	//success = BSTInsert (t1, 12, 8);

	printf("t1 must be pointing to its root %p", t1);

}

Bool Key1GreaterThanKey2 (void *key1, void *key2)
{
	int k1 = *(int *)key1;
	int k2 = *(int *)key2;
	if (key1 < key2)
		return FALSE;
	else
		return TRUE;
}
