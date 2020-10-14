#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>

//������ 8.
//�� ����� ����������� N ����� ������� ����� � M ����� ������� ����.������ ����
//�� ���� ������� �������, �������������� ������ S - ��� ������.� ������ ��� 
//���� ���������� � �����.� ����� ������� ���� ���������� ������, 
//����� ����� K ����� ����� L �����, ������� ������� �����.

//TODO: ������� ��������� ��� �������� ���������� � ������ �����

using namespace std;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int M = 5; //����� ������� ����
	int N = 4; //����� ������� �����
	int S = 3; //���
	int K = 2; //���������� �����
	int L = 5; //����� ������� ����� ����� ����������
	int p = 0; //���������� ����� ����� �����������

	int SumNM = N + M;				//���������� �����
	int *A = new int[SumNM] {0};	//������ ������� ������������
	
	for (int i = 0, pos = 0; i < K; i++)	//������������ ����� ������ ����� �����������
	{
		A[pos] = 1 - A[pos];
		pos += S;
		if (pos >= SumNM)	//������� � ������ ������� ��� ���������� �����
		{
			pos -= SumNM;
		}
	}

	for (int i = 0; i < SumNM; i++)			//������������ ����� ���������� ����� ����� �����������
	{
		p += A[i];
		cout << A[i];	//��������������� ������� ������ ������� ����� �����������
	}
	//-------------------------------------
	//����������� ���� ��������������
	if (L >= N)		//1� ��� ��������������
	{
		int O = L - N;	//���������������� ������ ������� ����
		int Q = p - O;	//���������������� ������, ��� 1 �������� ������� ����, � ������ �����
		int v = Q / 2;	//�������� ��������������� �����
		if (Q >= 0 && ((v * 2) == Q) && v <= N && ((v + O) <= M))	//�������� ����������� ��������������
		{
			int v0 = v, v1 = v;	//���������������� ������ 
								//v0 - ������� ����; v1 - ������� �����
			if (A[0] == 0 && N > v1)
			{
				int *coins = new int[SumNM] {0};	//������ � ����������� �����
													//0 - ������� ����; 1 - ������� �����
				coins[0] = 1;
				N--;
				//------------------------------------------
				//��������������
				for (int i = 1; i < SumNM; i++)
				{
					if (A[i] == 1)
					{
						if (O > 0)
						{
							//coins[i] = 0;
							O--;
							M--;
						}
						else if (v0 > 0)
						{
							//coins[i] = 0;
							v0--;
							M--;
						}
						else if (v1 > 0)
						{
							coins[i] = 1;
							v1--;
							N--;
						}
						else
						{
							//������ �������������� A[i] == 1
						}
					}
					else if (A[i] == 0)
					{
						if ((M - (O + v0)) > 0)
						{
							//coins[i] = 0;
							M--;
						}
						else if ((N - v1) > 0)
						{
							coins[i] = 1;
							N--;
						}
						else
						{
							//������ �������������� A[i] == 0
						}
					}
					else
					{
						//������ ������������ �������� � ������� A
					}
				}
				//------------------------------------------
			}
			else if (A[0] == 1 && v1 > 0) //����� ���������������� ����� ������ ���� �� ������� ���� ����, ������� ���������� �������� ������ �����
			{
				int *coins = new int[SumNM] {0};	//������ � ����������� �����
													//0 - ������� ����; 1 - ������� �����
				coins[0] = 1;
				v1--;
				N--;
				//------------------------------------------
				//��������������
				for (int i = 1; i < SumNM; i++)
				{
					if (A[i] == 1)
					{
						if (O > 0)
						{
							//coins[i] = 0;
							O--;
							M--;
						}
						else if (v0 > 0)
						{
							//coins[i] = 0;
							v0--;
							M--;
						}
						else if (v1 > 0)
						{
							coins[i] = 1;
							v1--;
							N--;
						}
						else
						{
							//������ �������������� A[i] == 1
						}
					}
					else if (A[i] == 0)
					{
						if ((M - (O + v0)) > 0)
						{
							//coins[i] = 0;
							M--;
						}
						else if ((N - v1) > 0)
						{
							coins[i] = 1;
							N--;
						}
						else
						{
							//������ �������������� A[i] == 0
						}
					}
					else
					{
						//������ ������������ �������� � ������� A
					}
				}
				//------------------------------------------
			}
			else
			{
				cout << "������!!! �������������� ����������!!!";
			}
		}
		else
		{
			cout << "������!!! �������������� ����������!!!";
		}
	}
	else if (L < N)	//2� ��� ��������������
	{
		int O = N - L;	//���������������� ������ ������� �����
		int Q = p - O;	//���������������� ������, ��� 1 �������� ������ ����, � ������ �����
		int v = Q / 2;	//�������� ��������������� �����
		if (Q >= 0 && ((v * 2) == Q) && v <= M && ((v + O) <= N))	//�������� ����������� ��������������
		{
			int v0 = v, v1 = v;	//���������������� ������ 
								//v0 - ������� ����; v1 - ������� �����
			if (A[0] == 0 && N > v1)
			{
				int *coins = new int[SumNM] {0};	//������ � ����������� �����
													//0 - ������� ����; 1 - ������� �����
				coins[0] = 1;
				N--;
				//------------------------------------------
				//��������������
				for (int i = 1; i < SumNM; i++)
				{
					if (A[i] == 1)
					{
						if (O > 0)
						{
							coins[i] = 1;
							O--;
							N--;
						}
						else if (v0 > 0)
						{
							//coins[i] = 0;
							v0--;
							M--;
						}
						else if (v1 > 0)
						{
							coins[i] = 1;
							v1--;
							N--;
						}
						else
						{
							//������ �������������� A[i] == 1
						}
					}
					else if (A[i] == 0)
					{
						if ((N - (O + v1)) > 0)
						{
							coins[i] = 1;
							N--;
						}
						else if ((M - v0) > 0)
						{
							//coins[i] = 0;
							M--;
						}
						else
						{
							//������ �������������� A[i] == 0
						}
					}
					else
					{
						//������ ������������ �������� � ������� A
					}
				}
				//------------------------------------------
			}
			else if (A[0] == 1 && (v1 + O) > 0) //����� ���������������� ����� ������ ���� �� ������� ���� ����, ������� ���������� �������� ������ �����
			{
				int *coins = new int[SumNM] {0};	//������ � ����������� �����
													//0 - ������� ����; 1 - ������� �����
				coins[0] = 1;
				v1--;
				N--;
				//------------------------------------------
				//��������������
				for (int i = 1; i < SumNM; i++)
				{
					if (A[i] == 1)
					{
						if (O > 0)
						{
							//coins[i] = 0;
							O--;
							M--;
						}
						else if (v0 > 0)
						{
							//coins[i] = 0;
							v0--;
							M--;
						}
						else if (v1 > 0)
						{
							coins[i] = 1;
							v1--;
							N--;
						}
						else
						{
							//������ �������������� A[i] == 1
						}
					}
					else if (A[i] == 0)
					{
						if ((M - (O + v0)) > 0)
						{
							coins[i] = 0;
							M--;
						}
						else if ((N - v1) > 0)
						{
							coins[i] = 1;
							N--;
						}
						else
						{
							//������ �������������� A[i] == 0
						}
					}
					else
					{
						//������ ������������ �������� � ������� A
					}
				}
				//------------------------------------------
			}
			else
			{
				cout << "������!!! �������������� ����������!!!";
			}
		}
		else
		{
			cout << "������!!! �������������� ����������!!!";
		}
	}
	else 
	{
		cout << "������ ����������!!!";
	}

	return 0;
}
//----------------------------------------------------------------------------------------
int Processing(int *coins, int *A, int Len, int N, int M, int O, int v, int type) //��������������, �������� type: 0-3
{
	int v0 = v, v1 = v;
	bool IsOInN = type >= 2;
	coins[0] = 1;
	N--;
	if (type % 2 > 0)
	{
		v1--;
	}

	for (int i = 1; i < Len; i++)
	{
		if (A[i] == 1)
		{
			if (O > 0)
			{
				coins[i] = 1;
				O--;
				if (IsOInN)
				{
					N--;
				}
				else
				{
					M--;
				}
			}
			else if (v0 > 0)
			{
				//coins[i] = 0;
				v0--;
				M--;
			}
			else if (v1 > 0)
			{
				coins[i] = 1;
				v1--;
				N--;
			}
			else
			{
				//������ �������������� A[i] == 1
			}
		}
		else if (A[i] == 0 && IsOInN)
		{
			if ((N - (O + v1)) > 0)
			{
				coins[i] = 1;
				N--;
			}
			else if ((M - v0) > 0)
			{
				//coins[i] = 0;
				M--;
			}
			else
			{
				//������ �������������� A[i] == 0
			}
		}
		else if (A[i] == 0 && !IsOInN)
		{
			if ((N - v1) > 0)
			{
				coins[i] = 1;
				N--;
			}
			else if ((M - (O + v0)) > 0)
			{
				//coins[i] = 0;
				M--;
			}
			else
			{
				//������ �������������� A[i] == 0
			}
		}
		else
		{
			//������ ������������ �������� � ������� A
		}
	}
	return 0;
}
//----------------------------------------------------------------------------------------