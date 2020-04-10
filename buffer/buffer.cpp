// buffer.cpp : 
//

#include <iostream>
#include "buffer.h"

constexpr int SIZE = 20;
int main()
{

	Int *_arr = (Int*)(operator new(sizeof(Int) * SIZE));
	for (int i = 0; i < SIZE; i++)
		new(&_arr[i]) Int(i);
	/////////////////////////////////////////////
	Int temp(-5);
	bool b = false;

	Ring<Int> * ring = new Ring<Int>(4);
	if (ring->push(_arr[1]) == false) std::cout << "add 1 false" << std::endl;
	if (ring->push(_arr[2]) == false) std::cout << "add 2 false" << std::endl;
	if (ring->push(_arr[3]) == false) std::cout << "add 3 false" << std::endl;
	if (ring->push(_arr[4]) == false) std::cout << "add 4 false" << std::endl;
	if (ring->push(_arr[5]) == false) std::cout << "add 5 false" << std::endl;
	if (ring->push(_arr[6]) == false) std::cout << "add 6 false" << std::endl;
	if (ring->push(_arr[7]) == false) std::cout << "add 7 false" << std::endl;

	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;
	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;
	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;
	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;
	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;

	if (ring->push(_arr[8]) == false) std::cout << "add 8 false" << std::endl;

	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;
	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;

	if (ring->push(_arr[9]) == false) std::cout << "add 9 false" << std::endl;
	if (ring->push(_arr[10]) == false) std::cout << "add 10 false" << std::endl;
	if (ring->push(_arr[11]) == false) std::cout << "add 11 false" << std::endl;
	if (ring->push(_arr[12]) == false) std::cout << "add 12 false" << std::endl;
	if (ring->push(_arr[13]) == false) std::cout << "add 13 false" << std::endl;
	if (ring->push(_arr[14]) == false) std::cout << "add 14 false" << std::endl;
	if (ring->push(_arr[15]) == false) std::cout << "add 15 false" << std::endl;

	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;
	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;
	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;
	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;
	if (ring->take(&temp)) temp.pr(); else { std::cout << "not read" << std::endl; }; temp.x = -5;



	/////////////////////////////////////////////
	std::cout << "finish ---------------------------------------- :" << std::endl;
	delete ring;
	/////////////////////////////////////////////
	for (int i = 0; i < SIZE; ++i)
		_arr[i].~Int();
	operator delete(_arr);
}

