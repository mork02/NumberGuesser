#include <iostream>
#include <random>
#include <limits>

void PressEnterToEND() {
    std::cin.ignore(std::numeric_limits<std::streamsize> :: max(), '\n');
    std::cout << "Press Enter to end the game!";
    std::cin.get();
}

void clear_screen() {
    system("cls");
}

int main() {
    // Random seed with local time
    srand(time(0));

    // Create random Number
    int rand_num = rand() % 100 + 1;

    // Create Variable for User Input/cin and the Attempts.
    int user_input;
    int attempts = 7;

    std::cout << "The number is between 0 and 100. Good luck guessing the number!" << std::endl;
    while (true) {
        // Get User Input/cin
        std::cout << "Attempts: " << attempts <<"\nWhat number do you guess?\n> ";
        std::cin >> user_input;
        // User Wins
        if (user_input == rand_num) {
            clear_screen();
            std::cout << "Congratulations! You guessed the right number! The number was " << rand_num << "!" << std::endl;
            PressEnterToEND();
            return 0;
        // User Input is to small
        } else if (user_input < rand_num && attempts > 0) {
            clear_screen();
            std::cout << "Your guess is wrong! go BIGGER!" << std::endl;
            attempts--;
        // User Input is to big
        } else if (user_input > rand_num && attempts > 0) {
            clear_screen();
            std::cout << "Your guess is wrong! go SMALLER!" << std::endl;
            attempts--;
        // User Attempts is 0 | Game Over
        } if (attempts == 0) {
            clear_screen();
            std::cout << "You lost all of your Attempts... Game Over!" << std::endl;
            PressEnterToEND();
            return 0;
        // Input/cin failed
        } if (std::cin.fail()) {
            clear_screen();
            std::cin.clear();
            std::cout << "Invalid Input" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize> :: max(), '\n');
            std::cout << "Press Enter to continue!";
            std::cin.get();
            attempts++;
            clear_screen();
        }
    }


    return 0;
}