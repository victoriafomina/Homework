#include "Phonebook.h"

// конструкторы - оператор присваивания - деструктор

Phonebook::Phonebook()
{
	int const size = 100;
	base = new Subscriber[size];
	numberOfNotes = 0;
	readInfoFromFile();
}

void Phonebook::readInfoFromFile()
{
	FILE* file = fopen("phonebook.txt", "r");
	int const sizeData = 100;
	int const sizeBuffer = 20;
	if (file)
	{
		char* data[sizeData] = {};
		int linesRead = 0;
		while (!feof(file))
		{
			char* buffer = new char[sizeBuffer];
			const int readBytes = fscanf(file, "%s", buffer);
			if (readBytes < 0)
			{
				break;
			}
			data[linesRead] = buffer;
			printf("%s", data[linesRead]);
			++linesRead;
		}
		numberOfNotes = linesRead / 2;
		for (int i = 0; i < linesRead; ++i)
		{
			Subscriber* s = new Subscriber;
			s->setName(data[i]);
			s->setNumber(data[i + 1]);
			(*this)[i / 2] = *s;
			++i;
			if (i == linesRead - 1)
			{
				delete s;
			}
		}
		for (int i = 0; i < linesRead; ++i)
		{
			delete[] data[i];
		}
	}
	fclose(file);
}

Phonebook::Phonebook(Phonebook const & p) {}

Phonebook & Phonebook::operator=(Phonebook const & p) 
{
	return *this;
}

Phonebook::~Phonebook()
{
	delete[] base;
	numberOfNotes = 0;
}

// getter - setter

Subscriber Phonebook::operator[](int number) const
{
	return base[number];
}

Subscriber & Phonebook::operator[](int number)
{
	return base[number];
}

int Phonebook::size() const
{
	return numberOfNotes;
}

// остальные методы

void Phonebook::addNote(Subscriber const & note) // 1
{
	(*this)[numberOfNotes] = note;
	++numberOfNotes;
}

void Phonebook::printAllNotes() const // 2
{
	int const size = this->size();
	for (int i = 0; i < size; ++i)
	{
		(*this)[i].print();
	}
}

bool compareStr(char const * name1, char const * name2)
{
	if (strlen(name1) != strlen(name2))
	{
		return false;
	}
	int const length = (int)strlen(name1);
	for (int i = 0; i < length; ++i)
	{
		if (name1[i] != name2[i])
		{
			return false;
		}
	}
	return true;
}

void Phonebook::findNumberByName(char const * name) const // 3
{
	for (int i = 0; i < size(); ++i)
	{
		if (compareStr((*this)[i].getName(), name))
		{
			(*this)[i].print();
		}
	}
}

void Phonebook::findNameByNumber(char const * number) const // 4
{
	for (int i = 0; i < size(); ++i)
	{
		if (compareStr((*this)[i].getNumber(), number))
		{
			(*this)[i].print();
		}
	}
}

void Phonebook::saveToFile() const // 5
{
	FILE* file = fopen("phonebook.txt", "w");
	if (!file)
	{
		printf("FILE WAS NOT FOUND\n!");
	}
	else
	{
		for (int i = 0; i < numberOfNotes; ++i)
		{
			fwrite((*this)[i].getName(), sizeof(char), strlen((*this)[i].getName()), file);
			fwrite(" ", sizeof(char), 1, file);
			fwrite((*this)[i].getNumber(), sizeof(char), strlen((*this)[i].getNumber()), file);
			fwrite("\n", sizeof(char), 1, file);
		}
	}
	fclose(file);
}