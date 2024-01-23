#include <iostream>

template <typename T>
class SmartArray
{
	template <typename T1>
	friend std::ostream& operator<<(std::ostream& out, const SmartArray<T1>& other);
private:
	T* sa_arr;
	unsigned sa_size;
public:
	SmartArray(const T* arr, int size)
		: sa_size(size)
	{
		sa_arr = new T[size];
		for (int i = 0; i < size; ++i)
			sa_arr[i] = arr[i];
		std::cout << "Smart array object created\n";
	}
	SmartArray()
		: SmartArray(nullptr, 0) 
	{}
	SmartArray(const SmartArray& other)
	{
		if (this != &other)
		{
			delete[] sa_arr;
			sa_size = other.sa_size;
			sa_arr = new T[sa_size];
			for (int i = 0; i < sa_size; ++i)
				sa_arr[i] = other.sa_arr[i];
			std::cout << "Copy operator for SmarArray\n";
		}
		else
			std::cout << "Copy operator for SmarArray ERROR\n";
	}
	~SmartArray()
	{
		delete[] sa_arr;
		sa_size = 0;
		std::cout << "SmartArray object has been deleted\n";
	}
	SmartArray& operator=(const SmartArray& other)
	{
		if (this != &other)
		{
			std::cout << "operator= called\n";
			sa_size = other.sa_size;
			delete[] sa_arr;
			sa_arr = new T[sa_size];
			for (int i = 0; i < sa_size; ++i)
				sa_arr[i] = other.sa_arr[i];
		}
		else
			std::cout << "ERROR IN operator=\n";
		return *this;
	}
	const T* getArr() const { return sa_arr; }
	int getSize() const { return sa_size; }
};

template <typename T1>
std::ostream& operator<<(std::ostream& out, const SmartArray<T1>& other)
{
	for (int i = 0; i < other.getSize(); ++i)
		out << other.getArr()[i] << ' ';
	out << '\n';
	return out;
}
