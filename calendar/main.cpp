#include <iostream>
#include <iomanip>
#include <string>

int main() 
{
    int year;
    std::cout << "Enter the year: "; std::cin >> year;

    int day;
    std::cout << "Enter the first day of the year: "; std::cin >> day;

    constexpr short NUMBER_OF_MONTHS = 12;
    const std::string MONTHS_NAMES[NUMBER_OF_MONTHS] = { "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December" };

    short DAYS_IN_THE_MONTH[NUMBER_OF_MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    //Is it leap year?
    if ((year % 4 == 0 and year % 100 != 0) or (year % 100 == 0 and year % 400 == 0))
        DAYS_IN_THE_MONTH[1] = 29;

    constexpr short COLUMN_WIDHT = 6;

    std::cout << "Calendar for " << year << '\n';

    for (int i = 0; i < NUMBER_OF_MONTHS; ++i)
    {
        std::cout << std::setw(COLUMN_WIDHT * 2) << ' ' << ("--" + MONTHS_NAMES[i] + "--") << '\n';
        std::cout << std::setw(COLUMN_WIDHT) << "Mon" << std::setw(COLUMN_WIDHT) << "Tue" <<
            std::setw(COLUMN_WIDHT) << "Wed" << std::setw(COLUMN_WIDHT) << "Thu" <<
            std::setw(COLUMN_WIDHT) << "Fri" << std::setw(COLUMN_WIDHT) << "Sat" <<
            std::setw(COLUMN_WIDHT) << "Sun" << '\n';

        for (int k = 1; k <= (day %= 7); ++k)
            std::cout << std::setw(COLUMN_WIDHT) << '-';

        for (int j = 1; j <= DAYS_IN_THE_MONTH[i]; ++j)
        {
            ++day;
            if (day > 7)
            {
                day = 1;
                std::cout << '\n';
            }

            std::cout << std::setw(COLUMN_WIDHT) << j;
        }

        for (int k = day; k < 7; ++k)
            std::cout << std::setw(COLUMN_WIDHT) << '-';

        std::cout << '\n';
    }
    system("pause");
    return 0;
}
