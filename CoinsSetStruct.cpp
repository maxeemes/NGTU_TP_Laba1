#include "CoinsSetStruct.h"

using namespace std;
CoinsSet * Create(int M, int N, int L)//функция создания структуры набора монет с основными значениями
{
	CoinsSet *Set = new CoinsSet();
	Set->M = M;
	Set->N = N;
	Set->L = L;
	int SumNM = M + N;
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

CoinsSet * Create(int M, int N, int L, int S, int K)//функция создания полной структуры набора монет
{
	CoinsSet * Set = Create(M, N, L);
	if (Set != 0)
	{
		if (FillA(Set, S, K) == 0 && FillCoins(Set) > 4)
		{
			return Set;
		}
		else
		{
			KillSet(Set);
		}
	}
	return 0;
}

int KillSet(CoinsSet * Set)//функция удаления структуры
{
	delete Set->A;
	delete Set->Coins;
	delete Set;
	return 0;
}

int FillA(CoinsSet * Set, int S, int K)//функция за полнения массива позций монет, которые перевернутся
{
	if (MNLCheck(Set) && S >= 0 && K >= 0)
	{
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

bool MNLCheck(CoinsSet * Set)//функция проверки корректности значений переменных M, N, L в структуре монет
{
	if (Set->M >= 0 && Set->N > 0 && Set->L >= 0 && ((Set->M + Set->N) >= Set->L))
	{
		return true;
	}
	return false;
}

int GetSetType(CoinsSet * Set)//функция получения типа набора монет для дальнейшего расчета
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
				Set->Type = 1;
				return 1;
			}
			else if (Set->A[0] == 1 && Set->v > 0)
			{
				Set->Type = 2;
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
				Set->Type = 3;
				return 3;
			}
			else if (Set->A[0] == 1 && (Set->v + Set->O) > 0)
			{
				Set->Type = 4;
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
	Set->Type = 0;
	cout << "Ошибка получения типа!!! Преобразование невозможно!!!";
	return -1;
}

int FillCoins(CoinsSet * Set)//функция расчета набора монет
{
	if (Set->Type <= 0 && GetSetType(Set) <= 0)
	{
		return -1;//ошибка определения типа
	}

	int M = Set->M, N = Set->N, SumNM = Set->M + Set->N, O = Set->O, v0 = Set->v, v1 = Set->v;
	bool IsOInN = Set->Type >= 3;
	Set->Coins[0] = 1;
	N--;
	if (Set->Type % 2 == 0)
	{
		if (v1 == 0 && IsOInN)
		{
			O--;
		}
		else
		{
			v1--;
		}
	}

	for (int i = 1;  i < SumNM;  i++)
	{
		if (Set->A[i] == 1)
		{
			if (O > 0)
			{
				O--;
				if (IsOInN)
				{
					Set->Coins[i] = 1;
					N--;
				}
				else
				{
					M--;
				}
			}
			else if (v0 > 0)
			{
				v0--;
				M--;
			}
			else if (v1 > 0)
			{
				Set->Coins[i] = 1;
				v1--;
				N--;
			}
			else
			{
				cout << "Ошибка преобразования набора монет! A[i] == 1";
				return Set->Type*-1;
			}
		}
		else if (Set->A[i] == 0 && IsOInN)
		{
			if ((M - v0) > 0)
			{
				M--;
			}
			else if ((N - (O + v1)) > 0)
			{
				Set->Coins[i] = 1;
				N--;
			}
			else
			{
				cout << "Ошибка преобразования набора монет! A[i] == 0";
				return Set->Type*-1;
			}
		}
		else if (Set->A[i] == 0 && !IsOInN)
		{
			if ((M - (O + v0)) > 0)
			{
				M--;
			}
			else if ((N - v1) > 0)
			{
				Set->Coins[i] = 1;
				N--;
			}
			else
			{
				cout << "Ошибка преобразования набора монет! A[i] == 0";
				return Set->Type*-1;
			}
		}
		else
		{
			cout << "Ошибка некорректное значение в массиве A!!!";
			return Set->Type*-1;
		}
	}

	if (M == 0 && N == 0 && O == 0 && v0 == 0 && v1 == 0)
	{
		cout << "Массив порядка монет успешно заполнен!!!";
		Set->Type += 4;
		return Set->Type;
	}
	cout << "Ошибка преобразования набора монет! Некорректные итоговые значения!";
	return Set->Type*-1;
}

int PrintIntArray(int * Arr, int Len)//функция вывода значений целочисленного массива в консоль
{
	for (int i = 0; i < Len; i++)
	{
		cout << Arr[i];
	}
	return 0;
}

int * CopyIntArray(int * Arr, int Len)//функция копирования целочисленного массива
{
	int * NewArr = new int[Len];
	for (int i = 0; i < Len; i++)
	{
		NewArr[i] = Arr[i];
	}
	return NewArr;
}

int VisualValidateCoins(CoinsSet * Set, int S, int K)//функция визуальной проверки набора монет
{
	int Len = Set->M + Set->N;
	int * TmpCoins = CopyIntArray(Set->Coins, Len);
	int L = Set->N;
	cout << "Исходный набор монет:" << endl;
	PrintIntArray(TmpCoins, Len);
	cout << endl << "Набор монет по шагам" << endl;
	for (int i = 0, pos = 0; i < K; i++, pos += S)
	{
		if (pos >= Len)		//переход в начало массива при достижении конца
		{
			pos -= Len;
		}
		L += 1 - TmpCoins[pos] * 2;	//подсчет суммы монет гербами вверх
		TmpCoins[pos] = 1 - TmpCoins[pos];	//замена 1 на 0, 0 на 1
		cout << i + 1 << ")\t";
		PrintIntArray(TmpCoins, Len);
		cout << endl;
	}
	cout << "Монет гербами вверх после последнего шага: " << L;

	delete TmpCoins;
	return L;
}
