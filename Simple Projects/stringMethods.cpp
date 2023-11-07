#include <iostream>

int main() {

    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << name.length() << std::endl;

    std::cout << (name.empty() ? "true\n" : "false\n");

    // std::cout << name.append("@gmail.com") << std::endl;

    std::cout << name.at(0) << std::endl;

    std::cout << name.insert(0, "@") << std::endl;

    std::cout << name.find(' ') << std::endl;

    std::cout << name.erase(0, 5) << std::endl;

    return 0;
}