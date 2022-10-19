#include "Bird.h"
Bird::Bird()
{
	cout << " Добавление Птицы" << endl << endl;
	try
	{
		setType(2);
		cout << "Введите породу: ";
		cin.ignore(256, '\n');
		getline(cin, species);
		if (species == "")
			throw (string)"Поле 'Порода' не может быть пустым";
		cout << "Введите окрас: ";
		getline(cin, color);
		if (color == "")
			throw (string)"Поле 'Окрас' не может быть пустым";
		cout << "Введите тип питания: ";
		getline(cin, food);
		if (food == "")
			throw (string)"Поле не может быть пустым";
		cout << "Введите место обитания: ";
		getline(cin, home);
		if (home == "")
			throw (string)"Поле 'Где обитает' не может быть пустым";
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
	cout << "Был вызван деструктор класса Bird" << endl;
}

void Bird::edit()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		int index;
		string new_vall;
		cout << "Выберите параметр для изменения:" << endl
			<< "(1) - Порода\n (2) - Окрас\n (3) - Чем питается\n (4) - Где обитает\n";
		cout << "Ваш выбор: ";
		cin >> index;
		if (index < 1 || index > 4)
		{
			throw (string)"Параметра с данным индексом не существует";
		}
		cout << "Исходное значение: ";
		switch (index)
		{
		case 1:
			cout << species << endl;
			cout << "Новое значение: ";
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"Поле 'Порода' не может быть пустым";
			species = new_vall;
			break;
		case 2:
			cout << color << endl;
			cout << "Новое значение: ";
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"Поле 'Окрас' не может быть пустым";
			color = new_vall;
			break;
		case 3:
			cout << food << endl;
			cout << "Новое значение: ";
			getline(cin, new_vall);
			if (new_vall == "")
				throw (string)"Поле 'Чем питается' не может быть пустым";
			food = new_vall;
			break;
		case 4:
			cout << home << endl;
			cout << "Новое значение: ";
			cin >> new_vall;
			if (new_vall == "")
				throw (string)"Поле 'Где обитает' не может быть пустым";
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
	out << "Кот" << endl;
	out << "Порода: " << this->species << endl
		<< "Окрас: " << this->color << endl
		<< "Тип питания: " << this->food << endl
		<< "Где обтьает: " << this->home << endl;
}
