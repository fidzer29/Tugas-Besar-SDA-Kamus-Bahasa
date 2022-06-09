#include "KMSTree.h"

void createTree(TreeNode *p){
	*p = (TreeNode)malloc(sizeof(treeElmtList));
	if(*p != NULL){
	}
	else
		printf("Gagal Alokasi\n");
}

void isiNode(TreeNode *p,infotype inputUserIndo,infotype inputUserIng){
	if (*p == NULL)
		printf("Node belum dialokasi\n");
	else{
		strcpy((*p)->indonesia,inputUserIndo);
		strcpy((*p)->inggris,inputUserIng);
		(*p)->left = NULL;
		(*p)->right = NULL;
	}
		
}

TreeNode InsertNode(TreeNode p, infotype inputUserIndo, infotype inputUserIng,bool bhs){
	if (bhs){
		if (p == NULL){
			createTree(&p);
			isiNode(&p,inputUserIndo,inputUserIng);
		}
		// input > node maka insert kanan
		else if (strcmp(inputUserIndo,p->indonesia) == 1){
			p->right =  InsertNode(p->right,inputUserIndo,inputUserIng,bhs);
			// cek balancing factor
			if(getBalanceFactor(p) < -1)
				if (strcmp(inputUserIndo,p->right->indonesia) == 1)
					//rotasi kiri
					p = RR(p);
				else
					//rotasi ganda
					p = RL(p);
				
		}
		// input < node maka insert kiri
		else if (strcmp(inputUserIndo,p->indonesia) == -1){
			p->left =  InsertNode(p->left,inputUserIndo,inputUserIng,bhs);
			//cek balancing
			if(getBalanceFactor(p) > 1)
				if (strcmp(inputUserIndo,p->left->indonesia) == -1)
					//rotasi kanan
					p = LL(p);
				else
					p = LR(p);
				
		}
	p->height = getHeight(p);
	return(p);
	}
	else {
		if (p == NULL){
			createTree(&p);
			isiNode(&p,inputUserIndo,inputUserIng);
		}
		// input > node maka insert kanan
		else if (strcmp(inputUserIng,p->inggris) == 1){
			p->right =  InsertNode(p->right,inputUserIndo,inputUserIng,bhs);
			// cek balancing factor
			if(getBalanceFactor(p) < -1)
				if (strcmp(inputUserIng,p->inggris) == 1)
					//rotasi kiri
					p = RR(p);
				else
					//rotasi ganda
					p = RL(p);
		}
		// input < node maka insert kiri
		else if (strcmp(inputUserIng,p->inggris) == -1){
			p->left =  InsertNode(p->left,inputUserIndo,inputUserIng,bhs);
			//cek balancing
			if(getBalanceFactor(p) > 1)
				if (strcmp(inputUserIng,p->inggris) == -1)
					//rotasi kanan
					p = LL(p);
				else
					//rotasi ganda
					p = LR(p);
		}
	p->height = getHeight(p);
	return(p);
	}
}

int getHeight(TreeNode p){
	int leftHeight,rightHeight;
	if(p==NULL)
		return(0);
	if(p->left==NULL)
		leftHeight=0;
	else
		leftHeight=1+p->left->height;
	if(p->right==NULL)
		rightHeight=0;
	else
		rightHeight=1+p->right->height;
	if(leftHeight>rightHeight) return(leftHeight);
	return(rightHeight);
}

int getBalanceFactor(TreeNode p){
	int leftHeight,rightHeight;
	if(p==NULL)
		return(0);
	if(p->left==NULL)
		leftHeight=0;
	else
		leftHeight=1+p->left->height;
	if(p->right==NULL)
		rightHeight=0;
	else
		rightHeight=1+p->right->height;
	
	return (leftHeight - rightHeight);
}

TreeNode RR (TreeNode p){
	p = rotateLeft(p);
	return(p);
}

TreeNode LL (TreeNode p){
	p = rotateRight(p);
	return(p);
}

TreeNode LR (TreeNode p){
	p->left = rotateLeft(p->left);
	p = rotateRight(p);
	return(p);
}

TreeNode RL (TreeNode p){
	p->right = rotateRight(p->right);
	p = rotateLeft(p);
	return(p);
}

TreeNode rotateLeft(TreeNode x){
	TreeNode y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->height=getHeight(x);
	y->height=getHeight(y);
	return(y);
}

TreeNode rotateRight(TreeNode x){
	TreeNode y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->height=getHeight(x);
	y->height=getHeight(y);
	return(y);
}

void PreOrder (TreeNode p, bool bhs){
	if (p != NULL) {
		if (bhs == true) {
			printf("\t\t\t        %s = % s \n", p->indonesia, p->inggris,p->height);
		}
		else {
			printf("\t\t\t        %s = % s \n", p->inggris, p->indonesia,p->height);
		}
		PreOrder(p->left, bhs);
		PreOrder(p->right, bhs);
	}
}

TreeNode Dealokasi(TreeNode p){
	p = NULL;
	free(p);
	
	return p;
}



