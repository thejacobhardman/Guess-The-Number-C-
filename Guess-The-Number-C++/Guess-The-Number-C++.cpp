// Jacob Hardman
// Comp Sci 1
// Professor Jennifer Bailey
// 10/13/19

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	bool isRunning = true;
	std::string userInput = "";
	int guess = 0;

	while (isRunning) {

		bool isGuessed = false, userConfirm = false;
		int tries = 0, randNum = rand() % 100 + 1, maxNum;

		while (userConfirm == false) {
			std::cout << "Welcome to guess the number!" << std::endl;
			std::cout << "Enter '1' for easy, '2' for medium, or '3' for hard: ";
			std::cin >> userInput;
			guess = stoi(userInput);

			switch (guess) {
			case 1:
				randNum = rand() % 100 + 1;
				maxNum = 100;
				userConfirm = true;
				break;
			case 2:
				randNum = rand() % 500 + 1;
				maxNum = 500;
				userConfirm = true;
				break;
			case 3:
				randNum = rand() % 1000 + 1;
				maxNum = 1000;
				userConfirm = true;
				break;
			default:
				std::cout << "Please enter a valid selection." << std::endl;
			}
		}

		userConfirm = false;

		std::cout << "\nI'm thinking of a number between 1 and " << maxNum << "." << std::endl << "Can you guess what it is?" << std::endl;

		while (isGuessed == false) {
			std::cout << "Guess the number: ";
			std::cin >> userInput;
			guess = stoi(userInput);
			tries += 1;

			if (guess == randNum) {
				std::cout << "Congratulations! You guessed it!" << std::endl;
				std::cout << "I was thinking of the number " << randNum << "." << std::endl;
				std::cout << "You guessed it in " << tries << " guesses." << std::endl << std::endl;
				isGuessed = true;
			}
			else if (guess > randNum) {
				std::cout << "Sorry, that's too high." << std::endl;
			}
			else if (guess < randNum) {
				std::cout << "Sorry, that's too low." << std::endl;
			}
		}

		while (userConfirm == false) {
			std::cout << "Play again? (Y/N): ";
			std::cin >> userInput;

			if (userInput == "y" || userInput == "Y") {
				userConfirm = true;
			}
			else if (userInput == "n" || userInput == "N") {
				userConfirm = true;
				isRunning = false;
			}
			else {
				std::cout << "Please enter a valid selection." << std::endl;
			}
		}
	}
}
