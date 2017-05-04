#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <deque>

void main() {
	std::stack<int> s1;
	std::stack<int> s2;

	s1.push(1);
	s1.push(3);
	s1.push(4);
	s1.push(6);

	s2.push(2);
	s2.push(3);
	s2.push(5);
	s2.push(9);

	std::stack<int> s3 = superMerge(s1, s2);
	std::cout << s3.top();


}



std::stack<int> superMerge(std::stack<int> a, std::stack<int> b)
{
	std::stack<int> resultado;
	std::vector<int> aux;
	int cont = 0;

	while (a.size() > 0 || b.size() > 0)
	{
		if (a.size() == 0) {
			resultado.push(b.top());
			b.pop();
		}
		else if (b.size() == 0) {
			resultado.push(a.top());
			a.pop();
		}
		else {
			if (a.top() > b.top())
			{
				resultado.push(a.top());
				a.pop();
			}
			else if (a.top() == b.top())
			{
				resultado.push(a.top());
				resultado.push(b.top());
				a.pop();
				b.pop();
			}
			else {
				resultado.push(b.top());
				b.pop();
			}
		}
		
	}

	while (resultado.size() > 0)
	{
		aux[cont] = resultado.top();
		resultado.pop();
		cont++;
	}
	while (cont > 0)
	{
		resultado.push(aux[cont]);
		cont--;
	}

	return resultado;
}



std::stack<int> putHat(std::stack<int> a, std::stack<int> b)
{
	std::stack<int> resultado;
	std::vector<int> v1;
	std::vector<int> v2;

	int cont = 0;
	int cont2 = 0;

	while (b.size() > 0)
	{
		v1[cont] = b.top();
		b.pop();
		cont++;
	}

	while (a.size() > 0)
	{
		v2[cont2] = a.top();
		a.pop();
		cont2++;
	}

	while (cont > 0)
	{
		resultado.push(v1[cont]);
		cont--;
	}

	while (cont2 > 0)
	{
		resultado.push(v2[cont2]);
		cont2--;
	}

	return resultado;
}



std::deque<int> transformToQ(std::stack<int> a)
{
	std::deque<int> cola;

	while (a.size() > 0)
	{
		cola.push_back(a.top());
		a.pop();
	}

	return cola;
}


bool isHat(std::stack<int> a, std::stack<int> b)
{
	std::deque<int> cola;

	while (a.size() > 0)
	{
		cola.push_back(a.top());
		a.pop();
	}

	int flag = 0;
	for (auto it = cola.begin(); it < cola.end(); it++)
	{
		if (*it != b.top())
		{
			flag = 1;
			break;
		}
		else {
			b.pop();
		}
	}

	if (flag == 0) {
		return true;
	}
	else {
		return false;
	}
}



void change(std::stack<int> &a)
{
	std::deque<int> cola;
	while (a.size() > 0)
	{
		cola.push_back(a.top());
		a.pop();
	}

	int aux1 = *cola.begin();
	int aux2= *cola.end();

	cola.pop_back();
	cola.pop_front();

	cola.push_back(aux1);
	cola.push_front(aux2);

	for (auto it = cola.begin(); it < cola.end(); it++) {
		a.push(*it);
	}
}