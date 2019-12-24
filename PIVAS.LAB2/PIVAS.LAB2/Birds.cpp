#include "Birds.h"
#include <iostream>
#include <math.h>>
using namespace zoo;

Birds::Birds() : Animals()
{}

Birds::Birds(std::string animal, bool isCanFly) : isCanFly(isCanFly), Animals(animal)
{}

Birds::~Birds() {

}

void Birds::NameAnimal() {
	Animals::NameAnimal();
}

void Birds::setIsCanFly(bool isCan) {
	isCanFly = isCan;
	hunger -= 2;
	die();
}

std::string Birds::getIsCanFly() {
	if (isCanFly) {
		return "Can fly";
	}
	else {
		return "can't fly";
	}
	hunger -= 2;
	die();
}

void Birds::fly(bool temp) {
	isFlyingNow = temp;
	hunger -= 2;
	die();
}

void Birds::Flying(double x1, double y1, double z1) {
	moveto(x1, y1, z1);
	hunger -= pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 0.5);
	die();
}

void Birds::hung(std::string WhatEat) {
	NameAnimal();
	std::cout << " eat " << WhatEat << '\n';
	hunger += 50;
	if (hunger > 100) {
		hunger == 100;
	}
	die();
}

void Birds::die() {
	if (hunger <= 0) {
		this == NULL;
		NameAnimal();
		std::cout << " die";
	}
}