#include <iostream>
#include "MiLista.h"

void main()
{
	MiLista l1;
	l1.push_front(5);
	l1.push_front(4);
	l1.push_front(8);

	l1.push_back(9);
	l1.push_back(11);

	//l1.pop_front();
	//l1.pop_back();
	
	MiLista l2(l1);


	std::cout << l2.Getsize();

	//std::cout << l1.isEmpty();

}