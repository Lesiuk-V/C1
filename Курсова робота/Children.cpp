#include "Children.h"
#include <iostream>
using namespace std;
void Children::create()
{
    cin.ignore(10, '\n');
    cout << "\n��'�: "; cin >> name;
    cout << "�������: "; cin >> surname;
    cout << "�� �������: "; cin >> patronymic;
    cout << "�������������: "; cin >> nationality;
    cout << "���� ����������: "; cin >> dateOfBirth;
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