#include <iostream>
#include <ctime>

int main() 
{
    std::srand(std::time(0));

    constexpr int NUMBER_OF_SUPPORTED_OPERATIONS = 4;
    constexpr char ALL_OPERATIONS[NUMBER_OF_SUPPORTED_OPERATIONS] = { '-', '+', '/', '*' };

    bool end_game = false;
    do
    {
        char operation = ALL_OPERATIONS[std::rand() % 4];

        int first_operand = std::rand() % 200;
        int second_operand;

        if (operation == '/')
            second_operand = std::rand() % 199 + 1;
        else
            second_operand = std::rand() % 200;

        std::cout << first_operand << ' ' << operation << ' ' << second_operand << " = ";

        double answer;
        switch (operation)
        {
        case '-':
            answer = first_operand - second_operand;
            break;
        case '+':
            answer = first_operand + second_operand;
            break;
        case '/':
            answer = static_cast<double>(first_operand) / static_cast<double>(second_operand);
            break;
        case '*':
            answer = first_operand * second_operand;
            break;
        default:
            break;
        }

        double attempt;
        std::cin >> attempt;

        if (attempt == answer)
            std::cout << "You're right! Congratulations!\n";
        else 
            std::cout << "You've lost! Correct answer was: " << answer << '\n';

        char do_you_want;
        std::cout << "Do you want to continue the game? (Y | N) "; std::cin >> do_you_want;

        end_game = (do_you_want == 'Y' || do_you_want == 'y') ? false : true;

    } while (!end_game);

    system("pause");
    return 0;
}
