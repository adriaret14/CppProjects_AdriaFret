#include <iostream>
#include <string>
#include <ctime>

enum class Weapon { FISTS, GUN, SHOTGUN, REVOLVER, SNIPER, MACHINE_GUN, MAX };

class Zombie;

class Player {
public:
	Player(Weapon arma, float precision, int life) {};
	Player() {
	this->arma=static_cast<Weapon>(rand() % static_cast<int>(Weapon::MAX));
	this->life = 100;
	this->precision =MIN_PREC + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (MAX_PREC - MIN_PREC)));
	};

	Weapon arma;
	float precision;
	int life;

	const int MAX_LIFE = 100;
	const float MIN_PREC = 0.1;
	const float MAX_PREC = 1.9;


	void attack(Zombie &);

	bool isAlive() {
		return (life > 0);
	}
};

class Zombie {
public:
	Zombie(int distancetoplayer, float speed, float dmg, int life) {};
	Zombie() {
		this->distancetoplayer = rand() % MAX_DIST + MIN_DIST;
		this->speed= MIN_SPEED + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (MAX_SPEED - MIN_SPEED)));
		this->dmg = MIN_DMG + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (MAX_DMG - MIN_DMG)));
		this->life = 100;
	};

	int distancetoplayer;
	float speed;
	float dmg;
	int life;

	const int MIN_DIST = 20;
	const int MAX_DIST = 200;
	const float MIN_SPEED = 0.1;
	const float MAX_SPEED = 20.9;
	const float MIN_DMG = 0.1;
	const float MAX_DMG = 20.9;
	const int MAX_HP = 100;
	

	void attack(Player &p) {
		
	}

	bool isAlive() {
		return (life > 0);
	}

};

void Player::attack(Zombie &z) {
	z.life = z.life - (static_cast<int>(this->arma)*this->precision);
}

int main() {

	srand(static_cast<unsigned>(time(nullptr)));

	const int MAX_Z = 10;

	//Zombie z1, z2, z3, z4, z5, z6, z7, z8, z9, z10;
	//Zombie lista_z[10]{ z1, z2, z3, z4, z5, z6, z7, z8, z9, z10 };
	Player p1;
	Zombie* lista_z[MAX_Z];

	int cont = 0;
	std::string nombre;

	while (cont < MAX_Z) {
		lista_z[cont] = new Zombie();
		cont++;

	}

	do {

	}while(p1.isAlive() && )

	std::cout << lista_z[2]->life;	
	p1.attack(*lista_z[2]);
	std::cout << lista_z[2]->life;


	return 0;
}