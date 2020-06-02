#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Children.h"
using namespace std;


void print_menu() {
    system("cls");
    cout << "          Дитячий садок\n" << endl;
    cout << "1.  додати дитину" << endl;
    cout << "2.  переглянути дітей" << endl;
    cout << "3.  пошук дітей" << endl;
    cout << "4.  видалення дитини" << endl;
    cout << "5.  редагування даних дитини" << endl;
    cout << "6.Вихід" << endl;
    cout << ">";
}
int get_variant(int count) {
    int variant;
    cin >> variant;
    if (variant > count)
    {
        cerr << "Помилка! Неправильний ввід\n";
        return 0;
    }
    return variant;
}

int main()
{
    system("chcp 1251>nul");
    int variant;
    string str;
    Children child;
    int n;
    do {
        print_menu();
        char ch;
        variant = get_variant(6);
        Children c;

        switch (variant) {
        case 1:
            do
            {
                cout << "Введіть дані дитини: ";
                child.create();
                child.write();
                cout << "Продовжити ввід?(т/н)?";
                cin >> ch;
            } while (ch == 'т');

            break;

        case 2:
            n = Children::count();
            cout << "У файлі " << n << " дітей\n";
            for (int j = 1; j < n + 1; j++)
            {
                cout << "\n Діти " << j << endl;
                child.read(j - 1);
                child.showData();
                cout << endl;
            }
            cout << endl;
            break;

        case 3:
            do
            {
                cout << "1. Пошук за іменем" << endl;
                cout << "2. Пошук за прізвищем" << endl;
                cout << "3. Пошук за датою народження" << endl;
                cout << "4. Пошук за групою" << endl;
                variant = get_variant(4);
                switch (variant)
                {
                case 1:
                    child.searchName();
                    break;

                case 2:
                    child.searchSurname();
                    break;

                case 3:
                    child.searchDateOfBirth();
                    break;
                case 4:
                    child.searchGroup();
                    break;
                }
                break;
                system("pause");
            } while (variant != 4);
            break;
        case 4:
            child.deleteData();
            break;
        case 5:
            child.editData();
            break;
        }
        if (variant != 6 || variant == 't')
            system("pause");
    } while (variant != 6);
    return 0;

}
