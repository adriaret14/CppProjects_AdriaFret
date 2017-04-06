#include <vector>
#include <map>
#include <string>
#include <iostream>

void main() {
	std::string nombre;
	int punt;

	std::map<std::string, int>m1;
	std::map<std::string, int>::const_iterator it;


	m1.insert(std::pair<std::string, int>("Antoine", 2));
	m1.insert(std::pair<std::string, int>("Claire", 8));
	m1.insert(std::pair<std::string, int>("Chloe", 2));
	m1.insert(std::pair<std::string, int>("Jerome", 3));

	std::cout << "Inserta tu nombre: \n";
	std::cin >> nombre;
	std::cout << "Inserta tu puntuacion: \n";
	std::cin >> punt;
	m1.insert(std::pair<std::string, int>(nombre, punt));


	
	it = m1.begin();
	int mayor = it->second;
	int imp = 0;
	it++;
	while (it != m1.end()) {
		//std::cout << it->first << " // " << it->second << std::endl;
		if (it->second > mayor) {
			mayor = it->second;
		}
		it++;
	}

	
	while (imp<m1.size())
	{
		it = m1.begin();
		while (it != m1.end()) {
			if (it->second == mayor)
			{
				std::cout << it->first << " // " << it->second << std::endl;
				imp++;
			}
			it++;
		}
		mayor--;
	}

	//std::cout << m1["Adria"];

}