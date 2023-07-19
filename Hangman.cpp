#include "hangman.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#define WRONG_TRIES 5
using namespace std;

Hangman::Hangman() {
    srand(time(NULL));
    string wordList[12] = { "january", "february", "march", "april",
                                 "may", "june", "july", "august", "september", "october",
                                 "november", "december" };
    word = wordList[1 + rand() % 12];
    int wordLength = word.length();
    disappearWord = string(wordLength, '_');
    guessed = "";
    tries = WRONG_TRIES;
}

void Hangman::drawMan() {
    cout << endl << endl;
    cout << "-----" << endl;
    cout << "  |   |" << endl;
    cout << "  |";
    if (tries >= 1) cout << " (• •)" << endl;
    cout << "  |";
    if (tries >= 3) cout << "  /|\\" << endl;
    cout << "  |";
    if (tries >= 5) cout << "  / \\" << endl;
}

void Hangman::playGame() {
    int wordLength = word.length();
    int found = 0;
    char guess = ' ';
    int flagFound = 0;

    while (tries >= 0) {
        system("cls");
        cout << "Guess the word" << endl;
        for (int i = 0; i < wordLength; i++)
            cout << " " << disappearWord[i] << " " << endl;
        cout << "Wrong Attempts: " << tries << "/" << WRONG_TRIES << endl;
        cout << "Guessed letters: " << guessed << endl;
        drawMan();
        if (found == wordLength) {
            cout << endl << endl;
            cout << "You win!" << endl;
            break;
        }
        if (tries == 0)
            break;
        std::cout << "Guess a letter: ";
        guess = getche();
        guessed = guessed + " " + guess;
        if (disappearWord.find(guess) != string::npos)
            tries++;
        flagFound = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess && disappearWord[i] == '_') {
                disappearWord[i] = guess;
                found++;
                flagFound = 1;
            }
        }
        if (!flagFound)
            tries--;
    }

    if (found != wordLength) {
        cout << endl;
        cout << "You lose!" << endl;
    }
    getch();
}
