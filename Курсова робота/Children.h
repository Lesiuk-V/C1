#pragma once
#include "Human.h"
#include <string>
enum Group
{
	first,
	second,
	third,
	fourth
};
class Children : public Human
{
private:
	int id;
	Group group;
	int Number_Doc;
	char dateOfExpiry[11];
	char MomName[50];
	char DadName[50];
	char MomNumber[20];
	char DadNumber[20];
public:
	int setId();
	void setGroup();
	int getNumberDoc();
	virtual Group getGroup();
	virtual void create() override;
	void read(int pn);
	void write();
	void set_date(int n);
	static int count();
	void searchName();
	void searchSurname();
	void searchDateOfBirth();
	void deleteData();
	void editData();
	void showData();
};

