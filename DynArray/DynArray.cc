#include "DynArray.hh"

DynArray::DynArray(void) :
	m_capacity(DYN_ARRAY_DEFAULT_SIZE),
	m_size(0),
	m_data(new int[m_capacity])
{
}

DynArray::DynArray(size_t size):

	m_capacity(size),
	m_size(size),
	m_data(new int[m_capacity])

{
}

DynArray::DynArray(size_t size, const int & value):

	m_capacity(size),
	m_size(size),
	m_data(new int[m_capacity])
	
{
		/*for (int i = 0; i < static_cast<int>(size);i++) {
			m_data[i] = value;
		}*/
	fill(begin(), end(), value);
}

DynArray::DynArray(int * arr, size_t size):

	m_capacity(size),
	m_size(size),
	m_data(new int[m_capacity])
{
	for (int i = 0; i < static_cast<int>(m_size); i++)
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

	return (m_data+m_size);
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

int * DynArray::data(void) const
{
	return m_data;
}

void DynArray::push(const int & val)
{
	if (m_size < m_capacity) {
		m_data[m_size] = val;
		m_size++;
	}
	else {
		int *tmp = new int[m_capacity + 1];
		for (int i = 0; i < m_size; i++)
		{
			tmp[i] = m_data[i];
		}
		tmp[m_size] = val;
		m_size = m_size + 1;
		m_capacity = m_capacity + 1;
		delete[] m_data;
		m_data = tmp;
	}
}

void DynArray::pop(void)
{
		int *tmp = new int[m_capacity];
		for (int i = 0; i < m_size-1; i++)
		{
			tmp[i] = m_data[i];
		}
		m_size = m_size - 1;
		m_capacity = m_capacity;
		delete[] m_data;
		m_data = tmp;
}

void DynArray::erase(size_t position)
{
	int *tmp = new int[m_capacity];
	/*for (int i = 0; i < m_size; i++)
	{
		if (i != position) {
			tmp[i] = m_data[i];
		}	
	}*/
	int i = 0, y = 0;
	while (i < m_size) {
		if (y == position) {
			y++;
		}
		else {
			tmp[i] = m_data[y];
			i++;
			y++;
		}
	}
	m_size = m_size-1;
	m_capacity = m_capacity;
	delete[] m_data;
	m_data = tmp;
}

bool operator==(const DynArray & lhs, const DynArray & rhs)
{
	if (lhs.m_size == rhs.m_size) {
		int cont = 0;
		
		while (cont < static_cast<int>(lhs.m_size))
		{
			if (lhs[cont] != rhs[cont]) {
				return false;
			}
			cont++;
		}
	}
		return true;
}

bool operator!=(const DynArray & lhs, const DynArray & rhs)
{
	if (lhs.m_size == rhs.m_size) {
		int cont = 0;

		while (cont < static_cast<int>(lhs.m_size))
		{
			if (lhs[cont] == rhs[cont]) {
				return false;
			}
		}
	}
		return true;

	//return !(lhs==rhs);
}

