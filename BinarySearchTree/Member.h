#pragma once

#ifndef ___Member
#define ___Member

/*	����f�[�^	*/
typedef struct {
	int number;		//�ԍ�
	char name[20];	//����
} Member;

#define MEMBER_NUMBER	1
#define MEMBER_NAME		2

//����̎������r
int MemberNumberCmp(const Member *x, const Member *y);

//����f�[�^�̕\��
void PrintLnMember(const Member *x);

//����f�[�^�̓ǂݍ���
Member ScanMember(const char *message, int sw);


#endif