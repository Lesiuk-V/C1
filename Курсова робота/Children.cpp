#include "Children.h"
#include <iostream>
using namespace std;
void Children::create()
{
    cin.ignore(10, '\n');
    cout << "\nІм'я: "; cin >> name;
    cout << "Прізвище: "; cin >> surname;
    cout << "По батькові: "; cin >> patronymic;
    cout << "Національність: "; cin >> nationality;
    cout << "Дата народження: "; cin >> dateOfBirth;
}
int Children::getNumberDoc()
{
    return Number_Doc;
}

Group Children::getGroup()
{
    return group;
}

void Children::setGroup(int gr)
{
    if(gr == 1)
}