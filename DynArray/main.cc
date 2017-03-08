#include "DynArray.hh"
#include <stdlib.h>
#include <iostream>


int main() {
	DynArray a1;
	DynArray a2(35, 14);
	
	int *p = a1.begin();
	int *t = a1.end();

	int *p2 = a2.begin();
	int *t2 = a2.end();
	std::cout << p << " / " << t;
	std::cout << "\n";
	std::cout << p2 << " / " << t2;
	std::cout << "Contructor 1: \n";
	while (p != t)
	{
		std::cout << *p << "\t";
		p++;
	}

	std::cout << "\nContructor 3: \n";
	while (p2 != t2)
	{
		std::cout << *p2 << "\t";
		p2++;
	}

	std::cout << "\nRelleno el 1 con 9: \n";

	std::cout << a2.size();
	return 0;
}