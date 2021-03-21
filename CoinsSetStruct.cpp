#include "CoinsSetStruct.h"

using namespace std;
CoinsSet * Create(int M, int N, int L)//������� �������� ��������� ������ ����� � ��������� ����������
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
		cout << "������ �������� ��������� CoinsSet, �������� �������� M, N, L!!!\n";
	}
	return 0;
}

CoinsSet * Create(int M, int N, int L, int S, int K)//������� �������� ������ ��������� ������ �����
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

int KillSet(CoinsSet * Set)//������� �������� ���������
{
	delete Set->A;
	delete Set->Coins;
	delete Set;
	return 0;
}

int FillA(CoinsSet * Set, int S, int K)//������� �� �������� ������� ������ �����, ������� ������������
{
	if (MNLCheck(Set) && S >= 0 && K >= 0)
	{
		int SumNM = Set->N + Set->M;//���������� �����

		for (int i = 0, pos = 0; i < K; i++, pos += S)
		{
			if (pos >= SumNM)		//������� � ������ ������� ��� ���������� �����
			{
				pos -= SumNM;
			}
			Set->p += 1 - Set->A[pos] * 2;	//������� ����� ���������������� �����
			Set->A[pos] = 1 - Set->A[pos];	//������ 1 �� 0, 0 �� 1
		}

		return 0;
	}
	else
	{
		cout << "������ �������� ��������� CoinsSet, �������� �������� S, K!!!\n";
	}
	return -1;
}

bool MNLCheck(CoinsSet * Set)//������� �������� ������������ �������� ���������� M, N, L � ��������� �����
{
	if (Set->M >= 0 && Set->N > 0 && Set->L >= 0 && ((Set->M + Set->N) >= Set->L))
	{
		return true;
	}
	return false;
}

int GetSetType(CoinsSet * Set)//������� ��������� ���� ������ ����� ��� ����������� �������
{
	if (Set->L >= Set->N)
	{
		Set->O = Set->L - Set->N;	//���������������� ������ ������� ����
		int Q = Set->p - Set->O;	//���������������� ������, ��� 1 �������� ������� ����, � ������ �����
		Set->v = Q / 2;				//�������� ��������������� �����
		if (Q >= 0 && ((Set->v * 2) == Q) && Set->v <= Set->N && ((Set->v + Set->O) <= Set->M))	//�������� ����������� ��������������
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
		Set->O = Set->N - Set->L;	//���������������� ������ ������� �����
		int Q = Set->p - Set->O;	//���������������� ������, ��� 1 �������� ������ ����, � ������ �����
		Set->v = Q / 2;				//�������� ��������������� �����
		if (Q >= 0 && ((Set->v * 2) == Q) && Set->v <= Set->M && ((Set->v + Set->O) <= Set->N))	//�������� ����������� ��������������
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
			cout << "������ ��������� ����!!! �������������� ����������!!!";
		}
	}

	Set->O = 0;
	Set->v = 0;
	Set->Type = 0;
	cout << "������ ��������� ����!!! �������������� ����������!!!";
	return -1;
}

int FillCoins(CoinsSet * Set)//������� ������� ������ �����
{
	if (Set->Type <= 0 && GetSetType(Set) <= 0)
	{
		return -1;//������ ����������� ����
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
				cout << "������ �������������� ������ �����! A[i] == 1";
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
				cout << "������ �������������� ������ �����! A[i] == 0";
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
				cout << "������ �������������� ������ �����! A[i] == 0";
				return Set->Type*-1;
			}
		}
		else
		{
			cout << "������ ������������ �������� � ������� A!!!";
			return Set->Type*-1;
		}
	}

	if (M == 0 && N == 0 && O == 0 && v0 == 0 && v1 == 0)
	{
		cout << "������ ������� ����� ������� ��������!!!";
		Set->Type += 4;
		return Set->Type;
	}
	cout << "������ �������������� ������ �����! ������������ �������� ��������!";
	return Set->Type*-1;
}

int PrintIntArray(int * Arr, int Len)//������� ������ �������� �������������� ������� � �������
{
	for (int i = 0; i < Len; i++)
	{
		cout << Arr[i];
	}
	return 0;
}

int * CopyIntArray(int * Arr, int Len)//������� ����������� �������������� �������
{
	int * NewArr = new int[Len];
	for (int i = 0; i < Len; i++)
	{
		NewArr[i] = Arr[i];
	}
	return NewArr;
}

int VisualValidateCoins(CoinsSet * Set, int S, int K)//������� ���������� �������� ������ �����
{
	int Len = Set->M + Set->N;
	int * TmpCoins = CopyIntArray(Set->Coins, Len);
	int L = Set->N;
	cout << "�������� ����� �����:" << endl;
	PrintIntArray(TmpCoins, Len);
	cout << endl << "����� ����� �� �����" << endl;
	for (int i = 0, pos = 0; i < K; i++, pos += S)
	{
		if (pos >= Len)		//������� � ������ ������� ��� ���������� �����
		{
			pos -= Len;
		}
		L += 1 - TmpCoins[pos] * 2;	//������� ����� ����� ������� �����
		TmpCoins[pos] = 1 - TmpCoins[pos];	//������ 1 �� 0, 0 �� 1
		cout << i + 1 << ")\t";
		PrintIntArray(TmpCoins, Len);
		cout << endl;
	}
	cout << "����� ������� ����� ����� ���������� ����: " << L;

	delete TmpCoins;
	return L;
}
