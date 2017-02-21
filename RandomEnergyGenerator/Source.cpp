#include <iostream>
#include <string>
#include <time.h> 

//Usar el namespace std es una mala practica.
//using namespace std;


//Enum class crea constantes definidas solo dentro del scope del enum; Poner un max dentro del enum nos servirá para ahorrarnos el magicnum del maximo de constantes del enum
enum class EnemyType { zombie, vampire, ghost, witch, max };


typedef struct Enemy {
	EnemyType clase;
	std::string name;
	int health;

	std::string GetEnemyTypeString() {
		switch (clase) {
		case EnemyType::zombie:
			return "zombie";
		case EnemyType::vampire:
			return "vampire";
		case EnemyType::ghost:
			return "ghost";
		case EnemyType::witch:
			return "witch";
		default: return "";
		}

	}


}enemigo;


//Redefinimos un operador, haciendolo overload(sobrecargado)
//Vamos a pedir la entrada de valores por referencia para que no haga copias y ocupar menos espacio y a la vez usaremos la palabra const para asegurarnos que solo son parámetros de entrada
//Recuerda que por referencia es entrada y salida, pasando solo la dir de memoria mientras que por valor es solo entrada y te da una copia de la variable
bool operator==(const Enemy &e1, const Enemy &e2) {
	return e1.clase == e2.clase && e1.name == e2.name;
}



Enemy CreateRandomEnemy() {

	Enemy enemigo;

	//Creamos las constantes necesarias de control
	const int MAX_LIFE = 250;
	const std::string nombres[] = { "Kang", "Yong", "Yoo", "Varian", "Celestino", "Guldan", "Hoger", "Taylor", "Segri", "Zeittan" };


	//El srand como es la semilla para el random la llamamos en el main y solo una vez
	//srand(time(NULL));
	//srand(static_cast<unsigned>(time(nullptr)));

	enemigo.name= nombres[rand() % (sizeof nombres/sizeof std::string) + 0];
	enemigo.health=rand() % MAX_LIFE + 1;
	enemigo.clase = static_cast<EnemyType>(rand() % 4);

	return enemigo;
}

/*std::string GetEnemyTypeString(EnemyType tipo) {
	std::string salida;

	switch (tipo) {
	case EnemyType::zombie:
		salida = "zombie";
		break;
	case EnemyType::vampire:
		salida = "vampire";
		break;
	case EnemyType::ghost:
		salida = "ghost";
		break;
	case EnemyType::witch:
		salida = "witch";
		break;
	}

	return salida;
}*/


int main() {
	
	
	srand(static_cast<unsigned>(time(nullptr)));


	Enemy enemigo1 = CreateRandomEnemy();
	Enemy enemigo2 = CreateRandomEnemy();
	Enemy enemigo3 = CreateRandomEnemy();
	Enemy enemigo4 = CreateRandomEnemy();
	Enemy enemigo5 = CreateRandomEnemy();

	//std::cout << GetEnemyTypeString(enemigo1.clase);

	Enemy lista[5] = {enemigo1, enemigo2, enemigo3, enemigo4, enemigo5};


	//std::cout << static_cast<int>(enemigo.type);


	//Falta mirar que los elementos de la array sean distintos

	//Printamos la lista de enemigos 
	for (auto &Enemy : lista)
	{
		std::cout << Enemy.name << " es un " << Enemy.GetEnemyTypeString() << " con vida " << Enemy.health << "\n";
	}
	

	return 0;
}

