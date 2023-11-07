#include <iostream>
#include <ctime>
#include <printf.h>

int main() {
    
    int num;
    int guess;
    int tries = 0;

    srand(time(NULL));

    num = (rand() % 100) + 1;

    do {
        std::cout << "Guess the Number (1 to 100): ";
        std::cin >> guess;
        tries++;
        if(num == guess) {
            break;
        }
        else {
            num > guess ? std::cout << "Too Low.\n" : std::cout << "Too High.\n";
        } 
    } while (guess != num);

    std::cout << "You Guessed Correct!\n";
    std::cout << "Number of Tries: " << tries << "\n";
    
    return 0;
}