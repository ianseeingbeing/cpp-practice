#include <iostream>
using std::cout;

int main() {

    std::string cars[3];

    cars[0] = "Corvette";
    cars[1] = "Mustang";
    cars[2] = "Camry";


    int carsSize = sizeof(cars) / sizeof(cars[0]);
    
    // cars[0] = "Camaro";

    for (int i = 0; i < carsSize; i++) {
        cout << cars[i] << "\n";
    }

    return 0;
}