#include <iostream>
#include <ctime>

int rpsRound(int playerScore, int cpuSelect);
std::string rpsGame();

int main() {

    std::cout << rpsGame();

    return 0;
}

int rpsRound(int playerSelect, int cpuSelect) {

    // 0 --> Draw
    // 1 --> User Won Round
    // 2 --> CPU Won Round

    if(playerSelect == cpuSelect) {
        return 0;
    }
    if(playerSelect == 1 && cpuSelect == 3) {
        return 1;
    }
    if(playerSelect == 2 && cpuSelect == 1) {
        return 1;
    }
    if(playerSelect == 3 && cpuSelect == 2) {
        return 1;
    }
    return 2;
}

std::string rpsGame() {
    
    int playerSelect;
    int cpuSelect;

    int playerScore = 0;
    int cpuScore = 0;

    int roundNumber = 1;

    std::string winner;

    srand(time(NULL));
    
    std::cout << "Welcom to RPS!\n";

    do {
        cpuSelect = (rand() % 3) + 1;
        std::cout << "Select: [1]Rock [2]Paper [3]Scissors [4]exit\n>> ";
        std::cin >> playerSelect;

        if(playerSelect > 4 || playerSelect < 0) {
            std::cout << "Not an Option. Try Again.\n\n";
            continue;
        }
        if(playerSelect == 4) {
            break;
        }
        
        switch(rpsRound(playerSelect, cpuSelect)) {
            case 0: 
                std::cout << "Draw. No Score Added.\n\n"; 
                break;
            case 1: 
                std::cout << "\nPlayer won round " << roundNumber << ".\n";
                playerScore++;
                break;
            case 2:
                std::cout << "\nCPU won round " << roundNumber << ".\n";
                cpuScore++;
        }
        std::cout << "================\nPlayer Score: " << playerScore << "\nCPU Score: " << cpuScore << "\n================\n\n";

        roundNumber++;

    } while (playerScore + cpuScore < 3);

    if (playerSelect == 4) {
        return "";
    }
    return playerScore > cpuScore ? "Player Won RPS\n" : "CPU Won RPS\n";
}