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

std::_Vector<>