#include <iostream>;
#include <time.h>
#include "HashTable.h"
using namespace std;


void PrintMenu()
{
	cout << endl;
	cout << "1. Add." << endl;
	cout << "2. Delete." << endl;
	cout << "3. Search." << endl;
	cout << "0. Exit." << endl;
}

// Проверка корректного ввода пункта в меню
//
int ChoiseVariant(int count)
{
	int variant;
	cout << "Chouse vairant: ";
	cin >> variant;
	while (variant < 0 or variant>3)
	{
		cout << "Incorrect input. Try again. " << endl;
		cout << "Chouse vairant: ";
		cin >> variant;
	}
	return variant;
}

void MainMenu(int *table)
{
	HashT map;
	string result;
	string element;
	string key;
	int count = 7; // Количество пунктов в меню
	int variant; // Пункт меню, выбранный пользователем

	do
	{
		system("cls");
		map.PrintMap();
		PrintMenu();
		variant = ChoiseVariant(3);
		switch (variant)
		{
		case 1:
			cout << "Enter key: ";
			cin >> key;
			cout << "Enter value: ";
			cin >> element;
			map.Add(key, element, table);
			break;
		case 2:
			cout << "Enter key: ";
			cin >> key;
			map.Delete(key, table);
			break;
		case 3:
			cout << "Enter key: ";
			cin >> key;
			result=map.Search(key, table);
			cout << "Value: " << result;
			system("pause");
			break;
		default:
			break;
		}
		if (variant == 0)
		{
			system("pause");
		}
	} while (variant != 0);
}

int main()
{
    srand(time(NULL));
    int i;
    int* table = new int[8];
    for (i = 0; i < 8; i++)
    {
        table[i] = rand() % 8;
    }
	MainMenu(table);
	return 0;
}