// Assignment 8: hangman.cpp  Exercise 21.11
// Date: March 28, 2015

#include <array>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// Function prototype
void displayHangman(unsigned int wrongCount);

// Global constants
const unsigned int MAX_WRONG = 7;   // 7 wrong guesses and you're hung
const size_t WORD_COUNT = 10;   // Number of words to guess from

int main()
{

	array<string, WORD_COUNT> answers = { "EXACTLY", "EXERCISE", "OBJECT", "INHERIT",
		"VECTOR", "SCOPE", "BINARY", "REVERSE", "STREAM", "LIBRARY" };

	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> randomInt(0, (WORD_COUNT-1));

	char playAgain;
	do
	{
		// randomly pick a word from the possible targets
		string target = answers[randomInt(engine)];

		// start with correct length of unknown letters
		string guess(target.size(), '?');

		string lettersGuessed;  // list of letters already guessed
		char letter;			// current letter guess

		ostream_iterator<char> output(cout, " ");

		// Indicate number of letters in target word
		cout << "Guess the word: " << string(target.size(), 'X') << "\n\n" << endl;

		unsigned int wrongCount = 0;
		unsigned int lettersRemainining = target.size();
		bool gameOver = false;

		while (!gameOver)  // repeat guessing until game won or lost
		{
			// prompt for next letter guess
			cout << "Guess a letter: " << guess << "\n?";
			cin >> letter;

			// ignore non letters and ones already guessed
			if (isalpha(letter))
			{
				letter = toupper(letter); // force uppercase
				if (lettersGuessed.find(letter) != string::npos)
				{
					cout << '\'' << letter << "' was already guessed.  Try another letter\n" << endl;
				}

				else
				{
					// record letter guessed
					lettersGuessed.append(1, letter);

					string::const_iterator nextStart = target.cbegin();
					string::const_iterator foundLocation;

					// look for the guessed letter in the target
					while ((foundLocation = find(nextStart, target.cend(),
						letter)) != target.cend())
					{
						// replace correct position in guess with actual letter
						guess[foundLocation - target.cbegin()] = letter;
						nextStart = foundLocation + 1;
						--lettersRemainining;
					}

					if (nextStart == target.cbegin())   // none of that letter found
					{
						// another wrong guess
						++wrongCount;
					}

					// display the current hangman figure based on the number of incorrect guesses,
					// plus the list of letters guessed so far
					displayHangman(wrongCount);
					cout << "Your guesses:\n ";
					copy(lettersGuessed.begin(), lettersGuessed.end(), output);
					cout << "\n" << endl;

					if (lettersRemainining == 0)   // player guessed word?
					{
						cout << "Word: " << target << "\n\n" << endl;
						cout << "Congratulations!!! You guessed my word.\n\n" << endl;
						gameOver = true;
					}

					else if (wrongCount == MAX_WRONG)   // or player ran out of guesses?
					{
						cout << "\nSorry - you have run out of guesses ;-(";
						cout << "\nThe correct answer was: " << target;
						cout << "\n\n...GAME OVER...\n\n" << endl;
						gameOver = true;
					}
				}
			}

			else
			{
				cout << "Letters only please\n" << endl;
			}

		}

		cout << "Play again? (y/n) ";
		cin >> playAgain;

	} while (tolower(playAgain) == 'y');

	system("pause");
}

// Display the hangman figure, one body part per wrong guess
void displayHangman(unsigned int wrongCount)
{
	cout << '\n';

	switch (wrongCount)
	{
	case 0:    // do nothing
		break;

	case 1:
		cout << " o " << endl;
		break;

	case 2:
		cout << " o \n/" << endl;
		break;

	case 3:
		cout << " o \n/|" << endl;
		break;

	case 4:
		cout << " o \n/|\\" << endl;
		break;

	case 5:
		cout << " o \n/|\\\n | " << endl;
		break;

	case 6:
		cout << " o \n/|\\\n | \n/" << endl;
		break;

	case 7:
		cout << " o \n/|\\\n | \n/ \\" << endl;
		break;

	default:
		cout << "Invalid value argument passed to displayHangman: " << wrongCount;
		break;
	}

	cout << endl;
}