#ifndef ___BinTree
#define ___BinTree

#include "Member.h"

// �m�[�h 
typedef struct __bnode {
	Member data;
	struct __bnode *left;	//���̎q�ւ̃|�C���^
	struct __bnode *right;	//�E�̎q�ւ̃|�C���^
} BinNode;

//�v�f��T�����郁�\�b�h
BinNode *Search(BinNode *p, const Member *x);

//�v�f��}�����郁�\�b�h
BinNode *Insert(BinNode *p, const Member *x);

//�v�f���폜���郁�\�b�h
int Delete(BinNode **root, const Member *x);

//�S�m�[�h�\��
void PrintTree(const BinNode *p);

//�S�m�[�h�폜
void DeleteAllNode(BinNode *p);


#endif