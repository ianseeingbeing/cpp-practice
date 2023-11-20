#include <iostream>

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int mult(int x, int y) {
    return x * y;
}
void printArr(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << std::endl;
    }
}