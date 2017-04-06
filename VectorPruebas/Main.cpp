#include <vector>
#include <string>


class Person
{
public:
	Person::Person(std::string n, std::string f, std::string d):
		nombre(n),
		fecha_nacimiento(f),
		dni(d)
	{
	}

	std::string nombre;
	std::string fecha_nacimiento;
	std::string dni;
};

void main() {
		std::vector<int>v1(5);	std::vector<int>v2(10);	std::vector<int>v3{10,9,8,7,6,5,4,3,2,1};	std::vector<std::string>v4{"Gertrudiz", "Pancracia", "Anacleto", "Hipolito", "Eustaquio", "Fulgencia"};	std::vector<std::string>v5(v4);	/*Person p1("Pepe", "13-01-1995", "45454545T");	Person p2("Jordi", "22-01-1997", "45454545T");	Person p3("Josué", "04-01-1960", "45454545T");	std::vector<Person>{p1, p2, p3};*/	std::vector<Person>v6({ { "Pepe", "13-01-1995", "45454545T" },{ "Jordi", "22-01-1997", "45454545T" },{ "Josué", "04-01-1960", "45454545T" } });


}


std::vector<int> AddVectors(std::vector<int> v1, std::vector<int> v2) {
	
	std::vector<int>v3(v1.size());

	if (v1.size() == v2.size()) {
		
		
		for (int i = 0;i < v1.size();i++)
		{
			v3[i] = v1[i] + v2[i];

		}


	}
	return v3;
}

std::vector<std::string> ConcatVectors(std::vector<std::string>v1, std::vector<std::string> v2) {
	
	std::vector<std::string>v3(v1.size());

	if (v1.size() == v2.size())
	{
		
	}

	return v3;
}