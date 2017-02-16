#include <iostream>
#include <string>
#include <time.h> 

using namespace std;

enum class EnemyType { zombie, vampire, ghost, witch };
//EnemyType tipo;

typedef struct Enemy {
	EnemyType clase;
	string name;
	int health;
}enemigo;

Enemy CreateRandomEnemy() {

	Enemy enemigo;
	//EnemyType tipo;
	string nombres[10] = { "Kang", "Yong", "Yoo", "Varian", "Celestino", "Guldan", "Hoger", "Taylor", "Segri", "Zeittan" };

	srand(time(NULL));

	enemigo.name= nombres[rand() % 10 + 0];
	enemigo.health=rand() % 150 + 1;
	enemigo.clase = static_cast<EnemyType>(rand() % 4);
	//enemigo.clase = tipo(rand() % 4);

	return enemigo;
}

string GetEnemyTypeString(EnemyType tipo) {
	string salida;

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
}


int main() {

	Enemy enemigo1 = CreateRandomEnemy();
	Enemy enemigo2 = CreateRandomEnemy();
	Enemy enemigo3 = CreateRandomEnemy();
	Enemy enemigo4 = CreateRandomEnemy();
	Enemy enemigo5 = CreateRandomEnemy();

	cout << GetEnemyTypeString(enemigo1.clase);


	//cout << static_cast<int>(enemigo.type);
	

	return 0;
}

