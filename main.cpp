#include <iostream>
#include <random>	
using namespace std;


//==== Function Prototypes ====//
void introduction();
// This function introduces the program

int getNumberOfGames();
// This function prompts the user for the number of games they wish to play

int compareTwoCharacters(char comp, char user);
// This function compares two char datatypes.  Using the char's ASCII code, it can determine if the letter comes before or after another.

bool playOneGame(char input);
// This function controls the overall flow of the game.
// A for-loop controls the number of guesses, while a switch determines what the function returns.

void closeProgram(int win, int loss);
// This function just displays a closing statement.
//==== ====//


int main() {

	int gamesToPlay;													// Variable used to store the number of games to play
	int currentGame = 1;												// Keeps track of the current game number
	int wins = 0;														// Keeps track of the number of user wins
	int losses = 0;														// Keeps track of the number of user losses

	introduction();														// Calls the introduction() function
	gamesToPlay = getNumberOfGames();									// Calls the getNUmberOfGames() function and puts the returned value into gamesToPlay variable

	do {																// Do-loop controls the number of times the game is played
		char cpuChoice;													// char variable for storing the computer's letter
		bool win;														// This variable keeps track of the playOneGame() function
		
		// Random Number Generator (RNG)
		random_device rd;												// Obtains a random number from hardware
		mt19937 RNG(rd());												// Seeds the random number generator
		uniform_int_distribution<int> myRange(97, 122);					// Defines a range for the random numbers.  The range is from the ASCII table (a - z)
		cpuChoice = myRange(RNG);										// Store this random number in my char variable
		// This block of code is used for generating random numbers

		cout << "**************************************" << endl;		// Formatting
		cout << "Let's play!  Game: " << currentGame << endl;			// Displays the current game
		cout << "Wins: " << wins << "\tLosses: " << losses << endl;		// This line will display the current number of player wins and losses
		cout << "Answer: " << cpuChoice << endl;						// For debugging.  Displays the answer.
		cout << endl;													// Line break for formatting
		win = playOneGame(cpuChoice);									// Calls the playOneGame() function and stores the return into win

		if (win) {														// If the user wins the game
			++wins;														// Increase the number of wins
		}
		else {															// If the user loses the game
			++losses;													// Increase the number of losses
		}

		++currentGame;													// Increase the current game by one
		--gamesToPlay;													// Decrease the number of games to play by one

		cout << endl << endl;											// Blank lines.  For formatting
		system("pause");												// Pause the screen and wait for user input
		system("cls");													// Clear the screen
		introduction();													// Call the introduction() function again.  Formatting
	} while (gamesToPlay);												// The do-loop will exit only if gamesToPlay == 0

	closeProgram(wins, losses);											// A quick closing statement that summarizes the user's score

	return 0;
}



// Function Definitions //

void introduction() {
	cout << "Welcom to the Letter Guessing Game" << endl;					
	cout << "You will enter the number of games you want to play (1 - 4 games)" << endl;
	cout << "You have 5 chances to guess each letter" << endl;
	cout << "Let's begin: " << endl << endl;			
	cout << "-----------------------------------------------------------------" << endl << endl;	// Just a line for formatting
}

int getNumberOfGames() {
	int games;																	// Variable to store the number of games

	do {																		// Do-loop to keep asking for input if the user provides values outside the range
		cout << "How many games do you want to play? (1 - 4): " << flush;		// Prompt user for input
		cin >> games;															// Capture input

		if (games < 1) {														// If games is less than 1
			cout << "The number of games must be at least 1!" << endl << endl;	// Needs to be higher
		}
		else if (games > 4) {													// If games is greater than 4
			cout << "The maximum number of games is 4!" << endl << endl;		// Needs to be lower
		}

	} while ((games < 1) || (games > 4));										// Run do-loop while user input is outside of the range [1, 4]

		return games;															// Returns the user input
}

int compareTwoCharacters(char comp, char user) {
	if (comp == user) {								// If user guesses correctly
		return 0;									// Returns zero
	}
	else if (comp > user) {							// If user's guess comes before computer's pick
		return 2;									// Returns two
	}
	else {											// If user's guess comes after computer's pick
		return -2;									// Returns negative two
	}
}

bool playOneGame(char input) {
	int tries = 5;													// Variable to control the number of guesses the user gets
	char guess;														// Variable to store the user's guess


	for (int i = 0; i < tries; i++) {								// For-loop controls the number of guesses
		cout << "Enter a guess: " << flush;							// Prompt user
		cin >> guess;												// Capture user input

		if (i < (tries - 1)) {										// If the number of tries is greater than i.  Keeps the game from providing a hint after last guess.
			switch (compareTwoCharacters(input, guess)) {			// Switch for 3 different inputs
			case 0:													// compareTwoCharacters() returns 0; the user was correct
				cout << "You guesses it!!!" << endl;				// You got it!
				return true;										// return true
				//break;											// break switch, not really necessary because of return
			case 2:													// compareTwoCharacters() returns 2; the user guessed lower
				cout << endl << "Incorrect.  --->" << endl << endl;	// Wrong.  Try to the right
				break;												// Break switch
			case -2:												// compareTwoCharacters() returns -2; the user guessed higher
				cout << endl << "Incorrect.  <---" << endl << endl;	// Wrong.  Try to the left
				break;												// Break switch
			}
		}
		
			
		else {														// When i == (tries - 1).  The user's final guess has been used
			cout << endl << "Game Over!!" << endl;					// Game over!
			cout << "The correct answer was: " << input << endl;	// Displays the correct answer
			return false;											// Returns false
		}

	}
}

void closeProgram(int win, int loss) {
	system("cls");																		// Clear screen
	cout << "Thanks for playing!" << endl << endl;										// Thanks!

	cout << "===================" << endl;												// Box top
	cout << "| Your wins: " << win << "    |" << endl;									// Number of wins
	cout << "| Your losses: " << loss << "  |" << endl;									// Number of losses
	cout << "===================" << endl << endl;										// Box bottom


	if (win == loss) {																	// If the user's wins equal losses
		cout << "Wow!  We have a tie!  Good game!" << endl;								// Tie statement
	}
	else if (win > loss) {																// If the user's wins are greater than losses
		cout << "Looks like you win this time!  Come back to play anytime!" << endl;	// User win statement
	}
	else {																				// If the user's wins are less than losses
		cout << "I win!  Better luck next time!" << endl;								// Computer wins the game
	}

	cout << endl << endl;																// Formatting
	system("pause");																	// Pause the program, wait for user input
	cout << "Closing program..." << flush;												// Closing...
}