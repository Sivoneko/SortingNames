// Сортировка вручную.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "SortName.h"
#include <string>
#include <time.h>
using namespace std;

void Menu();
int main()
{
	New<string*, string> first;

	char answer;
	do {
		Menu();
		cout << "Choose one of menu's point: ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case '1':
		{

			string vvod;
			int number = 0;
			cout << "Enter number of name's: ";
			try
			{
				if (!(cin >> number)) throw "Not a int type!";
			}
			catch (char *WrongInput)
			{
				cout << WrongInput << endl;
				number = 0;
			}
			try
			{
				first.add(number);
			}
			catch (char* NothingToAdd)
			{
				cout << NothingToAdd << endl;
			}
			break;
		}
		case '2':
		{
			try
			{

				//first.Sortirovka(); // работает в 5 раз дольше

				double t1 = clock();
				first.sort();
				double t2 = clock() - t1;
				cout << t2/ CLOCKS_PER_SEC << endl;
			}
			catch (char* NothingToSort)
			{
				cout << NothingToSort << endl;
			}
			break;
		}
		case '3':
		{
			cout << first;
			break;
		}
		default:
			break;
		}
	} while (answer != 'o');


	//----------------------------------------------------------------------------------------------
	//функция с наследованого класса по заполнению стека
	/*
	try
	{
		first.add(number);
	}
	catch (char* NothingToAdd)
	{
		cout << NothingToAdd << endl;
	}


	try
	{
		first.Sortirovka();
	}
	catch (char* NothingToSort)
	{
		cout << NothingToSort << endl;
	}
	


	cout << first;
	*/
	//----------------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------------
	//Основной класс, заполнение стека
	/*
	for (int i(0); i < number; i++)
	{
	cout << "Enter name: ";
	cin.get();
	getline(cin, vvod);
	first.Push(vvod);
	}
	for (int i(0); i < number; i++)
	{
	first.Pop();
	}
	*/
	//----------------------------------------------------------------------------------------------
	_getch();
    return 0;
}

void Menu()
{
	cout << "1 - Enter base of fucking people" << endl;
	cout << "2 - Sort base" << endl;
	cout << "3 - Output base" << endl;
}