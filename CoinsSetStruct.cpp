#include "CoinsSetStruct.h"

using namespace std;
CoinsSet * Create(int M, int N, int L)
{
	CoinsSet *Set = new CoinsSet();
	Set->M = M;
	Set->N = N;
	Set->L = L;
	int SumNM = N + M;
	Set->A = new int[SumNM] {0};
	Set->Coins = new int[SumNM] {0};

	if (MNLCheck(Set))
	{
		return Set;
	}
	else
	{
		KillSet(Set);
		cout << "Ошибка создания структуры CoinsSet, неверное значение M, N, L!!!\n";
	}
	return 0;
}

CoinsSet * Create(int M, int N, int L, int S, int K)
{
	return nullptr;
}

int KillSet(CoinsSet * Set)
{
	delete Set->A;
	delete Set->Coins;
	delete Set;
	return 0;
}

int FillA(CoinsSet * Set, int S, int K)
{
	if (MNLCheck(Set) && S >= 0 && K >= 0)
	{
		delete Set->A;
		int SumNM = Set->N + Set->M;//количество монет

		for (int i = 0, pos = 0; i < K; i++, pos += S)
		{
			if (pos >= SumNM)		//переход в начало массива при достижении конца
			{
				pos -= SumNM;
			}
			Set->p += 1 - Set->A[pos] * 2;	//подсчет суммы переворачиваемых монет
			Set->A[pos] = 1 - Set->A[pos];	//замена 1 на 0, 0 на 1
		}

		return 0;
	}
	else
	{
		cout << "Ошибка создания структуры CoinsSet, неверное значение S, K!!!\n";
	}
	return -1;
}

bool MNLCheck(CoinsSet * Set)
{
	if (Set->M >= 0 && Set->N >= 0 && Set->L >= 0 && Set->M + Set->N >= Set->L)
	{
		return true;
	}
	return false;
}

int GetSetType(CoinsSet * Set)
{
	if (Set->L >= Set->N)
	{
		Set->O = Set->L - Set->N;	//переворачиваемые монеты гербами вниз
		int Q = Set->p - Set->O;	//переворачиваемые монеты, где 1 половина гербами вниз, а другая вверх
		Set->v = Q / 2;				//половина переворчиваемых монет
		if (Q >= 0 && ((Set->v * 2) == Q) && Set->v <= Set->N && ((Set->v + Set->O) <= Set->M))	//проверка возможности преобразования
		{
			if (Set->A[0] == 0 && Set->N > Set->v)
			{
				Set->SetType = 1;
				return 1;
			}
			else if (Set->A[0] == 1 && Set->v > 0)
			{
				Set->SetType = 2;
				return 2;
			}
		}
	}
	else if (Set->L < Set->N)
	{
		Set->O = Set->N - Set->L;	//переворачиваемые монеты гербами вверх
		int Q = Set->p - Set->O;	//переворачиваемые монеты, где 1 половина гербом вниз, а другая вверх
		Set->v = Q / 2;				//половина переворчиваемых монет
		if (Q >= 0 && ((Set->v * 2) == Q) && Set->v <= Set->M && ((Set->v + Set->O) <= Set->N))	//проверка возможности преобразования
		{
			if (Set->A[0] == 0 && Set->N > (Set->v + Set->O))
			{
				Set->SetType = 3;
				return 3;
			}
			else if (Set->A[0] == 1 && (Set->v + Set->O) > 0)
			{
				Set->SetType = 4;
				return 4;
			}
		}
		else
		{
			cout << "Ошибка получения типа!!! Преобразование невозможно!!!";
		}
	}

	Set->O = 0;
	Set->v = 0;
	Set->SetType = 0;
	cout << "Ошибка получения типа!!! Преобразование невозможно!!!";
	return -1;
}



