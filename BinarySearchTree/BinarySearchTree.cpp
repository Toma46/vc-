// BinarySearchTree.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Member.h"
#include "BinTree.h"


typedef enum {
	FINISH, INSERT, DELETE, SEARCH, PRINT
}Menu;

Menu SelectMenu(void) {
	int c;

	do {
		printf("\n(1)挿入 (2)削除 (3)探索 (4)表示 (0)終了：");
		scanf_s("%d", &c);
	} while (c < FINISH || c > PRINT);
	return (Menu)c;
}

int main()
{
	Menu menu;
	BinNode *root = NULL;

	do {
		Member x;
		BinNode *temp;
		temp = 0;


		switch (menu = SelectMenu()) {
			case INSERT :
				x = ScanMember("挿入", MEMBER_NUMBER | MEMBER_NAME);
				root = Insert(root, &x);
				break;
			case DELETE :
				x = ScanMember("削除", MEMBER_NUMBER);
				Delete(&root, &x);
				break;
			case SEARCH :
				x = ScanMember("探索", MEMBER_NUMBER);
				if ((temp = Search(root, &x)) != NULL) 
					PrintLnMember(&temp->data);
				break;
			case PRINT :
				puts("[会員一覧]");
				PrintTree(root);
				break;
		}
	} while (menu != FINISH);

	DeleteAllNode(root);

    return 0;
}

