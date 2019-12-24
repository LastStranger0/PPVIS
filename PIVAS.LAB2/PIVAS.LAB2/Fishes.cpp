#include "Fishes.h"
#include <iostream>
#include <math.h>
Fishes::Fishes(): Animals(), dangerous(0), isPredator(0){}

Fishes::Fishes(std::string Name, bool isDanger) : Animals(Name), dangerous(isDanger){
	if (dangerous == 1) isPredator = 1;
	if (isPredator == 0) dangerous = 0;
}

Fishes::~Fishes() {

}

void Fishes::NameAnimal() {
	Animals::NameAnimal();
	hunger -= 2;
}

void Fishes::setDangerous(bool temp) {
	dangerous = temp;
	if (dangerous == 1) isPredator = 1;
}

std::string Fishes::isDangerous() {
	if (dangerous)
		return "is dangerous";
	else
		return "isn't dangerous";
	hunger -= 2;
}

std::string Fishes::IsPredator() {
	if (isPredator)
		return "It is a predator";
	else
		return "It's not a predator";
	hunger -= 2;
}

void Fishes::swim(bool temp) {
	isSwimmingNow = temp;
}

void Fishes::swimmnig(double x, double y, double z) {
	Animals::moveto(x, y, z);
	hunger -= pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 0.5);
	die();
}

void Fishes::getHunger() {
	gethunger();
}

void Fishes::eating(std::string whatEat) {
	if (IsPredator() == "It is a predator") {
		if (whatEat == "fish" || whatEat == "meat" || whatEat == "people" || whatEat == "bird" || whatEat == "frog") {
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
		else{
			NameAnimal();
			std::cout << " don't eat " << whatEat << std::endl;
		}
	}
	if (IsPredator() == "It's not a predator") {
		if (whatEat == "grass" || whatEat == "plankton" || whatEat == "weed" || whatEat == "seaweed" || whatEat == "leaves") {
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

void Fishes::die() {
	if (hunger <= 0) {
		this == NULL;
		NameAnimal();
		std::cout << " die";
	}
}