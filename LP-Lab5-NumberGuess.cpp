//Lium Powers, Computer Science, Lab 5, 11/10/2026
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

//declare Random Number Generator
int RNG(int m);
//This is the menu that takes user inputs and compares it to the random num
void playMenu();
//compares the guess to the random number
void guessCheck(int num, int guess);
//ends the game if the guess is correct
void win();
//prints a loss message if user does noot guess correctly
void loss();
//Asks user if they want to play again, and ends or repeats program depending on answer
bool playAgain();


int main()
{
    do
    {
        std::cout << "I will pick a random number between 1 and 100, and you try to guess it!" << std::endl;
        std::cout << "Enter your first guess" << std::endl;
        playMenu();
    }
    while(playAgain() == true);

   return 0;
}

int RNG(int m)
{
    srand(time(NULL));
    int ranNum = rand() % m + 1;
    return ranNum;
}

void playMenu()
{
    int guess;
    std::cin >> guess;
    int num = RNG(100);
    int i;

    for(i = 0; i < 20 - 1; i++)
    {
            guessCheck(num, guess);
    }
    
    if(guess != num)
        {
            loss();
        }
        else if(guess == num && i == 20)
        {
            win();
        }
}

void guessCheck(int num, int guess)
{
        if(guess == num)
        {
            win();
        }
        else
        {
            std::cout << "Not quite! Try again!" << std::endl;
            std::cin >> guess;
        }
}

void win()
{
    int msg = RNG(10);
    switch(msg)
    {
        case 1 : std::cout << "Good Job, You Win!" << std::endl;
        break;
        case 2 : std::cout << "Congrats, You Got It!" << std::endl;
        break;
        case 3 : std::cout << "Way To Go, You Won!" << std::endl;
        break;
        case 4 : std::cout << "We Have a Winner!!!" << std::endl;
        break;
        case 5 : std::cout << "Winner Winner Chicken Dinner" << std::endl;
        break;
        case 6 : std::cout << "Woohoo! You have Won!" << std::endl;
        break;
        case 7 : std::cout << "Great Guess, Player" << std::endl;
        break;
        case 8 : std::cout << "Winner!!!" << std::endl;
        break;
        case 9 :std::cout << "Here\'s a pat on the back for winning" << std::endl;
        break;
        default : std::cout << "Correct Guess, You Win!" << std::endl;
    }
}

void loss()
{
    int msg = RNG(10);
    switch(msg)
    {
        case 1 : std::cout << "Not this time </3" << std::endl;
        break;
        case 2 : std::cout << "Not quite." << std::endl;
        break;
        case 3 : std::cout << "You are... Not the Winner!" << std::endl;
        break;
        case 4 : std::cout << "Maybe next time." << std::endl;
        break;
        case 5 : std::cout << "Are you even Trying?" << std::endl;
        break;
        case 6 : std::cout << "Lets try again" << std::endl;
        break;
        case 7 : std::cout << "You are kinda.. not good at this" << std::endl;
        break;
        case 8 : std::cout << "Huh, I almost thought you had it there" << std::endl;
        break;
        case 9 :std::cout << "You lost, better luck next time" << std::endl;
        break;
        default : std::cout << "Take a break" << std::endl;
        break;
    }
}

bool playAgain()
{
    bool again = true;
    char yn = 'y';
    std::cout << "would you like to play again? y/n" << std::endl;
    std::cin >> yn;

    switch(yn)
    {
        case 'y' : again = true;
        break;
        case 'n' : again = false;
        break;
        default : std::cout << "Invalid Input" << std::endl;
        again = false;
    }
    return again;
}