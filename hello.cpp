#include <iostream>

enum WeekDay {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

int main() {

    WeekDay today = monday;

    switch (today) {
        case friday : std::cout << true;
        break;
        default: std::cout << false;
        break;
    }

    return 0;
}