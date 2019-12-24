#pragma once
#include "mammals.h"
#include "Fishes.h"

using namespace zoo;

class mammalsfish :
	private mammals, private Fishes
{
protected:
	std::string WhatEats;
	std::string Sound;
public:
	mammalsfish();
	mammalsfish(std::string animal, std::string wherelive, bool isDangerous, bool itHaveBag);
	void setWhatEats(std::string);
	std::string getWhatEats();
	void setSound(std::string);//
	std::string getSound();//
	void Moving(double, double, double);//
	void Move(bool);//
};

