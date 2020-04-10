
#pragma once
#include <iostream>

class Int {
public:
	int x;
	Int(int x = -1) :x(x) {};

	Int(Int& a) : x(a.x) {};



	Int(Int&& a)
		: x(a.x)
	{
		a.x = -99;
	};

	Int& operator=(const Int& a)
	{
		if (&a == this)
			return *this;
		x = a.x;
		return *this;
	}


	Int& operator=(Int&& a)
	{
		if (&a == this)
			return *this;
		//delete allocated
		x = a.x;
		a.x = -100;
		return *this;
	};
	~Int() { std::cout << "destructor: " << x << std::endl; }
	void pr() { std::cout << "print: " << x << std::endl; }
};