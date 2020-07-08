// BinarySearchTree.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
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
		printf("\n(1)�}�� (2)�폜 (3)�T�� (4)�\�� (0)�I���F");
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
				x = ScanMember("�}��", MEMBER_NUMBER | MEMBER_NAME);
				root = Insert(root, &x);
				break;
			case DELETE :
				x = ScanMember("�폜", MEMBER_NUMBER);
				Delete(&root, &x);
				break;
			case SEARCH :
				x = ScanMember("�T��", MEMBER_NUMBER);
				if ((temp = Search(root, &x)) != NULL) 
					PrintLnMember(&temp->data);
				break;
			case PRINT :
				puts("[����ꗗ]");
				PrintTree(root);
				break;
		}
	} while (menu != FINISH);

	DeleteAllNode(root);

    return 0;
}

