#include <iostream>

void PlayGameAtDifficulty(int difficulty)
{

}

int main()
{
	int lockDigitsCount = 3;
	int lockDigitsSum = 8;
	int lockDigitsProduct = 18;

	// Need a collection for items that the player will unlock.
	std::cout << "While wandering around in the night, you find a fancy hypercar you like." << "\n";

	// Instead of this ugly if else, in the future locks should be represented by classes (base lock, easy lock, medium lock, hard lock etc...).
	if (lockDigitsCount > 3)
		std::cout << "\"Well, a lock with " << lockDigitsCount << " numbers, it gets interesting.\"" << "\n";
	else
		std::cout << "\"Tsk, another one of those stupid security mechanisms with just " << lockDigitsCount << " numbers!\"" << "\n";

	// Add a timer on higher levels.
	std::cout << "The small screen on the car door is waiting for the code..." << "\n";
	std::cout << "\n";
	// Maybe in some level the neuralink could not work properly or at all, in which case there should be another way to find the code.
	std::cout << "Your neural link will give you suggestion to find the right code:" << "\n";
	std::cout << "\n";
	std::cout << "# The " << lockDigitsCount << " numbers add up to " << lockDigitsSum << ". \n";
	std::cout << "# The " << lockDigitsCount << " numbers multiplication result is " << lockDigitsProduct << ". \n";
	std::cout << "\n";

#pragma region Lock Screen
	for (int i = 0; i <= (lockDigitsCount * 3) + 1; i++)
		std::cout << "*";
	std::cout << "\n";
	std::cout << "*";
	for (int i = 0; i < lockDigitsCount; i++)
		std::cout << " # ";
	std::cout << "*" << "\n";

	for (int i = 0; i <= (lockDigitsCount * 3) + 1; i++)
		std::cout << "*";
	std::cout << "\n";
	std::cout << "\n";
#pragma endregion

	if (true)
		std::cout << "The code is correct... - \"Damn, imagine spending so much for a car that has this kind of security\"" << "\n";
	else
		std::cout << "The code is incorrect and the police has been called... \"Well, I guess I'm dumber than the mechanism itself\"" << "\n";

	return 0;
}
