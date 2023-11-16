#include <iostream>
#include <ctime>

void playGame();
void printBoard(const char board[3][3]);
std::string askPlayerGoFirst();
void playerChoice(char board[3][3], const char symbole);
void cpuChoice(char board[3][3], const char symbole);
void checkBoard(const char board[3][3]);
bool checkWin(char board[3][3]);


int main() {

    //ask player if start game

    //ask them if they want to go first

    //start game loop
    playGame();

    //have an exit button

    return 0;
}

void playGame() {

    char board[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
    char player;
    char cpu;
    int playerScore = 0;
    int cpuScore = 0;
    std::string firstMove;
    std::string secondMove;

    std::cout << "====== TIC TAC TOE ======\n";
    firstMove = askPlayerGoFirst();
    secondMove = (firstMove == "player") ? "cpu" : "player";

    std::cout << "First[X]: " << firstMove << "\nSecond[O]: " << secondMove << '\n';

    if (firstMove == "player") {
        player = 'X';
        cpu = 'O';
    }
    else {
        player = 'O';
        cpu = 'X';
    }

    printBoard(board);
    playerChoice(board, player);
    printBoard(board);
    playerChoice(board, player);
    printBoard(board);
    playerChoice(board, player);
    printBoard(board);


}

void printBoard(const char board[3][3]) {
    std::cout << "=============\n";
    //std::cout << "#############\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "  " << board[i][0] << " | ";
        std::cout << board[i][1] << " | ";
        std::cout << board[i][2] << "  \n";
        if (i < 2) {
            std::cout << " ---+---+--- \n";
        }
    }
    std::cout << "=============\n";
}

std::string askPlayerGoFirst() {
    std::string input;
    std::cout << "Player has first move? [Y/n]: ";
    std::getline(std::cin, input);

    if (input == "N" || input == "n") {
        return "cpu";
    }
    return "player";
}

void playerChoice(char board[3][3], const char symbole) {
    int row;
    int column;
    std::cout << "Row (1-3): ";
    std::cin >> row;
    std::cout << "Colunm (1-3): ";
    std::cin >> column;

    row--;
    column--;

    board[row][column] = symbole;
}

void cpuChoice(char board[3][3], const char symbole) {
    srand(time(0));
    int row = (rand() % 3);
    int column = (rand() % 3);

    board[row][column] = symbole;
}

bool checkWin(char board[3][3]) {

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    return false;
}