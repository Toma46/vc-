
#include "stdafx.h"
#include "Member.h"

//����̎������r
int MemberNumberCmp(const Member *x, const Member *y) {
	return x->number <  y->number ? -1 : x->number > y->number ? 1 : 0;
}

//����f�[�^�̕\��
void PrintLnMember(const Member *x) {
	printf("%d %s\n", x->number, x->name);
}

//����̎������r
Member ScanMember(const char *message, int sw) {
	Member temp;

	printf("%s����f�[�^����͂��Ă��������B\n", message);  //�}���A�폜�A�T���A�\��

	if (sw & MEMBER_NUMBER) {
		printf("�ԍ��F");
		scanf_s("%d", &temp.number);
	}
	if (sw & MEMBER_NAME) {
		printf("�����F");
		scanf_s("%s", temp.name);
	}
	return temp;
}
