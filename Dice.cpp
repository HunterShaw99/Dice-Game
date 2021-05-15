
#include <iostream>
#include <ctime>

int roll(void);
void promptUser(void);
void getSeed(void);
int seed, d1, d2, targetValue, wallet = 0, dieSum = 0, wins = 0, losses = 0;
char command = 0;

int main() {

	getSeed();
	do {
		promptUser();
		if (dieSum == 7 || dieSum == 11) {
			wallet += 9;
			wins++;
			if (dieSum == 7) {
				wallet++;
			}

		}
		else if (dieSum == 2 || dieSum == 3 ||
			dieSum == 10 || dieSum == 12) {
			wallet -= 10;
			losses++;
		}
		else {
			targetValue = dieSum;
			dieSum = 0;
			while (dieSum != targetValue || dieSum != 7) {
				std::cout << "Target value is: ";
				std::cout << targetValue << std::endl;
				promptUser();
				if (dieSum == 7) {
					wallet -= 9; // Player gets $1 anytime they roll a 7, so here they are only deducted $9. 
					losses++;
					break;
				}
				else if (dieSum == targetValue) {
					wallet += 9;
					wins++;
					break;
				}
			}

		}
		// Print Post-game details.
		std::cout << "Wallet total: $";
		std::cout << wallet << std::endl;
		std::cout << "Total wins: ";
		std::cout << wins;
		std::cout << "	Total losses: ";
		std::cout << losses << std::endl;
		std::cout << "---------------------------------------" << std::endl;

		std::cout << "To play again enter any key, to exit press 'q': ";
		std::cin >> command;
		std::cout << command << std::endl;
	} while (command != 'q');

	if (command == 'q') {
		int dOne = 0, dTwo = 0, dThree = 0, dFour = 0, dFive = 0, dSix = 0, dieValue;
		for (int i = 0; i < 50000; i++) {
			dieValue = roll();
			switch (dieValue) {
			case 1:
				dOne++;
				break;
			case 2:
				dTwo++;
				break;
			case 3:
				dThree++;
				break;
			case 4:
				dFour++;
				break;
			case 5:
				dFive++;
				break;
			default:
				dSix++;
			}
		}
		std::cout << "---Dice Probability based off 50,000 rolls---\n";
		std::cout << "Probability of one: ";
		std::cout << dOne << std::endl;
		std::cout << "Probability of two: ";
		std::cout << dTwo << std::endl;
		std::cout << "Probability of three: ";
		std::cout << dThree << std::endl;
		std::cout << "Probability of four: ";
		std::cout << dFour << std::endl;
		std::cout << "Probability of five: ";
		std::cout << dFive << std::endl;
		std::cout << "Probability of six: ";
		std::cout << dSix << std::endl;
	}
	return 0;
}

// Roll function, used to "roll" dice. 
int roll(void) {
	return rand() % 6 + 1;
}

// promptUser function, used to prompt user for input.
void promptUser() {
	std::cout << "Enter r to roll\n";
	std::cin >> command;
	std::cout << "Entered: ";
	std::cout << command << std::endl;
	d1 = roll();
	d2 = roll();
	dieSum = d1 + d2;
	std::cout << d1;
	std::cout << " & ";
	std::cout << d2;
	std::cout << " for a value of ";
	std::cout << dieSum << std::endl;
}

// Gets the seed from user.
void getSeed() {
	std::cout << "Hello player! enter a seed for your dice game\n";
	std::cin >> seed;

	// If user enters a negative seed value, use system time in seconds as seed.
	if (seed < 0) {
		time_t time(time_t * time);
		seed = (int)time;
		srand(seed);
	}
	else {
		srand(seed);
	}
	std::cout << "Seed entered: ";
	std::cout << seed << std::endl;
}
