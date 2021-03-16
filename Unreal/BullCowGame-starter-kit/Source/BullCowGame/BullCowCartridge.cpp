// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

#include "FileHelper.h"
#include "Paths.h"
//#include "Math/UnrealMathUtility.h" // Already declared in CoreMinimal.h

void UBullCowCartridge::BeginPlay() // When the game starts
{
	Super::BeginPlay();

	const FString WordsListPath = FPaths::ProjectContentDir() / TEXT("WordsList/HiddenWordsList.txt");
	FFileHelper::LoadFileToStringArrayWithPredicate(Isograms, *WordsListPath, [](const FString& Word)
		{
			return Word.Len() > 4 && Word.Len() < 8 && IsIsogram(Word);
		});

	SetupGame();
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{
	if (bGameOver)
	{
		ClearScreen();
		SetupGame();
	}
	else
		ProcessGuess(PlayerInput);
}

void UBullCowCartridge::SetupGame()
{
	PrintLine(TEXT("Welcome to Bulls&Cows!"));

	int32 RandomIndex = FMath::RandRange(0, Isograms.Num() - 1);
	HiddenWord = Isograms[RandomIndex];
	PlayerLives = HiddenWord.Len() * 2;
	bGameOver = false;

	PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
	PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Debug Line for testing
	PrintLine(TEXT("You have %i lives."), PlayerLives);
	PrintLine(TEXT("Type in your guess and \npress enter to continue..."));

}

void UBullCowCartridge::EndGame()
{
	bGameOver = true;
	PrintLine(TEXT("\nPress enter to play again."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
	if (Guess == HiddenWord)
	{
		PrintLine(TEXT("You won!"));
		EndGame();
		return;
	}

	if (Guess.Len() != HiddenWord.Len())
	{
		PrintLine(TEXT("The hidden word is %i letters long."), HiddenWord.Len());
		PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining."), PlayerLives);
		return;
	}

	if (!IsIsogram(Guess))
	{
		PrintLine(TEXT("No repeating letters, guess again!"));
		return;
	}

	PrintLine(TEXT("Lost a life!"));
	PlayerLives--;

	if (PlayerLives <= 0)
	{
		ClearScreen();
		PrintLine(TEXT("You have no lives left!"));
		PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
		EndGame();
		return;
	}

	//int32 Bulls, Cows; // By not initializing and passing them to the function, we suggest they are going to be out parameters
	//GetBullCows(Guess, Bulls, Cows);
	FBullsCowsCount Score = GetBullCows(Guess);

	PrintLine(TEXT("You have %i Bulls and %i Cows."), Score.Bulls, Score.Cows);

	PrintLine(TEXT("Guess again, you have %i lives left"), PlayerLives);
}

bool UBullCowCartridge::IsIsogram(const FString& Word)
{
	for (int32 Index = 0; Index < Word.Len(); Index++)
		for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
			if (Word[Index] == Word[Comparison])
				return false;
	return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& Words) const
{
	TArray<FString> ValidWords;
	for (FString Word : Words)
		if (Word.Len() >= 4
			&& Word.Len() <= 8
			&& IsIsogram(Word))
			ValidWords.Emplace(Word);
	return ValidWords;
}

FBullsCowsCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
	FBullsCowsCount Count;

	// See screenshot in parent folder for continue and break example
	for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
	{
		if (Guess[GuessIndex] == HiddenWord[GuessIndex])
		{ 
			Count.Bulls++;
			continue;
		}

		for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
			if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
			{
				Count.Cows++;
				break;
			}
	}
	return Count;
}

/*
	// DEBUG
	TArray<FString> ValidWords = GetValidWords(Words);
	PrintLine(TEXT("The number of possible words is %i."), Words.Num());
	PrintLine(TEXT("The number of valid words is %i."), ValidWords.Num());
	PrintLine(TEXT("ValidWords - 1 is %i."), GetValidWords(Words).Num() - 1);

	// FString::Printf Not needed because already in definition of PrintLine
	// PrintLine(FString::Printf(TEXT("The HiddenWord is: %s"), *HiddenWord));

	// INCREMENTS
	Pre increment the right variable than assign its value to the left one
	Post increment assing the value first than increment the left variable

	int32 a = 1; // 1
	int32 b = ++a; // b == 2, a == 2
	int32 c = ++ ++a; // Don't do this. c == 4, a == 4
	int32 d = a += 2; // Do this instead d == 6, a == 6
	int32 e = a++; // e == 6, a == 7

	PrintLine(TEXT("%i, %i, %i, %i, %i"), a, b, c, d, e);

	// ARRAYS
	const TCHAR HW[] = TEXT("plums");
	// const TCHAR HW[] = { TEXT('c'), TEXT('a'), TEXT('k'), TEXT('e'), TEXT('s'), TEXT('\0') };
	PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]); // print "c"
	PrintLine(TEXT("Character 4 of HW is: %c"), HW[3]); // print "m"
	HW;

	// LOOPS
	int32 i = 0;
	while (i < 2)
	{
		PrintLine(TEXT("%i"), i);
		i++;
	}

	for (int32 Index = 0; Index < 2; Index++)
	{
		PrintLine(TEXT("%i"), Index);
	}

	int32 j = 0;
	do // at least once
	{
		PrintLine(TEXT("%i"), j);
		j++;
	} while (j < 2);

	// REFERENCES
	int a = 0;
	int b = 5;

	const int32& refa = a; // After writing const refa = b below will give an error
	PrintLine(TEXT("a = %i, b = %i, refa = i%"), a, b, refa); // 0, 5, 0

	refa = b; // Now refa is a reference also to b, so both refa and a will be 5, so this should be avoided and set refa to const
	PrintLine(TEXT("a = %i, b = %i, refa = i%"), a, b, refa); // 5, 5, 5

	//RANDOM
	// #include "Math/UnrealMathUtility.h" // Already declared in CoreMinimal.h
	PrintLine(TEXT("%i"), FMath::RandRange(0, 10));
*/