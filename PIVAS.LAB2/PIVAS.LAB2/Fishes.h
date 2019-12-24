#pragma once
#include "animals.h"

using namespace zoo;

class Fishes :
	protected virtual Animals
{
protected:
	bool isSwimmingNow = 0, isPredator = 0, dangerous;
public:
	Fishes();//
	~Fishes();
	Fishes(std::string, bool);//
	void setDangerous(bool);//
	std::string isDangerous();//
	void swim(bool);//
	void swimmnig(double, double, double);//
	void NameAnimal();//
	void getHunger();//
	std::string IsPredator();//
	void eating(std::string);//
	void die();//
};

