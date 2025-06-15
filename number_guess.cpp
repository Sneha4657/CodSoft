#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

// Function to generate a random number within a range
int generateRandomNumber(int lower, int upper) {
    return lower + std::rand() % (upper - lower + 1);
}

// Function to handle invalid input
void clearInputStream() {
    std::cin.clear(); // Clear error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
}

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int lowerBound = 0;
    const int upperBound = 120;
    int target = generateRandomNumber(lowerBound, upperBound);
    int guess = 0;
    int attempts = 0;

    std::cout << "=== Welcome to the Number Guessing Game! ===\n";
    std::cout << "I have selected a number between " << lowerBound << " and " << upperBound << ".\n";

    while (true) {
        std::cout << "Enter your guess: ";
        if (!(std::cin >> guess)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputStream();
            continue;
        }

        attempts++;

        if (guess < target) {
            std::cout << "Too low! Try again.\n";
        } else if (guess > target) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "🎉 Congratulations! You guessed the number in " << attempts << " attempts.\n";
            break;
        }
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
