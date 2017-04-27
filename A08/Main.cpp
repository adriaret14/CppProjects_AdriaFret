#include <iostream>
#include <deque>
#include <vector>
#include <concurrent_priority_queue.h>


void main() {

	//DEQUES
	std::cout << "DEQUES: " << std::endl;
	//Creo la deque prices
	std::deque<float> prices(10, 10.5);
	//Cambio el ultimo valor por 32.43
	prices.pop_back();
	prices.push_back(32.43);
	//Elimino el primer valor
	prices.pop_front();
	//Asignar la deque a una nueva
	std::deque<float> prices2(prices);
	//Insertar 5.64 y 20.31 al comienzo
	prices2.push_front(5.64);
	prices2.push_front(20.31);
	//insertar 10 como segundo elemento de la segunda deque
	std::deque<float>::iterator it2 = prices2.begin();
	it2++;
	prices2.insert(it2, 10);
	//Imprimir la primera deque usando un backward iterato
	std::deque<float>::reverse_iterator rit = prices.rbegin();
	std::deque<float>::reverse_iterator itr = prices.rend();
	while (rit != itr)
		std::cout << ' ' << *rit++;
	std::cout << std::endl;
	//Imprimir la segunda deque de otra forma
	it2 = prices2.begin();
	while (it2 != prices2.end())
		std::cout << ' ' << *it2++;
	std::cout << std::endl;




	//VECTORES											//Lo normal es usar subindices
	std::cout << "VECTORS: " << std::endl;
	//Creo el vector prices
	std::vector<float> vprices(10, 10.5);
	//Cambio el ultimo valor por 32.43
	vprices[vprices.size()] = 32.43;
	//Elimino el primer valor
	std::vector<float>::iterator vit = vprices.begin();
	vprices.erase(vit);
	//Asigno el vector a uno nuevo
	std::vector<float> vprices2(vprices);
	//Inserto 5.64 y 20.31 al comienzo del segundo vector
	vprices2.insert(vprices2.begin(), 5.64);
	vprices2.insert(vprices2.begin(), 20.31);
	//insertar 10 como segundo elemento del segundo vector
	std::vector<float>::iterator vit2 = vprices2.begin() + 1;
	vprices2.insert(vit2, 10);
	//Imprimo el primer vector con un backward iterator
	std::vector<float>::reverse_iterator rvit = vprices.rbegin();
	std::vector<float>::reverse_iterator vitr = vprices.rend();
	while (rvit != vitr) {
		std::cout << " " << *rvit;
		rvit++;
	}
	std::cout << std::endl;
	//Imprimo el segundo vector de otra forma
	vit2 = vprices2.begin();
	while (vit2 != vprices2.end()) {
		std::cout << " "  << *vit2;
		vit2++;
	}


}
