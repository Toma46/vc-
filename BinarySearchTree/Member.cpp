
#include "stdafx.h"
#include "Member.h"

//会員の氏名を比較
int MemberNumberCmp(const Member *x, const Member *y) {
	return x->number <  y->number ? -1 : x->number > y->number ? 1 : 0;
}

//会員データの表示
void PrintLnMember(const Member *x) {
	printf("%d %s\n", x->number, x->name);
}

//会員の氏名を比較
Member ScanMember(const char *message, int sw) {
	Member temp;

	printf("%sするデータを入力してください。\n", message);  //挿入、削除、探索、表示

	if (sw & MEMBER_NUMBER) {
		printf("番号：");
		scanf_s("%d", &temp.number);
	}
	if (sw & MEMBER_NAME) {
		printf("氏名：");
		scanf_s("%s", temp.name);
	}
	return temp;
}
