#include "MyStack.h"



MyStack::MyStack():
	s(nullptr)
{
}

MyStack::MyStack(MyStack &ms)
{
	if (ms.s != nullptr) {
		node* aux = ms.s;
		node* aux2 = nullptr;;
		while (aux->next != nullptr)
		{
			s = new node{ aux->info, aux2  };
			aux2 = s;
		}
	}
}


MyStack::~MyStack()
{
}

void MyStack::pop()
{
	node* aux = s->next;
	delete s;
	s = aux;
}

void MyStack::push(int inf)
{
	node* n = new node{ inf, s };
	s = n;
}

int MyStack::top()
{
	return s->info;
}

int MyStack::size()
{
	int cont = 0;
	node* aux = s;
	while (aux->next != nullptr)
	{
		cont++;
		aux = aux->next;
	}
	return cont;
}

bool MyStack::isEmpty()
{
	return s==nullptr;
}
