#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include "CoinsSetStruct.h"

//������ 8.
//�� ����� ����������� N ����� ������� ����� � M ����� ������� ����.������ ����
//�� ���� ������� �������, �������������� ������ S - ��� ������.� ������ ��� 
//���� ���������� � �����.� ����� ������� ���� ���������� ������, 
//����� ����� K ����� ����� L �����, ������� ������� �����.

//TODO: ������� �������� ��� ������������ ���������� ��� ���������  

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
		AddConsoleTextColor("������ 8", 224);
		int M = ReadConsoleNum("������� ���������� ����� ������� ����...", 14);
		int N = ReadConsoleNum("������� ���������� ����� ������� �����...", 14);
		int L = ReadConsoleNum("������� ���������� ����� ������� ����� ����� ����������...", 14);
		int S = ReadConsoleNum("������� ������ ����...", 14);
		int K = ReadConsoleNum("������� ���������� �����...", 14);
		CoinsSet * Set = Create(M, N, L, S, K);
		if (Set != 0)
		{
			AddConsoleTextColor("������� ����� ������� ���������!\n���������:", 10);
			PrintIntArray(Set->Coins, M + N);
			cout << endl;
			if (ReadConsoleNum("������� 1 ����� ��������� ��� ����� ����� ��� ����������� ������...", 14) == 1)
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
		IsExit = ReadConsoleNum("������� 1 ����� ����� �� ��������� ��� ����� ����� ��� ����������� ������...", 14) == 1;
		KillSet(Set);
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