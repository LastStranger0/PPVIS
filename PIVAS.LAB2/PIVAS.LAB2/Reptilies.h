#pragma once
#include "animals.h"
#include <string>
using namespace zoo;

class Reptilies :
	private Animals
{
private:
	int temprature;
	bool isCreeps, isJump, isWalks, isPredator, isMooving = false;
public:
	Reptilies();
	~Reptilies();
	Reptilies(std::string, int, bool, bool, bool, bool);
	void setTemp(int);
	void setPredator(bool);//
	void getHunger();//
	std::string IsPredator();//
	void NameAnimal();
	int returnTemp();
	void mooving(double, double, double);
	void typeofmooving(bool, bool, bool);
	void eating(std::string);//
	void die();//
};

