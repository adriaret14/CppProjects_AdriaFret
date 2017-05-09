#pragma once
class MyStack
{
public:
	MyStack();							//Constructor vacio
	MyStack(MyStack &);					//Constructor por copia
	MyStack(int, int);					//Nº elementos, elemento de inicializacion
	~MyStack();							//Destructor

	struct node {						//Struct del stack
		int info;
		node* next;
	};

	node* s;							//Puntero que apunta a la primera posicion del stack

	void pop();							//Eliminar el primero del stack
	void push(int);						//Pushear al principio del stack
	int top();							//Devuelve el primer elemento del stack
	int size();							//REtornar el tamaño del stack
	bool isEmpty();						//Comprobar si el stack esta vacio
};

