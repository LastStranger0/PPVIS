#include <iostream>
#include <string>
#include "Birds.h"
#include "Fishes.h"
#include "mammals.h"
#include "mammalsfish.h"
#include "Reptilies.h"

using namespace std;

int main()
{
	string temp;
	int t;
	Birds pigeon("pigeon", 1);
	pigeon.NameAnimal();
	pigeon.setIsCanFly(0);
	temp = pigeon.getIsCanFly();
	cout << "\t" << temp << endl;
	pigeon.Flying(100.2, -25.4, 73.8);
	mammalsfish whale("Whale", "water", 0, 0);
	whale.setSound("Shhhhhhh");
	whale.setWhatEats("plankton");
	temp = whale.getWhatEats();
	cout << "\t" << temp << endl;
	temp = whale.getSound();
	cout << "\t" << temp << endl;
	whale.Moving(27.3, 38.5, -23.7);
	mammals people("People", "everywhere", 0);
	temp  = people.itbag();
	cout << "\t" << temp << endl;
	people.WhereLive();
	Fishes pike("pike", 5463);
	pike.swimmnig(10.3, 43.5, 53.6);

	pike.eating("meat");
}