#include "Keeper.h"

Keeper::Keeper()
{
	this->data = nullptr;
	this->size = 0;
}

Keeper::~Keeper()
{
	delete[] data;
}

int Keeper::getSize()
{
	return size;
}

void Keeper::add()
{
	int type;
	try
	{
		cout << " Выберите класс \n (1) - Рыбы \n (2) - Птицы  \n (3) - Коты\n";
		cin >> type;
		while (type > 3 || type < 1) {
			cout << "Выбрана не верная позиция"<< endl;
			cout << " Выберите класс \n (1) - Рыбы \n (2) - Птицы  \n (3) - Коты\n";
			cin >> type;
		}
		Animal** ctm = new Animal * [size + 1];
		for (int i = 0; i < size; i++)
		{
			ctm[i] = data[i];
		}
		switch (type)
		{
		case 1:
			ctm[size] = new Fish;
			break;
		case 2:
			ctm[size] = new Bird;
			break;
		case 3:
			ctm[size] = new Cat;
			break;
		default:
			break;
		}
		size++;
		if (data)
			delete[] data;
		data = ctm;
		cout << "Элемент успешно добавлен" << endl;
		system("pause");
	}
	catch(string err)
	{cout << "ERROR: " + err << endl;
	system("pause");
	};
}
void Keeper::add(int _type, ifstream& inf)
{
	Animal** ctm = new Animal * [size + 1];
	for (int i = 0; i < size; i++)
	{
		ctm[i] = data[i];
	}
	switch (_type)
	{
	case 1:
		ctm[size] = new Fish(inf);
		break;
	case 2:
		ctm[size] = new Bird(inf);
		break;
	case 3:
		ctm[size] = new Cat(inf);
		break;
	default:
		break;
	}
	size++;
	if (data)
		delete[] data;
	data = ctm;
}

void Keeper::edit()
{
	int index;
	if (!size)
	{
		cout << "Контейнер пуст! Загрузите данные из файла или добавьте новые элементы." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size; i++)
		{
			cout << "(" << i << ") ";
			switch (data[i]->getType())
			{
			case 1:
				cout << "Рыбы" << endl;
				break;
			case 2:
				cout << "Птицы" << endl;
				break;
			case 3:
				cout << "Коты" << endl;
				break;
			default:
				break;
			}
		}
		cout << "Выберите элемент для именения: ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"Выбранного элемента не существует";
		data[index]->edit();
		if (data[index]->isError())
		{
			cout << "Элемент не изменен из-за ошибки" << endl;
		}
		else
		{
			cout << "Элемент изменен успешно" << endl;
		}
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}

void Keeper::del()
{
	int index;
	if (!size)
	{
		cout << "Контейнер пуст! Загрузите данные из файла или добавьте новые элементы." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size; i++)
		{
			cout << "(" << i << ") ";
			switch (data[i]->getType())
			{
			case 1:
				cout << "Рыбы" << endl;
				break;
			case 2:
				cout << "Птицы" << endl;
				break;
			case 3:
				cout << "Коты" << endl;
				break;
			default:
				break;
			}
		}
		cout << "Выберите элемент для удаления: ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"Выбранного элемента не существует";
		if (size == 1)
		{
			delete[] data;
			data = nullptr;
			cout << "Элемент удален успешно" << endl;
			size--;
			system("pause");
			return;
		}
		Animal** ctm = new Animal * [size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (index == i)
				continue;
			ctm[j] = data[i];
		}
		delete[] data;
		data = ctm;
		size--;
		cout << "Элемент удален успешно" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}

void Keeper::save()
{
	ofstream fout("output.txt");
	for (int i = 0; i < size; i++)
	{
		data[i]->save(fout);
	}
	fout.close();
	cout << "Элементы успешно сохранены в файл" << endl;
	system("pause");
}

void Keeper::load()
{
	ifstream inf("output.txt");
	if (inf.fail())
	{
		cout << "Файл пустой!" << endl;
		system("pause");
		return;
	}
	int type = 0;
	while (inf)
	{
		inf >> type;
		if (inf.peek() == -1)
		{
			break;
		}
		add(type, inf);
	}
	inf.close();
	cout << "Элементы успешно загружены из файла" << endl;
	system("pause");
}

ostream& operator<<(ostream& out, Keeper& obj)
{
	if (!obj.size)
	{
		cout << "Контейнер пуст!" << endl;
		system("pause");
		return out;
	}
	for (int i = 0; i < obj.size; i++)
	{
		obj.data[i]->print(out);
	}
	system("pause");
	return out;
}
