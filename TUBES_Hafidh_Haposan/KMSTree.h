#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

typedef char infotype[25];

typedef struct treeElmtList *TreeNode;
typedef struct treeElmtList {
	infotype indonesia,inggris;
	TreeNode left,right;
	int height;
} TreeElmtList;

void createTree(TreeNode p);

void isiNode(TreeNode p, infotype inputUserIndo, infotype inputUserIng);

TreeNode InsertNode(TreeNode p, infotype inputUserIndo, infotype inputUserIng,bool bhs);

int getHeight(TreeNode p);

int getBalanceFactor(TreeNode p);

TreeNode RR (TreeNode p);

TreeNode LL (TreeNode p);

TreeNode LR (TreeNode p);

TreeNode RL (TreeNode p);

TreeNode rotateLeft(TreeNode x);

TreeNode rotateRight(TreeNode x);

void PreOrder (TreeNode p, bool bhs);

TreeNode Dealokasi(TreeNode p);
