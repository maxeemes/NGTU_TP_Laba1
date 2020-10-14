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
	int SetType = 0;	//0 - тип не определен; 
						//1 - L >= N && A[0] == 0;
						//2 - L >= N && A[0] == 1;
						//3 - L < N	 && A[0] == 0;
						//4 - L < N	 && A[0] == 1;
};

CoinsSet *Create(int M, int N, int L);
CoinsSet *Create(int M, int N, int L, int S, int K);
int KillSet(CoinsSet *Set);
int FillA(CoinsSet *Set, int S, int K);
bool MNLCheck(CoinsSet *Set);
int GetSetType(CoinsSet *Set);
int FillCoins(CoinsSet *Set);
#endif // _CoinsSetStruct_h_
