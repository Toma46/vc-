
#include"stdafx.h"
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

static BinNode *MakeBinNode(void) {
	return (BinNode*)calloc(1, sizeof(BinNode));

}
static void SetBinNode(BinNode *n, const Member *x, const BinNode *left, const BinNode *right) {
	n->data = *x;
	n->left = (BinNode*)left;
	n->right =(BinNode*) right;
}

BinNode *Search(BinNode *p, const Member *x) {
	int cond;

	if (p == NULL) 
		return NULL;
	else if ((cond = MemberNumberCmp(x, &p->data)) == 0) 
		return p;
	else if (cond < 0) 
		Search(p->left, x);
	else 
		Search(p->right, x);
}

BinNode *Insert(BinNode *p, const Member *x) {
	int cond;

	if (p == NULL) {
		p = MakeBinNode();
		SetBinNode(p, x, NULL, NULL);
	}else if ((cond = MemberNumberCmp(x, &p->data)) == 0)
		printf("[ƒGƒ‰[v%d‚Í“o˜^Ï‚Ý‚Å‚·B\n", x->number);
	else if (cond < 0) 
		p->left = Insert(p->left, x);
	else 
		p->right = Insert(p->right, x);

	return p;
}

int Delete(BinNode **root, const Member *x) {
	BinNode *next;
	BinNode *temp;
	BinNode **left;
	BinNode **p = root;

	while (1) {
		int cond;
		if (*p == NULL) {
			printf("[ƒGƒ‰[v%d‚Í“o˜^‚³‚ê‚Ä‚¢‚Ü‚¹‚ñB\n", x->number);
			return -1;
		}else if ((cond = MemberNumberCmp(x, &(*p)->data)) == 0) 
			break;
		else if (cond < 0) 
			p = &((*p)->left);
		else 
			p = &((*p)->left);
	}
	if ((*p)->left == NULL) 
		next = (*p)->right;
	else {
		left = &((*p)->left);
		while ((*left)->right != NULL) 
			left = &(*left)->right;
		next = *left;
		*left = (*left)->left;
		next->left = (*p)->left;
		next->right = (*p)->right;
	}
	temp = *p;
	*p = (BinNode*)next;
	free(temp);

	return 0;
}

void PrintTree(const BinNode *p) {
	if (p != NULL) {
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

void  DeleteAllNode(BinNode *p) {
	if (p != NULL) {
		DeleteAllNode(p->left);
		DeleteAllNode(p->right);
		free(p);
	}
}