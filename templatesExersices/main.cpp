#include <iostream>

//1.  Create the C++ Function Template named swap so that it has two
//parameters of the same type.A Template Function created from swap
//will exchange the values of these two parameters.

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//2.  Create the C++ Function Template named multiples so that it has
//three parameters sum, x, and n.The first two parameters will have
//the type represented by the function template type parameter WhatKind.
//n will always be int.The return type is void.All parameters are
//passed by value except for sum which is passed by reference.A
//Template Function created from multiples will compute...
// 
//sum = 1 + x + 2x + 3x + ... + nx

template<typename WhatKind>
concept WhatKindFilter = requires(WhatKind a)
{
	a + a;
	a * 2;
};

template<typename WhatKind>
requires WhatKindFilter<WhatKind>
void multiples(WhatKind& sum, WhatKind x, int n)
{
	sum += 1;
	for (int i = 1; i <= n; ++i)
		sum += (i * x);
}

//3.  Create the C++ Function Template named init so that it has three
//parameters whose types are determined by the function template type
//parameters T1 and T2.The function header is shown below. init sets
//the value of the parameter start to a T2 - type value of 1.  init
//returns a T1 - type value which is the sum of num1 and num2.
// 
//T1 init(T1 num1, T1 num2, T2 & start)

template<typename T1, typename T2>
concept ThirdExersice = requires(T1 a, T2 b)
{
	b = static_cast<T2>(1);
	a + a;
};

template<typename T1, typename T2>
requires ThirdExersice<T1, T2>
T1 init(T1 num1, T1 num2, T2& start)
{
	start = static_cast<T2>(1);
	return num1 + num2;
}

int main()
{
	/*int a = 10;
	int b = -10;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	swap(a, b);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	int* ap = &a;
	int* bp = &b;

	std::cout << *ap << std::endl;
	std::cout << *bp << std::endl;

	swap(ap, bp);

	std::cout << *ap << std::endl;
	std::cout << *bp << std::endl;*/

	/*int sum = 0;

	multiples(sum, 3, 5);

	std::cout << sum << std::endl;

	//should fail
	//std::string string1{ "Hello!" };
	//std::string string2{ "Hello!" };
	//multiples(string1, string2, 2);*/

	/*int num1 = 10;
	int num2 = -10;
	double start = 100;

	std::cout << init(num1, num2, start) << ' ' << start << '\n';*/

	return 0;
}
