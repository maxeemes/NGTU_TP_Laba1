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
	int M = 0;		//монет гербами вниз
	int N = 0;		//монет гербами вверх
	int L = 0;		//монет гербами вверх после выполнения
	int p = 0;		//количество монет будет перевернуто
	int *A = 0;		//монеты которые перевернутся
	int *Coins = 0;	//массив с положениями монет
	int O = 0;		//переворачиваемые монеты
	int v = 0;		//половина суммы переворачивемых монет, отношение положений которых не меняется
	int Type = 0;	//0 - тип не определен; 
					//1 - L >= N && A[0] == 0;/5 - L >= N	&& A[0] == 0 и массив Coins заполнен;
					//2 - L >= N && A[0] == 1;/6 - L >= N	&& A[0] == 1 и массив Coins заполнен;
					//3 - L < N	 && A[0] == 0;/7 - L < N	&& A[0] == 0 и массив Coins заполнен;
					//4 - L < N	 && A[0] == 1;/8 - L < N	&& A[0] == 1 и массив Coins заполнен;
};

CoinsSet *Create(int M, int N, int L);
CoinsSet *Create(int M, int N, int L, int S, int K);
int KillSet(CoinsSet *Set);
int FillA(CoinsSet *Set, int S, int K);
bool MNLCheck(CoinsSet *Set);
int GetSetType(CoinsSet *Set);
int FillCoins(CoinsSet *Set);
int PrintIntArray(int *Arr, int Len);
int *CopyIntArray(int *Arr, int Len);
int VisualValidateCoins(CoinsSet *Set, int S, int K);
#endif // _CoinsSetStruct_h_
  