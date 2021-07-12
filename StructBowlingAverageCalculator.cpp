// This program will take the scores of 10 bowlers and will print out each of those scores and their average scores.
// This program will continue to iterate till the file runs out of lines.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
// Created struct to hold the bowlers information that will be used throughout the rest of the program.
    struct bowlerInformation{
        string name;
        int scores[5] = {0,0,0,0,0};
        int averageScore = 0;
    };
    bowlerInformation bowlers[10];

// Function is called to display the *'s and welcome message to welcome the user to the program.
void welcomeMessage() {
    const int STARS_LENGTH = 60;
    const int SIDE_STAR_LENGTH = 7;
    cout << setw(STARS_LENGTH) << setfill('*') << "" << endl;
    cout << setw(SIDE_STAR_LENGTH) << "" << " Welcome to my Average Bowling Scores Counter "
         << setw(SIDE_STAR_LENGTH) << "" << endl;
    cout << setw(STARS_LENGTH) << "" << endl;
    cout << endl;
}
// This function is called when the scores are gathered and will sum all the scores and get the average.
void GetAverageScore(bowlerInformation bowlersInfo[10]){
    int i = 0;
    int j = 0;
    for(i = 0; i < 10; i++){
        int runningTotal = 0;
        for(j = 0; j < 5; j++){
            runningTotal += bowlersInfo[i].scores[j];
        }
        bowlers[i].averageScore = runningTotal / 5;
    }


}
// This function prints the final outcome that is sent to the console.
void PrettyPrintResults(bowlerInformation bowlerScores[10]){
    for (int i = 0; i < 10; i++){
        cout << bowlers[i].name + " scores are: " << endl;
        for (int j = 0; j < 5; j++){
            cout << bowlerScores[i].scores[j] << endl;
        }
        cout << bowlers[i].name + "'s average score is: " << bowlers[i].averageScore << endl;
    }
}
// This function does all the calculations in terms of grabbing the names and the scores from the test file, and sending
// all the information to the print results function
bool GetBowlingData(){
    int i = 0;
    int j = 0;
    string names;
    ifstream inputFile;

    inputFile.open("BowlingScores.txt");
    if (!inputFile)
        return false;

    while(!inputFile.eof()){
        inputFile >> bowlers[i].name;
        for(j = 0; j < 5; j++){
            inputFile >> bowlers[i].scores[j];
        }
        i++;
    }

    return true;
}
// The main function calls all other functions to perform all the calculations and printing of the results.
int main(){
    string names;
    welcomeMessage();
    GetBowlingData();
    GetAverageScore(bowlers);
    PrettyPrintResults(bowlers);
}
