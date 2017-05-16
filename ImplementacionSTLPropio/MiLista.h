#pragma once
class MiLista
{
public:
	MiLista();
	MiLista(MiLista &);
	~MiLista();

	struct node {
		int info;
		node* next;
		node* previous;
	};
	node* last;
	node* frst;


	void push_front(int);
	void push_back(int);
	void pop_front();
	void pop_back();
	int& first();
	int& back();
	int Getsize();
	bool isEmpty();

private:
	int size;

};

