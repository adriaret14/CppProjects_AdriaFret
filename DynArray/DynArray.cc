#include "DynArray.hh"

DynArray::DynArray(void) {
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_size = 0;
	m_data = new int[m_capacity];

}

DynArray::DynArray(size_t size)
{
	m_capacity = size;
	m_size = size;
	m_data = new int[m_capacity];
}

DynArray::DynArray(size_t size, const int & value)
{
	m_capacity = size;
	m_size = size;
	m_data = new int[m_capacity];
	for (int i = 0; i < static_cast<int>(size);i++) {
		m_data[i] = value;
	}
}

DynArray::DynArray(int * arr, size_t size)
{
	m_capacity = size;
	m_size = size;
	m_data = new int[m_capacity];

	//Recorrerla con punteros sería mejor?

	for (int i = 0; i < sizeof(arr)/4; i++)
	{
		m_data[i] = arr[i];
	}
}

DynArray::~DynArray(void)
{
	delete[] m_data;
}

int * DynArray::begin(void) const
{
	
	return m_data;
}

int * DynArray::end(void) const
{

	return (m_data+m_capacity);
}



void DynArray::fill(int * first, int * last, int value)
{
	int *p = first;

	while (p != last)
	{
		*p = value;
		p++;
	}
}

void DynArray::copy(int * first, int * last, int * dest)
{
	int *p = first;
	while (p != last) {
		*dest = *p;
		p++;
		dest++;
	}
}


bool DynArray::empty(void) const
{
	return (m_size>0);
}

size_t DynArray::capacity(void) const
{
	return m_capacity;
}

size_t DynArray::size(void) const
{
	return m_size;
}

size_t DynArray::maxSize(void)
{
	return DYN_ARRAY_MAX_SIZE;
}

int & DynArray::operator[](size_t n) const
{
	// TODO: insert return statement here
	//int &p=m_data[n];

	return m_data[n];
}

int & DynArray::at(size_t n) const
{
	// TODO: insert return statement here
	return m_data[n];
}

int & DynArray::front(void) const
{
	// TODO: insert return statement here
	return m_data[0];
}

int & DynArray::back(void) const
{
	// TODO: insert return statement here
	return m_data[m_size - 1];
}

bool operator==(const DynArray & lhs, const DynArray & rhs)
{
	if (lhs.m_size == rhs.m_size) {
		//Tienen longitud igual
		int cont = 0;
		while (cont < static_cast<int>(lhs.m_size))
		{
			if (lhs[cont] == rhs[cont]) {
				return true;
			}
		}
	}

	return false;
}
