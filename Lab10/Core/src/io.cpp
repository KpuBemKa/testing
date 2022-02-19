#include <iostream>
#include "io.h"

int readNumber()
{
    std::cout << "Your number: ";
    int number;
    std::cin >> number;
    return number;
}

void writeAnswer(int result)
{
    std::cout << "Result is \'" << result << "\'\n";
}