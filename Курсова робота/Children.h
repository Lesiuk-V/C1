#pragma once
#include "Human.h"
enum Group
{
	first,
	second
};
class Children : public Human
{
private:
	Group group;
	int Number_Doc;
public:
	void setGroup(int);
	int getNumberDoc();
	virtual Group getGroup();
	virtual void create() override;
};

