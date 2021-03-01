#include <iostream>
#include <Windows.h>

void PlayGameAtDifficulty(int difficulty)
{
}


int main()
{
	int LockDigitsCount = 3;
	int LockDigitsSum = 8;
	int LockDigitsProduct = 18;

#pragma region Initial story lines
	// Need a collection for items that the player will unlock.
	std::cout << "While wandering around in the night, you find a fancy hypercar you like.\n";
	///
		// Instead of this ugly if else, in the future locks should be represented by classes (base lock, easy lock, medium lock, hard lock etc...).
	if (LockDigitsCount > 3)
		std::cout << "\"Well, a lock with " << LockDigitsCount << " numbers, it gets interesting.\"\n";
	else
		std::cout << "\"Tsk, another one of those stupid security mechanisms with just " << LockDigitsCount << " numbers!\"\n";

	// Add a timer on higher levels.
	std::cout << "The small screen on the car door is waiting for the code...\n";
	std::cout << "\n";
	// Maybe in some level the neuralink could not work properly or at all, in which case there should be another way to find the code.
	std::cout << "Your neural link will give you suggestion to find the right code:\n";
	std::cout << "\n";
	std::cout << "+ The " << LockDigitsCount << " numbers add up to " << LockDigitsSum << ". \n";
	std::cout << "+ The " << LockDigitsCount << " numbers multiplication result is " << LockDigitsProduct << ".\n" ;
	std::cout << "\n";
#pragma endregion

#pragma region Lock Screen
	std::string DisplayedDigits;
	for (int i = 0; i < LockDigitsCount; i++)
		DisplayedDigits += " # ";

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {0, 10};
	SetConsoleCursorPosition(hConsole, position);

	for (int i = 0; i <= (LockDigitsCount * 3) + 1; i++)
		std::cout << "*";

	std::cout << "\n";
	std::cout << "*"; std::cout << DisplayedDigits; std::cout << "*";
	std::cout << "\n";


	for (int i = 0; i <= (LockDigitsCount * 3) + 1; i++)
		std::cout << "*";
	std::cout << "\n";
	std::cout << "\n";
#pragma endregion

#pragma region Player input
	int PlayerGuess1, PlayerGuess2, PlayerGuess3;
	std::cin >> PlayerGuess1; std::cin >> PlayerGuess2; std::cin >> PlayerGuess3;
	int PlayerSum = PlayerGuess1 + PlayerGuess2 + PlayerGuess3;
	int PlayerProduct = PlayerGuess1 * PlayerGuess2 * PlayerGuess3;
#pragma endregion

#pragma region Ending story lines
	std::cout << "\n";
	std::cout << "You enter the code..." << PlayerGuess1 << PlayerGuess2 << PlayerGuess3 + "\n";
	if (PlayerSum == LockDigitsSum && PlayerProduct == LockDigitsProduct)
		std::cout << "The code is correct... -\"Damn, imagine spending so much for a car that has this kind of security\"\n";
	else
		std::cout << "The code is incorrect and the police has been called... \"Well, I guess I'm dumber than the mechanism itself\"\n";
#pragma endregion

	return 0;
}
