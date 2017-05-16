#include "MiLista.h"



MiLista::MiLista() :
	last(nullptr),
	frst(nullptr),
	size(0)
{
}


MiLista::MiLista(MiLista &lista)
{
	node* aux =nullptr;
	node* aux2 = nullptr;
	int sizeAux = 0;
	size = lista.Getsize();

	if (lista.frst == nullptr)
	{
		frst = nullptr;
		last = nullptr;
		size = 0;
	}
	else {
		frst = new node{lista.frst->info, nullptr, nullptr};
		aux = frst;
		lista.frst = lista.frst->next;
		while (lista.frst->next!=nullptr) {
			aux2 = new node{ lista.frst->info, nullptr, aux };
			aux->next = aux2;
			lista.frst = lista.frst->next;
		}
		last = aux2;
	}
}


MiLista::~MiLista()
{
}

void MiLista::push_front(int num)
{
	node* aux = frst;
	frst = new node{num, aux, nullptr};
	size++;
}

void MiLista::push_back(int num)
{
	node* aux = last;

	last = new node{num, nullptr, aux};
	size++;
}

void MiLista::pop_front()
{
	node* aux=frst->next;

	delete frst;
	frst = aux;
}

void MiLista::pop_back()
{
	node* aux = last->previous;

	delete last;
	last = aux;
}




int MiLista::Getsize()
{
	return size;
}

bool MiLista::isEmpty()
{
	return frst==nullptr;
}
