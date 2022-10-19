#include "Cat.h"
Cat::Cat()
{
	cout << " ���������� ����" << endl << endl;
	try
	{
		setType(3);
		cout << "������� ������: ";
		cin.ignore(256, '\n');
		getline(cin, species);
		if (species == "")
			throw (string)"���� '������' �� ����� ���� ������";
		cout << "������� �����: ";
		getline(cin, color);
		if (color == "")
			throw (string)"���� '�����' �� ����� ���� ������";
		cout << "������� ��� ��������� (�������, ���� �� �����������) ";
		getline(cin, user);
		if (user == "")
			throw (string)"���� �� ����� ���� ������";
		cout << "������� ������ ����: ";
		getline(cin, name);
		if (name == "")
			throw (string)"���� '������' �� ����� ���� ������";
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

Cat::Cat(ifstream& fin)
{
	setType(3);
	getline(fin, species);
	getline(fin, color);
	getline(fin, user);
	getline(fin, name);
}

Cat::~Cat()
{
	cout << "��� ������ ���������� ������ Cat" << endl;
}

void Cat::edit()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		int index;
		string new_vall;
		cout << "�������� �������� ��� ���������:" << endl
			<< " (1) - ������\n (2) - �����\n (3) - ��� ���������\n (4) - ������\n";
		cout<< "��� �����: ";
		cin >> index;
		if (index < 1 || index > 6)
		{
			throw (string)"��������� � ������ �������� �� ����������";
		}
		cout << "�������� ��������: ";
		switch (index)
		{
		case 1:
			cout << species << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"���� '������' �� ����� ���� ������";
			species = new_vall;
			break;
		case 2:
			cout << color << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"���� '�����' �� ����� ���� ������";
			color = new_vall;
			break;
		case 3:
			cout << user << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"���� '������������' �� ����� ���� ������";
			user = new_vall;
			break;
		case 4:
			cout << name << endl;
			cout << "����� ��������: ";
			cin >> new_vall;
			if (new_vall == "")
				throw (string)"���� '������' �� ����� ���� ������";
			user = new_vall;
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

void Cat::save(ofstream& fout)
{
	setlocale(LC_ALL, "Russian");
	fout << getType() << endl
		<< this->species << endl
		<< this->color << endl
		<< this->user << endl
		<< this->name << endl;
}

void Cat::print(ostream& out)
{
	setlocale(LC_ALL, "Russian");
	out << "���" << endl;
	out << "������: " << this->species << endl
		<< "�����: " << this->color << endl
		<< "��� ���������: " << this->user << endl
		<< "������: " << this->name << endl;
}
