#include "DynArray.hh"
#include <stdlib.h>
#include <iostream>


int main() {
	DynArray a2(5, 8);
	a2.push(5);
	a2.push(5);
	a2.push(5);
	a2.push(200);

	//a2.pop();
	a2.erase(7);

	int *p2 = a2.begin();
	int *t2 = a2.end();
	std::cout << p2 << " / " << t2;

	std::cout << "\nContructor 3: \n";
	while (p2 != t2)
	{
		std::cout << *p2 << "\t";
		p2++;
	}

	std::cout << a2.size() << "\n";


	return 0;
}