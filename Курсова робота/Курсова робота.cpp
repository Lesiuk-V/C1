#include <iostream>
#include <Windows.h>
#include "Children.h"
#include "Parent.h"
using namespace std;
int main()
{
	system("chcp 1251 >nul");
	Children ch;
	ch.setGroup(2);
	cout<<ch.getGroup()+1;
}
