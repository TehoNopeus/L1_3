#include "Fish.h"
Fish::Fish()
{
	cout << " ���������� ����" << endl << endl;
	try
	{
		setType(1);
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
		setError(false);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

Fish::Fish(ifstream& fin)
{
	setType(1);
	getline(fin, species);
	getline(fin, color);
	getline(fin, food);
}

Fish::~Fish()
{
	cout << "��� ������ ���������� ������ Fish" << endl;
}

void Fish::edit()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		int index;
		string new_vall;
		cout << "�������� �������� ��� ���������:" << endl
			<< "(1) - ������\n (2) - �����\n (3) - ��� �������\n";
		cout << "��� �����: ";
		cin >> index;
		if (index < 1 || index > 3)
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
				throw (string)"���� '��� �������' �� ����� ���� ������";
			food = new_vall;
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

void Fish::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->species << endl
		<< this->color << endl
		<< this->food << endl;
}

void Fish::print(ostream& out)
{
	setlocale(LC_ALL, "Russian");
	out << "����" << endl;
	out << "������: " << this->species << endl
		<< "�����: " << this->color << endl
		<< "��� �������: " << this->food << endl;
}

