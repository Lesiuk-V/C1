#include "Children.h"
#include <iostream>
#include <fstream>
using namespace std;


//метод для запису нових даних дитини
void Children::create()
{
    cin.ignore(10, '\n');
    cout << "\nІм'я: "; cin >> name;
    cout << "Прізвище: "; cin >> surname;
    cout << "По батькові: "; cin >> patronymic;
    cout << "Національність: "; cin >> nationality;
    cout << "Дата народження: "; cin >> dateOfBirth;
    cout << "Ім'я матері: "; cin >> MomName;
    cout << "Ім'я батька: "; cin >> DadName;
    cout << "Номер телефону матері: "; cin >> MomNumber;
    cout << "Номер телефону батька: "; cin >> DadNumber;
    setGroup(); //установка групи
    id = setId(); //установка ід
}

//метод для відображення всіх даних дітей
void Children::showData()
{ 
    cout << "id: "                     << id << endl;
    cout << "Ім'я: "                   << name << endl;
    cout << "Прізвище: "               << surname << endl;
    cout << "По батькові: "            << patronymic << endl;
    cout << "Група: "                  << group +1 << endl;
    cout << "Національність: "         << nationality << endl;
    cout << "Дата народження: "        << dateOfBirth << endl;
    cout << "Ім'я матері: "            << MomName << endl;
    cout << "Ім'я батька: "            << DadName << endl;
    cout << "Номер телефону матері: "  << MomNumber << endl;
    cout << "Номер телефону батька: "  << DadNumber << endl;
}


//метод для отримання групи конкретної дитини
Group Children::getGroup()
{
    return group;
}

//метод установки ід
int Children::setId()
{
    int tempId;
    string str;
    fstream idfile;
    idfile.open("childId.txt", fstream::out | fstream::in);//відкриваємо файл, в якому знаходиться записане ід
    ifstream temp;
    while (!idfile.eof())
    {
        getline(idfile, str);
        tempId = atoi(str.c_str());//отримуємо ід з файлу
    }
    ++tempId; //збільшуємо його на 1
    idfile.close();//закриваємо зв'язок з файлом
    idfile.open("childId.txt", fstream::out | fstream::in);//відкриваємо файл з вже збільшеним ід
    idfile << tempId;//записуємо ід у змінну, яку повертає метод
    idfile.close();
    return tempId;//повертаємо змінну
}


//метод для установки групи
void Children::setGroup()
{
    cin.ignore(10, '\n');
    cout << "Група: 1, 2, 3, 4. Введіть групу дитячого садка:";
    int input = -1;
    bool valid = false;
    do
    {
        cin >> input;
        if (cin.good())
        {
            
            if (input > 0 && input <= 4)
                valid = true;
            
            else
            {
                valid = false;
                cout << "Помилка вводу. Введіть ще раз" << endl;
            }

        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка вводу. Введіть ще раз" << endl;
        }
    } while (!valid);

        switch (input)
        {
        case 1:
            group = first;
            break;
        case 2:
            group = second;
            break;
        case 3:
            group = third;
            break;
        case 4:
            group = fourth;
            break;
        default:

            break;
        }
}

//метод зчитування даних з файлу
void Children::read(int pn) {
    ifstream ifile;
    ifile.open("Children.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);

    ifile.seekg(pn * sizeof(Children));
    ifile.read((char*)this, sizeof(*this));
    ifile.close();
}

//метод запису даних в файл
void Children::write() {
    ofstream ofile;
    ofile.open("Children.dat", ios::app | ios::binary | ios::out | ios::in);
    ofile.write((char*)this, sizeof(*this));
    ofile.close();
}


int Children::count()
{
    ifstream ifile;
    ifile.open("Children.dat ", ios::binary);
    ifile.seekg(0, ios::end);
    return (int)ifile.tellg() / sizeof(Children);
    ifile.close();
}

#pragma region Children search

void Children::searchName()
{
    Children child;
    ifstream ifile;
    char str[40];
    ifile.open("Children.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "Введіть ім'я для пошуку: ";
    cin >> str;
    for (int i = 0; i < count(); i++)
    {
        ifile.seekg(i * sizeof(Children));
        ifile.read(reinterpret_cast<char*>(&child), sizeof(Children));
        if (0 == strcmp(str, child.name))
        {
            child.showData();
        }
    }
    ifile.close();
}

void Children::searchSurname()
{
    Children child;
    ifstream ifile;
    char str[40];
    ifile.open("Children.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "Введіть прізвище для пошуку: ";
    cin >> str;
    for (int i = 0; i < count(); i++)
    {
        ifile.seekg(i * sizeof(Children));
        ifile.read(reinterpret_cast<char*>(&child), sizeof(Children));
        if (0 == strcmp(str, child.surname))
        {
            child.showData();
        }
    }
    ifile.close();
}

void Children::searchDateOfBirth()
{
    Children child;
    ifstream ifile;
    char str[40];
    ifile.open("Children.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "Введіть дату народження для пошуку(день.місяць.рік): ";
    cin >> str;
    for (int i = 0; i < count(); i++)
    {
        ifile.seekg(i * sizeof(Children));
        ifile.read(reinterpret_cast<char*>(&child), sizeof(Children));
        if (0 == strcmp(str, child.dateOfBirth))
        {
            child.showData();
        }
    }
    ifile.close();
}

void Children::searchGroup()
{
    Children child;
    ifstream ifile;
    int groupSearch;
    ifile.open("Children.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "Введіть групу дитячого садка(1, 2, 3, 4): ";
    cin >> groupSearch;
    for (int i = 0; i < count(); i++)
    {
        
        ifile.seekg(i * sizeof(Children));
        ifile.read(reinterpret_cast<char *>(&child), sizeof(Children));
       
        if (child.group + 1 == groupSearch)
        {
            child.showData();
        }
    }
    ifile.close();
}

#pragma endregion

#pragma region Delete adn edit data

void Children::deleteData()
{
    Children child;
    int str;
    cout << "Введіть номер документа для видалення: ";
    cin >> str;
    ifstream file;
    file.open("Children.dat", ios::binary | ios::out | ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
    file.read(reinterpret_cast<char*>(&child), sizeof(Children));
    while (!file.eof())
    {

        if (child.id != str)
        {
            temp.write(reinterpret_cast<char*>(&child), sizeof(Children));
        }

        else
        {
            cout << "\nЗапис видалено\n";
        }
        file.read(reinterpret_cast<char*>(&child), sizeof(Children));
    }
    temp.close();
    file.close();
    if (remove("Children.dat") != 0)
    {
        cout << "file was not removed";
    }
    if (rename("temp.dat", "Children.dat") != 0)
    {
        cout << "file was not renamed";
    }
}

void Children::editData()
{
    Children child;
    int str;
    cout << "Введіть номер документа для редагування: ";
    cin >> str;
    ifstream file;
    file.open("Children.dat", ios::binary | ios::out | ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
    file.seekg(0);
    file.read(reinterpret_cast<char*>(&child), sizeof(Children));
    while (!file.eof())
    {

        if (child.id != str)
        {
            temp.write(reinterpret_cast<char*>(&child), sizeof(Children));
        }

        else
        {
            child.create();
            temp.write(reinterpret_cast<char*>(&child), sizeof(Children));
        }
        file.read(reinterpret_cast<char*>(&child), sizeof(Children));
    }
    temp.close();
    file.close();
    if (remove("Children.dat") != 0)
    {
        cout << "file was not removed";
    }
    if (rename("temp.dat", "Children.dat") != 0)
    {
        cout << "file was not renamed";
    }
}

#pragma endregion