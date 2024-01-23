#include <iostream>

class Point
{
	friend Point& operator+=(Point& right, const Point& left);
private:
	double m_x;
	double m_y;
public:
	Point(double x, double y)
		: m_x(x), m_y(y) 
	{
		std::cout << "Point [" << m_x << "; " << m_y << "] has been created\n";
	}
	Point(double x) 
		: Point(x, x) {}
	Point()
		: Point(0, 0) {}
	~Point()
	{
		std::cout << "Point [" << m_x << "; " << m_y << "] has been destoyed\n";
		m_x = 0;
		m_y = 0;
	}
	explicit operator double();
	double getX() const { return m_x; }
	double getY() const { return m_y; }
	/*Point operator+(const Point& other) const
	{
		std::cout << "\toperator+ as a member function\n";
		return Point{ this->m_x + other.m_x, this->m_y + other.m_y };
	}*/
};

Point operator+(const Point& left, const Point& right)
{
	std::cout << "\toperator+ as non member and non friend function\n";
	return Point{ left.getX() + right.getX(), left.getY() + right.getY() };
}

bool operator==(const Point& left, const Point& right)
{
	bool result = (left.getX() == right.getX()) && (left.getY() == right.getY());
	std::cout << "\toperator== as non member and non friend function\n";
	return result;
}

std::ostream& operator<<(std::ostream& out, const Point& other)
{
	std::cout << "Point [" << other.getX() << "; " << other.getY() << "]\n";
	std::cout << "\toperator<< as non member and non friend function\n";
	return out;
}

Point& operator+=(Point& right, const Point& left)
{
	right.m_x += left.m_x;
	right.m_y += left.m_y;
	std::cout << "\toperator+= as friend function\n";
	return right;
}

Point::operator double()
{
	std::cout << "\toperator double() as member function\n";
	return m_x;
}

int main()
{
	system("pause");
	Point A{ 2, 3 };
	Point B{ 6, 2 };
	std::cout << "A: " << A;
	std::cout << "B: " << B;
	A += B;
	std::cout << "A: " << A;
	std::cout << "B: " << B;
	std::cout << "Point(A) + double(2.0): " << A + 2.;

	//std::cout << 2 + A; - compiler error 

	std::cout << "A: " << A;
	std::cout << "B: " << B;
	std::cout << "double(2.0) + Point(A): " << 2. + A;
	std::cout << std::boolalpha << "Point(A) + double(2.0) == double(2.0) + Point(A): " << (A + 2. == 2. + A) << std::endl;
	
	std::cout << "Point(A) += double(2.0): " << (A += 2.);
	std::cout << "A: " << A;
	std::cout << "B: " << B;

	double a = 2.;
	std::cout << "double(2.0) += static_cast<double>(Point(A)): " << (a += static_cast<double>(A)) << std::endl;
	std::cout << std::boolalpha << "Point(A) + double(2.0) == double(2.0) + Point(A): " << ((A += 2.) == (a += static_cast<double>(A))) << std::endl;

	std::cout << "\tEnd of the program\n";
	return 0;
}
