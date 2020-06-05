#include "Children.h"
#include <iostream>
#include <fstream>
using namespace std;


//����� ��� ������ ����� ����� ������
void Children::create()
{
    cin.ignore(10, '\n');
    cout << "\n��'�: "; cin >> name;
    cout << "�������: "; cin >> surname;
    cout << "�� �������: "; cin >> patronymic;
    cout << "�������������: "; cin >> nationality;
    cout << "���� ����������: "; cin >> dateOfBirth;
    cout << "��'� �����: "; cin >> MomName;
    cout << "��'� ������: "; cin >> DadName;
    cout << "����� �������� �����: "; cin >> MomNumber;
    cout << "����� �������� ������: "; cin >> DadNumber;
    setGroup(); //��������� �����
    id = setId(); //��������� ��
}

//����� ��� ����������� ��� ����� ����
void Children::showData()
{ 
    cout << "id: "                     << id << endl;
    cout << "��'�: "                   << name << endl;
    cout << "�������: "               << surname << endl;
    cout << "�� �������: "            << patronymic << endl;
    cout << "�����: "                  << group +1 << endl;
    cout << "�������������: "         << nationality << endl;
    cout << "���� ����������: "        << dateOfBirth << endl;
    cout << "��'� �����: "            << MomName << endl;
    cout << "��'� ������: "            << DadName << endl;
    cout << "����� �������� �����: "  << MomNumber << endl;
    cout << "����� �������� ������: "  << DadNumber << endl;
}


//����� ��� ��������� ����� ��������� ������
Group Children::getGroup()
{
    return group;
}

//����� ��������� ��
int Children::setId()
{
    int tempId;
    string str;
    fstream idfile;
    idfile.open("childId.txt", fstream::out | fstream::in);//��������� ����, � ����� ����������� �������� ��
    ifstream temp;
    while (!idfile.eof())
    {
        getline(idfile, str);
        tempId = atoi(str.c_str());//�������� �� � �����
    }
    ++tempId; //�������� ���� �� 1
    idfile.close();//��������� ��'���� � ������
    idfile.open("childId.txt", fstream::out | fstream::in);//��������� ���� � ��� ��������� ��
    idfile << tempId;//�������� �� � �����, ��� ������� �����
    idfile.close();
    return tempId;//��������� �����
}


//����� ��� ��������� �����
void Children::setGroup()
{
    cin.ignore(10, '\n');
    cout << "�����: 1, 2, 3, 4. ������ ����� �������� �����:";
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
                cout << "������� �����. ������ �� ���" << endl;
            }

        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������� �����. ������ �� ���" << endl;
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

//����� ���������� ����� � �����
void Children::read(int pn) {
    ifstream ifile;
    ifile.open("Children.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);

    ifile.seekg(pn * sizeof(Children));
    ifile.read((char*)this, sizeof(*this));
    ifile.close();
}

//����� ������ ����� � ����
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
    cout << "������ ��'� ��� ������: ";
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
    cout << "������ ������� ��� ������: ";
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
    cout << "������ ���� ���������� ��� ������(����.�����.��): ";
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
    cout << "������ ����� �������� �����(1, 2, 3, 4): ";
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
    cout << "������ ����� ��������� ��� ���������: ";
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
            cout << "\n����� ��������\n";
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
    cout << "������ ����� ��������� ��� �����������: ";
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