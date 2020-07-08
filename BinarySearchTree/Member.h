#pragma once

#ifndef ___Member
#define ___Member

/*	会員データ	*/
typedef struct {
	int number;		//番号
	char name[20];	//氏名
} Member;

#define MEMBER_NUMBER	1
#define MEMBER_NAME		2

//会員の氏名を比較
int MemberNumberCmp(const Member *x, const Member *y);

//会員データの表示
void PrintLnMember(const Member *x);

//会員データの読み込み
Member ScanMember(const char *message, int sw);


#endif