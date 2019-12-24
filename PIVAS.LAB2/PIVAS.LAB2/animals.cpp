#include "animals.h"
#include <iostream>

using namespace zoo;

Animals::Animals() : nameAnimal("Unknown") {
}

Animals::Animals(std::string name) : nameAnimal(name) {
}

Animals::~Animals() {

}

void Animals::NameAnimal() {
	std::cout << "Animal name: " << nameAnimal << std::endl;
}

void Animals::moveto(double x1, double y1, double z1) {
	x += x1;
	y += y1;
	z += z1;
}

void Animals::gethunger() {
	std::cout << hunger;
}