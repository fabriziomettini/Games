#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleTitle("ROCK - PAPER - SCISSORS");
	srand(time(NULL));
	
	int rounds, userChoice, CPUChoice, userScore, CPUScore;
	bool again;
	char character;
	
	cout << "ROCK - PAPER - SCISSORS" << endl;
	cout << "-----------------------" << endl;
	
	do{
		userScore = 0; 
		CPUScore = 0;
		
		do{
			cout << "Enter the number of rounds you want to play: ";
			cin >> rounds;
			if(rounds <= 0)){
				cout << "Please, enter a positive integer number!" << endl;
			}
		} while(rounds <= 0);
		cout << endl;
		
		for(int i = 0; i < rounds; i++){
			cout << "Round " << i + 1 << endl;
			cout << "------" << endl;
			
			cout << "Choose between rock (1), paper (2) and scissors (3): ";
			
			do{
				cin >> userChoice;
				if(userChoice < 1 || userChoice > 3){
					cout << "Invalid option. Try Again: ";
				}
			} while(userChoice < 1 || userChoice > 3);
			
			CPUChoice = rand() % 3 + 1;
			
			cout << endl;
			cout << "Your choice: " << userChoice << endl;
			cout << "CPU choice: " << CPUChoice << endl;
			
			if(userChoice == CPUChoice){
				cout << "DRAW" << endl;
			}
			else if(userChoice == CPUChoice + 1|| userChoice == CPUChoice - 2){
				cout << "You WIN this round!" << endl;
				userScore++;
			}
			else{
				cout << "You LOSE this round!" << endl;
				CPUScore++;
			}
			cout << endl;
		}
		
		cout << "Final Results" << endl;
		cout << "-------------" << endl;
		cout << "Your Score: " << userScore << endl;
		cout << "CPU Score: " << CPUScore << endl;
		
		if(userScore == CPUScore){
			cout << "It's a DRAW" << endl;
		}
		else if(userScore > CPUScore){
			cout << "You WIN. Congratulations!" << endl;
		}
		else{
			cout << "You LOSE. Better luck next time!" << endl;
		}
		
		cout << endl;
		cout << "Want to play again? Y / N: ";
		do{
			cin >> character;
			character = toupper(character);
			if(character == 'Y'){
				again = true;
			}
			else if(character == 'N'){
				again = false;
			}
			else{
				cout << "Invalid option. Want to play again? Y / N: ";
			}
		}while(character != 'Y' && character != 'N');
	}while(again);
	
	cout << "Thanks for playing!";
	return 0;
}

