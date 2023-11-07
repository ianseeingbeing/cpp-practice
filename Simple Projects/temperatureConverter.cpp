#include <iostream>
#include <cctype>

int main() {

    double temperature;
    char unit;
    char convertUnit;
    double result;

    std::cout << "Temperature: ";
    std::cin >> temperature;

    std::cout << "Unit (F or C): ";
    std::cin >> unit;

    if (unit == 'F' || unit == 'f') {
        result = (temperature - 32) * 5/9;
        convertUnit = 'C';
    }
    if (unit == 'C' || unit == 'c') {
        result = (temperature * 9/5) + 32;
        convertUnit = 'F';
    }

    std::cout << temperature << " degrees " << unit << " is " << result << " degrees " << convertUnit << std::endl;
    return 0;
}