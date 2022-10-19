#include <iostream>
#include "Keeper.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Keeper AnimalNote;
	int menu;
	do
	{
		system("cls");
		cout << "               МЕНЮ               " << endl
			<< "Кол-во элементов в контейнере : [" << AnimalNote.getSize() << "]" << endl;
			cout << "(1) Добавить элемент\n";
			cout<< "(2) Удалить элемент\n";
			cout << "(3) Сохранить данные в файл\n";
			cout << "(4) Загрузить данные из файла\n";
			cout << "(5) Изменить данные элемента\n";
			cout << "(6) Вывести данные из контейнера\n";
			cout << "(0) Выход" << endl;
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:
			AnimalNote.add();
			break;
		case 2:
			AnimalNote.del();
			break;
		case 3:
			AnimalNote.save();
			break;
		case 4:
			AnimalNote.load();
			break;
		case 5:
			AnimalNote.edit();
			break;
		case 6:
			cout << AnimalNote;
			break;
		case 0:
			return 0;
		default:
			break;
		}
		/*Меню*/
	} while (true);
}
