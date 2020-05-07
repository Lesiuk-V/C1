#include "Children.h"
#include <iostream>
#include <fstream>
using namespace std;
void Children::create()
{
    cin.ignore(10, '\n');
    cout << "\nІм'я: "; cin >> name;
    cout << "Прізвище: "; cin >> surname;
    cout << "По батькові: "; cin >> patronymic;
    cout << "Дата народження: "; cin >> dateOfBirth;
    cout << "Номер свідоцтва про народження: "; cin >> number_Doc;
}
int Children::getNumberDoc()
{
    return number_Doc;
}

Group Children::getGroup()
{
    return group;
}

//void Children::setGroup(int gr)
//{
//    if(gr == 1)
//}

void Children::read(int pn)
{
    ifstream ifile;
    ifile.open("Children.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    ifile.seekg(pn * sizeof(Children));
    ifile.read((char*)this, sizeof(*this));
    ifile.close();
}

void Children::setGroup(int gr)
{
    int g;
    cout << "Група: 1, 2, 3, 4\n";
    for (;;) {
        cin >> g;
        if (g != 1 &&
            g != 2 &&
            g != 3 &&
            g != 4) cout << "Неправильний ввід! Спробуйте ще раз\n";
        else {
            switch (g)
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

            break;
        }
    }
}