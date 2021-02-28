#include <iostream>
#include <Windows.h>

void PlayGameAtDifficulty(int difficulty)
{

}

int main()
{
	int lockDigitsCount = 3;
	int lockDigitsSum = 8;
	int lockDigitsProduct = 18;

#pragma region Initial story lines
	// Need a collection for items that the player will unlock.
	std::cout << "While wandering around in the night, you find a fancy hypercar you like." << std::endl;
	///
		// Instead of this ugly if else, in the future locks should be represented by classes (base lock, easy lock, medium lock, hard lock etc...).
	if (lockDigitsCount > 3)
		std::cout << "\"Well, a lock with " << lockDigitsCount << " numbers, it gets interesting.\"" << std::endl;
	else
		std::cout << "\"Tsk, another one of those stupid security mechanisms with just " << lockDigitsCount << " numbers!\"" << std::endl;

	// Add a timer on higher levels.
	std::cout << "The small screen on the car door is waiting for the code..." << std::endl;
	std::cout << std::endl;
	// Maybe in some level the neuralink could not work properly or at all, in which case there should be another way to find the code.
	std::cout << "Your neural link will give you suggestion to find the right code:" << std::endl;
	std::cout << std::endl;
	std::cout << "+ The " << lockDigitsCount << " numbers add up to " << lockDigitsSum << ". \n";
	std::cout << "+ The " << lockDigitsCount << " numbers multiplication result is " << lockDigitsProduct << "." << std::endl;
	std::cout << std::endl;
#pragma endregion

#pragma region Lock Screen
	std::string displayedDigits;
	for (int i = 0; i < lockDigitsCount; i++)
		displayedDigits += " # ";

	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD position = {displayedDigits.at(1)};

	for (int i = 0; i <= (lockDigitsCount * 3) + 1; i++)
		std::cout << "*";

	std::cout << std::endl;
	std::cout << "*"; std::cout << displayedDigits; std::cout << "*";
	std::cout << std::endl;

	//SetConsoleCursorPosition(hConsole, position);

	for (int i = 0; i <= (lockDigitsCount * 3) + 1; i++)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << std::endl;
#pragma endregion

#pragma region Player input
	int playerGuess1, playerGuess2, playerGuess3;
	std::cin >> playerGuess1; std::cin >> playerGuess2; std::cin >> playerGuess3;
	int playerSum = playerGuess1 + playerGuess2 + playerGuess3;
	int playerProduct = playerGuess1 * playerGuess2 * playerGuess3;
#pragma endregion

#pragma region Ending story lines
	std::cout << std::endl;
	std::cout << "You enter the code..." << playerGuess1 << playerGuess2 << playerGuess3 << std::endl;
	if (playerSum == lockDigitsSum && playerProduct == lockDigitsProduct)
		std::cout << "The code is correct... -\"Damn, imagine spending so much for a car that has this kind of security\"" << "\n";
	else
		std::cout << "The code is incorrect and the police has been called... \"Well, I guess I'm dumber than the mechanism itself\"" << "\n";
#pragma endregion

	return 0;
}
