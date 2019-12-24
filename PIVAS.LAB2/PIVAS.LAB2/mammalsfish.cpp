#include "mammalsfish.h"
#include <iostream>

using namespace zoo;

mammalsfish::mammalsfish() : mammals(), Fishes()
{}

mammalsfish::mammalsfish(std::string animal, std::string wherelive, bool isDangerous, bool itHaveBag) : mammals(animal, wherelive, itHaveBag), Fishes(animal, isDangerous)
{}

void mammalsfish::setSound(std::string sound) {
	Sound = sound;
}

std::string mammalsfish::getSound() {
	return Sound;
}

void mammalsfish::Move(bool temp) {
	isMovingNow = temp;
}

void mammalsfish::Moving(double x, double y, double z) {
	Animals::moveto(x, y, z);
}

void mammalsfish::setWhatEats(std::string whatEats) {
	WhatEats = whatEats;
}

std::string mammalsfish::getWhatEats() {
	return WhatEats;
}