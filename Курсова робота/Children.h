#pragma once
#include "Human.h"
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
	Group group;
	int number_Doc;
public:
	void setGroup(int gr);
	int getNumberDoc();
	Group getGroup();
	virtual void create() override;
	void read(int pn);
	void write();
	void count();
	void deleteData();
	void edit();
};

