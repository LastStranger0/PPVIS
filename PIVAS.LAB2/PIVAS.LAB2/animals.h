#pragma once
#include <string>

namespace zoo {
	class Animals
	{
	public:
		Animals();
		~Animals();
		Animals(std::string);
		void virtual moveto(double, double, double);
		void virtual NameAnimal();
		void virtual gethunger();
	protected:
		std::string nameAnimal;
		int hunger = 100;
		double x=0, y=0, z=0;
	};
}