#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cctype>

void showBalance(std::string username, double balance);
double depositMoney(std::string username, double balance);
double withdrawMoney(std::string username, double balance);

int main() {

    double balance;
    int select;
    std::string exit = "";

    std::string username;
    std::cout << "Input Bank Username: ";
    std::cin >> username;

    username.append("_account.txt");

    std::ifstream infile(username);
    infile >> balance;
    infile.close();

    do {
        std::ofstream outfile(username);

        std::cout << "Select: [1]Balance [2]Deposit [3]Withdraw\n";
        std::cin >> select;

        if(select == 1) {
            showBalance(username, balance);
        }
        if(select == 2) {
            balance = depositMoney(username, balance);
            std::cout << "Current Balance: $" << balance << std::endl;
        }
        if(select == 3) {
            balance = withdrawMoney(username, balance);
            if(balance == -1) {
                continue;
            }
            std::cout << "Current Balance: $" << balance << std::endl;
        }

        outfile << balance;

        outfile.close();
        
        std::cout << "Exit [Y/n]: ";
        std::cin >> exit;
        if (exit == "y" || exit == "Y") {
            break;
        }
    } while (true);

    

    return 0;
}

void showBalance(std::string username, double balance) {
    std::cout << "Your Balance: $" << balance << std::endl;

}

double depositMoney(std::string username, double balance) {
    double amount;
    std::cout << "Deposit Amount: $";
    std::cin >> amount;

    return balance + amount;
}

double withdrawMoney(std::string username, double balance) {
    double amount;
    std::cout << "Withdraw Amount: $";
    std::cin >> amount;

    if (amount > balance) {
        std::cout << "Can't Withdraw Amount. Not Enough Money In Your Account.\n";
    }
    else {
        return balance - amount;
    }
    return balance;
}