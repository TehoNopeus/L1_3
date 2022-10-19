#include "Cat.h"
Cat::Cat()
{
	cout << " Добавление Кота" << endl << endl;
	try
	{
		setType(3);
		cout << "Введите породу: ";
		cin.ignore(256, '\n');
		getline(cin, species);
		if (species == "")
			throw (string)"Поле 'Порода' не может быть пустым";
		cout << "Введите окрас: ";
		getline(cin, color);
		if (color == "")
			throw (string)"Поле 'Окрас' не может быть пустым";
		cout << "Введите ФИО владельца (Указать, если он отсутствует) ";
		getline(cin, user);
		if (user == "")
			throw (string)"Поле не может быть пустым";
		cout << "Введите кличку кота: ";
		getline(cin, name);
		if (name == "")
			throw (string)"Поле 'Кличка' не может быть пустым";
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
	cout << "Был вызван деструктор класса Cat" << endl;
}

void Cat::edit()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		int index;
		string new_vall;
		cout << "Выберите параметр для изменения:" << endl
			<< " (1) - Порода\n (2) - Окрас\n (3) - ФИО Владельца\n (4) - Кличка\n";
		cout<< "Ваш выбор: ";
		cin >> index;
		if (index < 1 || index > 6)
		{
			throw (string)"Параметра с данным индексом не существует";
		}
		cout << "Исходное значение: ";
		switch (index)
		{
		case 1:
			cout << species << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"Поле 'Порода' не может быть пустым";
			species = new_vall;
			break;
		case 2:
			cout << color << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"Поле 'Окрас' не может быть пустым";
			color = new_vall;
			break;
		case 3:
			cout << user << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"Поле 'Пользователь' не может быть пустым";
			user = new_vall;
			break;
		case 4:
			cout << name << endl;
			cout << "Новое значение: ";
			cin >> new_vall;
			if (new_vall == "")
				throw (string)"Поле 'Кличка' не может быть пустым";
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
	out << "Кот" << endl;
	out << "Порода: " << this->species << endl
		<< "Окрас: " << this->color << endl
		<< "ФИО владельца: " << this->user << endl
		<< "Кличка: " << this->name << endl;
}
