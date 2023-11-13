#include <iostream>
#include <cmath>
#include <limits>

int numLength(const double &number);
bool luhnAlgorithm(const int numbers[], int numDigits);

//USING THE LUHN ALGORITHM TO VALIDATE THE CARD NUMBERS.

int main() {
    std::cout.precision(17);

    long double creditNum;

    std::cout << "Input Card Number to check: ";
    std::cin >> creditNum;
    
    int creditNumSize = numLength(creditNum);
    int creditNumArr[creditNumSize];

    int luhnResults[creditNumSize];

    for (int i = 0; i < creditNumSize; i++) {
        long long div = pow(10, i + 1);
        // Assings the value of each digit int the creditNum to the the respective index in the array.
        creditNumArr[(creditNumSize - 1) - i] = ((creditNum/div - floor(creditNum/div)) * 10);
    }

    bool isValid = luhnAlgorithm(creditNumArr, creditNumSize);

    if (isValid) {
        std::cout << "Card number: [" << creditNum << "] is valid USD!\n";
    }
    else {
        std::cout << "Card number: [" << creditNum << "] is not valid USD!\n";
    }

    return 0;
}

bool luhnAlgorithm(const int numbers[], int numDigits) {
    int resultArr[numDigits];
    int weight = 1;

    for (int i = numDigits - 1; i > -1; i--) {
        int temp = numbers[i] * weight;
        if (temp > 9) {
            resultArr[i] = (temp - 10) + 1;
        }
        else {
            resultArr[i] = temp;
        }
        
        weight = (weight == 1) ? 2 : 1;
    }

    int sum = 0;
    for (int num : resultArr) {
        sum += num;
    }

    return (sum % 10 == 0) ? true : false;
}

int numLength(const double &number) {
    double num = number;
    int size = 0;

    while (num / 10 > 1) {
        num /= 10;
        size++;
    }

    size++;

    return size;
}