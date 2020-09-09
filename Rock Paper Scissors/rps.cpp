#include <iostream>
#include <ctime>
#include <cstdlib>
#include<cstdio>

using std::cout;
using std::cin;
using std::endl;


// starting main function
int main(){
    // set the char variable for the y/n while loop. I have learned since that a bool statement
    // might have been a little better for the loop
    char ch;
    // set up variables for the scores
    int win = 0;
    int tie = 0;
    int lose = 0;
    int totalGamesPlayed=0;
    char userChoice;
    char options[]={'r','p','s'};

    // Ask the player to choose Rock, Paper, Scissors
    start: cout << "Rock-paper-scissors shoo: ";
    cin >> userChoice;
    // start of game loop, the loop will run untill ch == n
    do {

        if(userChoice!='r' && userChoice!='p' && userChoice!='s' && userChoice!='q')
        {
            cout << "Oops..." << endl;
            goto start;
        }

        if(userChoice=='q' || userChoice=='Q')
            break;

        //using srand with time generates different set of numbers every time
        //initialize the random seed
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // gets a random number between 1 and 3 and tell the player what was chosen
        int compChoice = std::rand() % 3 ;

        cout <<  "The computer chose: " << options[compChoice] << endl;

        totalGamesPlayed++;

        // starts possible outcome sequence in rock paper scissors there are 9 possible out comes 3 wins 3 ties and 3 losses.
        if(userChoice == 'r' && compChoice == 0){
             cout << "I'm rock, tied...." << endl;
             tie++;
             }
        else if(userChoice =='r' && compChoice== 1){
             cout << "I'm paper, I won :)" << endl;
             lose++;
             }
        else if(userChoice == 'r' && compChoice == 2){
             cout << "I'm scissors, you won :(" << endl;
             win++;
             }
        else if(userChoice == 'p' && compChoice == 0){
             cout << "I'm rock, you won :(" << endl;
             win++;
             }
        else if(userChoice == 'p' && compChoice== 1){
             cout << "I'm paper, tied...." << endl;
             tie++;
             }
        else if(userChoice == 'p' && compChoice== 2){
             cout << "I'm scissors, I won :)" << endl;
             lose++;
             }
        else if( userChoice == 's' && compChoice == 0){
             cout << "I'm rock, I won :)" << endl;
             lose++;
             }
        else if( userChoice == 's' && compChoice== 1){
             cout << "I'm paper, you won :(" << endl;
             win++;
             }
        else if(userChoice == 's' && compChoice== 2){
             cout << "I'm scissors, tied...." << endl;
             tie++;
             }
             // this is what happens if the player doesn't hit 1 2 or 3


        // Ask the player to choose Rock, Paper, Scissors
        cout << "Rock-paper-scissors shoo: ";
        cin >> userChoice;



    }while(userChoice!='Q' || userChoice!='q');

    double winPercent=(double)((win/totalGamesPlayed)*100);
    // displays your score so far and asks if you want to play again then clears screen

    cout << " You Won: " << win << ", Lost: "<<lose<<", Tied: "<<tie;
    printf(". You won %.2f %",winPercent);
    //system("pause"); took this out so that the loop ends it with out you needing to hit another button
    return 0;


}
