#pragma once
#include "animals.h"
using namespace zoo;
class mammals :
	protected Animals
{
protected:
	std::string whereislive;
	bool isCanSwim = 0;
	bool isCanFly = 0;
	bool isMovingNow = 0;
	bool itHaveBag;
public:
	mammals();//
	mammals(std::string, std::string, bool);//
	void WhereLive();//
	void NewPlaceToLive(std::string);//
	std::string CanItFly();//
	std::string CanItSwim();//
	void Moving(double, double, double);//
	void Movingnow(bool);//
	std::string itbag();//
};

