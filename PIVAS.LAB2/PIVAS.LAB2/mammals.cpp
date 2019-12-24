#include "mammals.h"
#include<iostream>

using namespace zoo;

mammals::mammals() : isCanFly(0), isCanSwim(0), whereislive("Unknown"), Animals() {}

mammals::mammals(std::string Name, std::string Whereitlive, bool Bag) : 
	Animals(Name), itHaveBag(Bag), whereislive(Whereitlive) {}

void mammals::WhereLive() {
	std::cout << " it live in " << whereislive;
}

void mammals::NewPlaceToLive(std::string newplace) {
	whereislive = newplace;
}

std::string mammals::CanItFly() {
	if (isCanFly) {
		return "it can fly";
	}
	else {
		return "it can't fly";
	}
}

std::string mammals::CanItSwim() {
	if (isCanSwim) {
		return "it can swim";
	}
	else {
		return "it can't swim";
	}
}

void mammals::Movingnow(bool temp) {
	isMovingNow = temp;
}

void mammals::Moving(double x, double y, double z) {
	moveto(x, y, z);
}

std::string mammals::itbag() {
	if (itHaveBag)
		return "it is a marsupial";
	else
		return "it's not a marsupial";
}
