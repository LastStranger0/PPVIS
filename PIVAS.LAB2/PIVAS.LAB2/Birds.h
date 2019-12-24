#pragma once
#include "animals.h"

using namespace zoo;

class Birds :
	public Animals
{
protected:
	bool isCanFly, isFlyingNow = false;
public:
	Birds();
	Birds(std::string, bool);
	~Birds();
	void NameAnimal();
	void setIsCanFly(bool);
	std::string getIsCanFly();
	void fly(bool);
	void Flying(double, double, double);
	void hung(std::string);
	void die();
};

