#include "Reptilies.h"
#include <iostream>
#include <math.h>
using namespace zoo;

Reptilies::Reptilies() :
	isCreeps(0), isJump(0), isWalks(0), isPredator(0), temprature(0){}

Reptilies::Reptilies(std::string Name, int tempratur, bool ispredator, bool iscreeps, bool isjump, bool iswalks)
	: Animals(Name), temprature(tempratur), isPredator(ispredator), isCreeps(iscreeps), isJump(isjump), isWalks(iswalks){}

Reptilies::~Reptilies() {}

void Reptilies::setTemp(int temp) {
	temprature = temp;
	hunger -= 2;
	die();
}

void Reptilies::setPredator(bool temp) {
	isPredator = temp;
	hunger -= 2;
	die();
}

std::string Reptilies::IsPredator() {
	if (isPredator)
		return "It is a predator";
	else
		return "It's not a predator";
	hunger -= 2;
	die();
}

int Reptilies::returnTemp() {
	return temprature;
	hunger -= 2;
	die();
}

void Reptilies::NameAnimal() {
	Animals::NameAnimal();
	hunger -= 2;
	die();
}

void Reptilies::typeofmooving(bool iscreeps, bool isjump, bool iswalks) {
	isCreeps = iscreeps;
	isJump = isjump;
	isWalks = iswalks;
}

void Reptilies::mooving(double x, double y, double z) {
	if (isCreeps) {
		std::cout << "\nSsSsSs\n";
	}
	else if (isJump) {
		std::cout << "\nJump\n";
	}
	else if (isWalks) {
		std::cout << "\nSlurp\n";
	}
	Animals::moveto(x, y, z);
	hunger -= pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 0.5);
	die();
}

void Reptilies::getHunger() {
	gethunger();
}

void Reptilies::eating(std::string whatEat) {
	if (IsPredator() == "It is a predator") {
		if (whatEat == "fish" || whatEat == "bug" || whatEat == "people" || whatEat == "bird" || whatEat == "frog") {
			NameAnimal();
			std::cout << " eat " << whatEat << std::endl <<
				" degree of hunger now: ";
			gethunger();
			std::cout << "\n";
			hunger += 50;
			if (hunger > 100) {
				hunger == 100;
			}
		}
		else {
			NameAnimal();
			std::cout << " don't eat " << whatEat << std::endl;
		}
	}
	if (IsPredator() == "It's not a predator") {
		if (whatEat == "grass" || whatEat == "weed" || whatEat == "seaweed" || whatEat == "leaves") {
			NameAnimal();
			std::cout << " eat " << whatEat << std::endl <<
				" degree of hunger now: ";
			gethunger();
			std::cout << "\n";
			hunger += 50;
			if (hunger > 100) {
				hunger == 100;
			}
		}
		else {
			NameAnimal();
			std::cout << " don't eat " << whatEat << std::endl;
		}
	}
	hunger -= 2;
	die();
}

void Reptilies::die() {
	if (hunger <= 0) {
		this == NULL;
		NameAnimal();
		std::cout << " die";
	}
}