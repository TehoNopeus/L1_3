#include "Bird.h"
Bird::Bird()
{
	cout << " ���������� �����" << endl << endl;
	try
	{
		setType(2);
		cout << "������� ������: ";
		cin.ignore(256, '\n');
		getline(cin, species);
		if (species == "")
			throw (string)"���� '������' �� ����� ���� ������";
		cout << "������� �����: ";
		getline(cin, color);
		if (color == "")
			throw (string)"���� '�����' �� ����� ���� ������";
		cout << "������� ��� �������: ";
		getline(cin, food);
		if (food == "")
			throw (string)"���� �� ����� ���� ������";
		cout << "������� ����� ��������: ";
		getline(cin, home);
		if (home == "")
			throw (string)"���� '��� �������' �� ����� ���� ������";
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

Bird::Bird(ifstream& fin)
{
	setType(2);
	getline(fin, species);
	getline(fin, color);
	getline(fin, food);
	getline(fin, home);
}

Bird::~Bird()
{
	cout << "��� ������ ���������� ������ Bird" << endl;
}

void Bird::edit()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		int index;
		string new_vall;
		cout << "�������� �������� ��� ���������:" << endl
			<< "(1) - ������\n (2) - �����\n (3) - ��� ��������\n (4) - ��� �������\n";
		cout << "��� �����: ";
		cin >> index;
		if (index < 1 || index > 4)
		{
			throw (string)"��������� � ������ �������� �� ����������";
		}
		cout << "�������� ��������: ";
		switch (index)
		{
		case 1:
			cout << species << endl;
			cout << "����� ��������: ";
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"���� '������' �� ����� ���� ������";
			species = new_vall;
			break;
		case 2:
			cout << color << endl;
			cout << "����� ��������: ";
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"���� '�����' �� ����� ���� ������";
			color = new_vall;
			break;
		case 3:
			cout << food << endl;
			cout << "����� ��������: ";
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"���� '��� ��������' �� ����� ���� ������";
			food = new_vall;
			break;
		case 4:
			cout << home << endl;
			cout << "����� ��������: ";
			cin >> new_vall;
			if (new_vall == "")
				throw (string)"���� '��� �������' �� ����� ���� ������";
			home = new_vall;
			break;
		default:
			break;
		}
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

void Bird::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->species << endl
		<< this->color << endl
		<< this->food << endl
		<< this->home << endl;
}

void Bird::print(ostream& out)
{
	setlocale(LC_ALL, "Russian");
	out << "���" << endl;
	out << "������: " << this->species << endl
		<< "�����: " << this->color << endl
		<< "��� �������: " << this->food << endl
		<< "��� �������: " << this->home << endl;
}
