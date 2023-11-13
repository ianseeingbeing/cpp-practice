#include <iostream>
#include <cmath>
#include <limits>

bool luhnAlgorithm(const std::string numberStr);

//USING THE LUHN ALGORITHM TO VALIDATE THE CARD NUMBERS.

int main() {
    std::cout.precision(17);

    std::string creditNum;

    std::cout << "Input Card Number to check: ";
    std::cin >> creditNum;

    bool isValid = luhnAlgorithm(creditNum);

    if (isValid) {
        std::cout << "Card number: [" << creditNum << "] is valid USD!\n";
    }
    else {
        std::cout << "Card number: [" << creditNum << "] is not valid USD!\n";
    }

    return 0;
}

bool luhnAlgorithm(const std::string numberStr) {
    std::string resultStr = "";
    int weight = 1;

    for (int i = numDigits - 1; i > -1; i--) {
        int temp = (int)(numberStr[i] - '0') * weight;

        if (temp > 9) {
            result += (temp % 10) + 1;
        }
        else {
            result = temp;
        }
        
        weight = (weight == 1) ? 2 : 1;
    }

    int sum = 0;
    for (int num : resultStr) {
        sum += num - '0';
    }

    std::cout << sum << std::endl;

    return (sum % 10 == 0) ? true : false;
}