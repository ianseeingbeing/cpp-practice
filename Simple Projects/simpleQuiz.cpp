#include <iostream>
#include <cmath>

int main() {

    std::string questions[] = {"1. What year was C++ created?: ", 
                                "2. Does Unreal Engine code in C++? [y/n]: ",
                                "3. What language was C++ born from?: "};
    int qSize = sizeof(questions)/sizeof(questions[0]);

    std::string correctAnswers[qSize] = {"1985", "y", "C"};
    std::string userAnswers[qSize];

    std::cout << "====== Quiz Game ======\n";

    for (int i = 0; i < qSize; i++) {
        std::cout << questions[i];
        std::getline(std::cin, userAnswers[i]);
    }

    int score = 0;

    for (int i = 0; i < qSize; i++) {
        if(correctAnswers[i] == userAnswers[i]) {
            score++;
        }
    }

    std::cout << "\n====== Question Answers ======\n";

    std::cout << "SCORE: (" << score << "/" << qSize << ") or "  << floor((score/(double)qSize)*100) << "%\n";

    for (int i = 0; i < qSize; i++) {
        std::cout << "#" << i + 1 << "\nCorrect Ans: " << correctAnswers[i] << "\n";
        std::cout << "Your Ans: " << userAnswers[i] << "\n";
    }

    return 0;
}