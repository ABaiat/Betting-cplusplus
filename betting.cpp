#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void rules();
int main()
{
    string playerName;
    int balance; // stores player's balance
    int bettingAmount; // stores the amount one wants to bet
    int guess1;
    int guess2;
    int dice; // stores the random number

    char choice;
    string exitt;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t========WELCOME TO BETTING WORLD=======\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << balance << "\n";
// Get player's betting balance
        do
        {
            cout << "Hey, " << playerName<<", enter amount to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                       <<"\nRe-enter balance\n ";
        }while(bettingAmount > balance);
// Get player's numbers
        do
        {
            cout << "\nNumber1: Guess any betting number between 1 & 10 :";
            cin >> guess1;
            cout << "\nNumber2: Guess any betting number between 1 & 10 :";
            cin >> guess2;
            if(guess1 <= 0 || guess1 > 10 || guess2 <= 0 || guess2 > 10)
                cout << "\nNumbers should be between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(guess1 <= 0 || guess1 > 10 || guess2 <= 0 || guess2 > 10);
        dice= rand()%10 + 1;

        if(dice == guess1 || dice == guess2 || (dice == (guess1+guess2)))
        {
            cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount * 5;
            balance = balance + bettingAmount * 5;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice << ", you have guessed: " << guess1 << " & "<< guess2;
        cout << "\n"<<playerName<<", You have balance of $ " << balance << "\n";
        if(balance <= 0)
        {
            cout << "You have no money to play, You should exit this time. Please Type Exit: ";
            cin>> exitt;
            if (true)
            {exit(0);}
            
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t======BETTING NUMBERS GUESSING RULES!======\n";
    cout << "\t1. Choose 2 numbers between 1 to 10\n";
    cout << "\t2. Winner gets 5 times of the money bet if at least one of guessed numbers or the sum of them are correct \n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}