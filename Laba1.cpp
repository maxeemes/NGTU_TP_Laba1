#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include "CoinsSetStruct.h"

//Лабораторная работа №1
//Задача 8.
//По кругу расположено N монет гербами вверх и M монет гербами вниз.Обходя круг
//по ходу часовой стрелки, переворачивает каждую S - тую монету.В первый раз 
//счет начинается с герба.В каком порядке надо расставить монеты, 
//чтобы после K ходов стало L монет, лежащих гербами вверх.

using namespace std;

bool AddConsoleTextColor(const string Text, const int Color = 7);//Цвета: 7 - белый(стандартный), 10 - зеленый, 12 - красный, 14 - желтый, 224 - черный на желтом фоне
int ReadConsoleNum(const string Text = "", const int Color = 7);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	bool IsExit = false;

	do
	{
		AddConsoleTextColor("_____________________________________________________________________________", 14);
		AddConsoleTextColor("Задача 8", 224);
		AddConsoleTextColor(
			string("По кругу расположено N монет гербами вверх и M монет гербами вниз.Обходя круг\n") +
			string("по ходу часовой стрелки, переворачивает каждую S - тую монету.В первый раз\n") +
			string("счет начинается с герба.В каком порядке надо расставить монеты,\n") +
			string("чтобы после K ходов стало L монет, лежащих гербами вверх.\n") +
			string("_____________________________________________________________________________"), 14);
		int M = ReadConsoleNum("Введите M - количество монет гербами вниз...", 14);
		int N = ReadConsoleNum("Введите N - количество монет гербами вверх...", 14);
		int L = ReadConsoleNum("Введите L - количество монет гербами вверх после выполнения...", 14);
		int S = ReadConsoleNum("Введите S - размер шага...", 14);
		int K = ReadConsoleNum("Введите K - количество шагов...", 14);
		CoinsSet * Set = Create(M, N, L, S, K);
		if (Set != 0)
		{
			AddConsoleTextColor("Порядок монет успешно рассчитан!\nРезультат:", 10);
			PrintIntArray(Set->Coins, M + N);
			cout << endl;
			if (ReadConsoleNum("Введите 1, чтобы проверить, или любую цифру для продолжения работы...", 14) == 1)
			{
				AddConsoleTextColor("Проверка...");
				if (VisualValidateCoins(Set, S, K) == L)
				{
					AddConsoleTextColor("\nПорядок монет рассчитан правильно!", 10);
				}
				else
				{
					AddConsoleTextColor("\nПорядок монет рассчитан ошибочно!", 12);
				}
			}
		}
		else
		{
			AddConsoleTextColor("Ошибка рассчета набора монет!", 12);
		}
		IsExit = ReadConsoleNum("Введите 1, чтобы выйти из программы, или любую цифру для продолжения работы...", 14) == 1;
		//KillSet(Set);
	} while (IsExit == false);

	return 0;
}

bool AddConsoleTextColor(const string Text, const int Color)//Цвета: 7 - белый(стандартный), 10 - зеленый, 12 - красный, 14 - желтый, 224 - черный на желтом фоне
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