#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include "CoinsSetStruct.h"

//������������ ������ �1
//������ 8.
//�� ����� ����������� N ����� ������� ����� � M ����� ������� ����.������ ����
//�� ���� ������� �������, �������������� ������ S - ��� ������.� ������ ��� 
//���� ���������� � �����.� ����� ������� ���� ���������� ������, 
//����� ����� K ����� ����� L �����, ������� ������� �����.

using namespace std;

bool AddConsoleTextColor(const string Text, const int Color = 7);//�����: 7 - �����(�����������), 10 - �������, 12 - �������, 14 - ������, 224 - ������ �� ������ ����
int ReadConsoleNum(const string Text = "", const int Color = 7);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	bool IsExit = false;

	do
	{
		AddConsoleTextColor("_____________________________________________________________________________", 14);
		AddConsoleTextColor("������ 8", 224);
		AddConsoleTextColor(
			string("�� ����� ����������� N ����� ������� ����� � M ����� ������� ����.������ ����\n") +
			string("�� ���� ������� �������, �������������� ������ S - ��� ������.� ������ ���\n") +
			string("���� ���������� � �����.� ����� ������� ���� ���������� ������,\n") +
			string("����� ����� K ����� ����� L �����, ������� ������� �����.\n") +
			string("_____________________________________________________________________________"), 14);
		int M = ReadConsoleNum("������� M - ���������� ����� ������� ����...", 14);
		int N = ReadConsoleNum("������� N - ���������� ����� ������� �����...", 14);
		int L = ReadConsoleNum("������� L - ���������� ����� ������� ����� ����� ����������...", 14);
		int S = ReadConsoleNum("������� S - ������ ����...", 14);
		int K = ReadConsoleNum("������� K - ���������� �����...", 14);
		CoinsSet * Set = Create(M, N, L, S, K);
		if (Set != 0)
		{
			AddConsoleTextColor("������� ����� ������� ���������!\n���������:", 10);
			PrintIntArray(Set->Coins, M + N);
			cout << endl;
			if (ReadConsoleNum("������� 1, ����� ���������, ��� ����� ����� ��� ����������� ������...", 14) == 1)
			{
				AddConsoleTextColor("��������...");
				if (VisualValidateCoins(Set, S, K) == L)
				{
					AddConsoleTextColor("\n������� ����� ��������� ���������!", 10);
				}
				else
				{
					AddConsoleTextColor("\n������� ����� ��������� ��������!", 12);
				}
			}
		}
		else
		{
			AddConsoleTextColor("������ �������� ������ �����!", 12);
		}
		IsExit = ReadConsoleNum("������� 1, ����� ����� �� ���������, ��� ����� ����� ��� ����������� ������...", 14) == 1;
		//KillSet(Set);
	} while (IsExit == false);

	return 0;
}

bool AddConsoleTextColor(const string Text, const int Color)//�����: 7 - �����(�����������), 10 - �������, 12 - �������, 14 - ������, 224 - ������ �� ������ ����
{
	if (Color == 7) {
		cout << Text << endl;
	}
	else {
		HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(Console, Color);
		cout << Text << endl;
		SetConsoleTextAttribute(Console, 7);
	}
	return true;
}

int ReadConsoleNum(const string Text, const int Color)
{
	if (!Text.empty())
	{
		AddConsoleTextColor(Text, Color);
	}
	int Num;
	cin >> Num;
	if (Num >= 0)
	{
		return Num;
	}
	return -1;
}