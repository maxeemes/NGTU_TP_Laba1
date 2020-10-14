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
		cout << "������ �������� ��������� CoinsSet, �������� �������� M, N, L!!!\n";
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
		Set->O = Set->L - Set->N;	//���������������� ������ ������� ����
		int Q = Set->p - Set->O;	//���������������� ������, ��� 1 �������� ������� ����, � ������ �����
		Set->v = Q / 2;				//�������� ��������������� �����
		if (Q >= 0 && ((Set->v * 2) == Q) && Set->v <= Set->N && ((Set->v + Set->O) <= Set->M))	//�������� ����������� ��������������
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
		Set->O = Set->N - Set->L;	//���������������� ������ ������� �����
		int Q = Set->p - Set->O;	//���������������� ������, ��� 1 �������� ������ ����, � ������ �����
		Set->v = Q / 2;				//�������� ��������������� �����
		if (Q >= 0 && ((Set->v * 2) == Q) && Set->v <= Set->M && ((Set->v + Set->O) <= Set->N))	//�������� ����������� ��������������
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
			cout << "������ ��������� ����!!! �������������� ����������!!!";
		}
	}

	Set->O = 0;
	Set->v = 0;
	Set->SetType = 0;
	cout << "������ ��������� ����!!! �������������� ����������!!!";
	return -1;
}



