#ifndef ___BinTree
#define ___BinTree

#include "Member.h"

// ノード 
typedef struct __bnode {
	Member data;
	struct __bnode *left;	//左の子へのポインタ
	struct __bnode *right;	//右の子へのポインタ
} BinNode;

//要素を探索するメソッド
BinNode *Search(BinNode *p, const Member *x);

//要素を挿入するメソッド
BinNode *Insert(BinNode *p, const Member *x);

//要素を削除するメソッド
int Delete(BinNode **root, const Member *x);

//全ノード表示
void PrintTree(const BinNode *p);

//全ノード削除
void DeleteAllNode(BinNode *p);


#endif