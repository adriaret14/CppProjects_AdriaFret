#include <iostream>
#include <list>

std::list<int> superMerge(std::list<int> l1, std::list<int> l2)
{
	std::list<int> resultado;
	std::list<int>::iterator it1 = l1.begin();
	std::list<int>::iterator it2 = l2.begin();

	while (it1 != l1.end() || it2 != l2.end())
	{	
		if (it1 == l1.end())
		{
			resultado.push_back(*it2);
			it2++;
		}
		else if (it2 == l2.end())
		{
			resultado.push_back(*it1);
			it1++;
		}
		else
		{
			if (*it1 <= *it2)
			{
				resultado.push_back(*it1);
				it1++;
			}
			else
			{
				resultado.push_back(*it2);
				it2++;
			}
		}
		
	}

	return resultado;
}

void change(std::list<int> &l1)
{
	std::list<int>::iterator it = l1.end();
	it--;
	int n_principio = *l1.begin();
	int n_final = *it;

	l1.pop_back();
	l1.pop_front();

	l1.push_front(n_final);
	l1.push_back(n_principio);

}

int getElementPos(std::list<int> l1, int pos)
{
	std::list<int>::iterator it = l1.begin();
	advance(it, pos-1);

	return *it;
}

void removeDuplicates(std::list<int> &l1)
{
	l1.sort();
	l1.unique();
}

void removeElement(std::list<int> &l1, int num)
{
	std::list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		if (*it == num)
		{
			it = l1.erase(it);
		}
		else
		{
			it++;
		}
		
	}
}

bool palindrome(std::list<int> l1)
{
	bool flag = true;

	std::list<int>::iterator it = l1.begin();
	std::list<int>::iterator bit = l1.end();
	bit--;
	int cont = 0;

	while (cont < l1.size()) {
		if (*it != *bit)
		{
			flag = false;
			break;
		}
		cont++;
	}
	return flag;
}



void main()
{
	std::list<int> l1{7,8,10,12};
	std::list<int>l2{4,9,10};
	
	//SUPERMERGE
	std::list<int>l3;
	l3 = superMerge(l1, l2);
	std::cout << "SUPERMERGE: " << std::endl;
	for (std::list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl;

	//CHANGE
	change(l3);
	std::cout << "CHANGE: " << std::endl;
	for (std::list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl;

	//GET ELEMENT POS
	std::cout << "GET ELEMENT POS: " << std::endl;
	std::cout << getElementPos(l1, 3);
	std::cout << std::endl;

	//REMOVE ELEMENT
	removeElement(l3, 12);
	std::cout << "REMOVE ELEMENT (12): " << std::endl;
	for (std::list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl;

	removeDuplicates(l3);

	//REMOVE DUPLICATES
	std::cout << "REMOVE DUPLICATES: " << std::endl;
	for (std::list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl;

	//PALINDROMES
	std::list<int>l4{ 4,9,6,9,4 };
	std::cout << "PALINDROME: " << std::endl;
	for (std::list<int>::iterator it = l4.begin(); it != l4.end(); it++)
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl <<  palindrome(l4);;

}




