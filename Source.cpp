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
		cout << "               ����               " << endl
			<< "���-�� ��������� � ���������� : [" << AnimalNote.getSize() << "]" << endl;
			cout << "(1) �������� �������\n";
			cout<< "(2) ������� �������\n";
			cout << "(3) ��������� ������ � ����\n";
			cout << "(4) ��������� ������ �� �����\n";
			cout << "(5) �������� ������ ��������\n";
			cout << "(6) ������� ������ �� ����������\n";
			cout << "(0) �����" << endl;
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
		/*����*/
	} while (true);
}
