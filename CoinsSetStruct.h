#pragma once
#include <SDKDDKVer.h>
//#include <stdio.h>
//#include <tchar.h>
#include<string>
#include <stdlib.h>
#include <iostream>

#ifndef _CoinsSetStruct_h_
#define _CoinsSetStruct_h_

struct CoinsSet
{
	int M = 0;		//����� ������� ����
	int N = 0;		//����� ������� �����
	int L = 0;		//����� ������� ����� ����� ����������
	int p = 0;		//���������� ����� ����� �����������
	int *A = 0;		//������ ������� ������������
	int *Coins = 0;	//������ � ����������� �����
	int O = 0;		//���������������� ������
	int v = 0;		//�������� ����� ��������������� �����, ��������� ��������� ������� �� ��������
	int Type = 0;	//0 - ��� �� ���������; 
					//1 - L >= N && A[0] == 0;/5 - L >= N	&& A[0] == 0 � ������ Coins ��������;
					//2 - L >= N && A[0] == 1;/2 - L >= N	&& A[0] == 1 � ������ Coins ��������;
					//3 - L < N	 && A[0] == 0;/3 - L < N	&& A[0] == 0 � ������ Coins ��������;
					//4 - L < N	 && A[0] == 1;/4 - L < N	&& A[0] == 1 � ������ Coins ��������;
};

CoinsSet *Create(int M, int N, int L);
CoinsSet *Create(int M, int N, int L, int S, int K);
int KillSet(CoinsSet *Set);
int FillA(CoinsSet *Set, int S, int K);
bool MNLCheck(CoinsSet *Set);
int GetSetType(CoinsSet *Set);
int FillCoins(CoinsSet *Set);
#endif // _CoinsSetStruct_h_
