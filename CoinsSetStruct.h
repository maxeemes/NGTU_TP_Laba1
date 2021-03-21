#pragma once
#include <SDKDDKVer.h>
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
					//2 - L >= N && A[0] == 1;/6 - L >= N	&& A[0] == 1 � ������ Coins ��������;
					//3 - L < N	 && A[0] == 0;/7 - L < N	&& A[0] == 0 � ������ Coins ��������;
					//4 - L < N	 && A[0] == 1;/8 - L < N	&& A[0] == 1 � ������ Coins ��������;
};

CoinsSet *Create(int M, int N, int L);//������� �������� ��������� ������ ����� � ��������� ����������
CoinsSet *Create(int M, int N, int L, int S, int K);//������� �������� ������ ��������� ������ �����
int KillSet(CoinsSet *Set);//������� �������� ���������
int FillA(CoinsSet *Set, int S, int K);//������� �� �������� ������� ������ �����, ������� ������������
bool MNLCheck(CoinsSet *Set);//������� �������� ������������ �������� ���������� M, N, L � ��������� �����
int GetSetType(CoinsSet *Set);//������� ��������� ���� ������ ����� ��� ����������� �������
int FillCoins(CoinsSet *Set);//������� ������� ������ �����
int PrintIntArray(int *Arr, int Len);//������� ������ �������� �������������� ������� � �������
int *CopyIntArray(int *Arr, int Len);//������� ����������� �������������� �������
int VisualValidateCoins(CoinsSet *Set, int S, int K);//������� ���������� �������� ������ �����
#endif // _CoinsSetStruct_h_
  