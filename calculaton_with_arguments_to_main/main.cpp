#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Expected 3 parameters. Received " << argc - 1 << std::endl;
		return 0;
	}
	else
	{
		double first_operand = atof(argv[1]);
		double second_operand = atof(argv[3]);

		if (first_operand == 0. or second_operand == 0.)
		{
			std::cerr << "Operands should be non zero!\n";
			return 0;
		}
			
		char operation = *argv[2];

		if (operation == '+' or operation == '-' or operation == '/' or operation == '*')
		{
			std::cout << first_operand << ' ' << operation << ' ' << second_operand << " = ";
			switch (operation)
			{
			case '+': 
				std::cout << first_operand + second_operand;
				break;
			case '-': 
				std::cout << first_operand - second_operand;
				break;
			case '/': 
				std::cout << first_operand / second_operand;
				break;
			case '*': 
				std::cout << first_operand * second_operand;
				break;
			default:
				break;
			}
		}
		else
		{
			std::cerr << "Invalid operation!\n";
		}
		return 0;
	}
}
