#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>
#include <string>
using namespace std;

class Hangman {
private:
    string word;
    string guessed;
    string disappearWord;
    int tries;

public:
    Hangman();
    void drawMan();
    void playGame();
};

#endif
