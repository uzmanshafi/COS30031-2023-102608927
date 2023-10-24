#include "HighScore.h"
#include "MainMenu.h"
#include <iostream>

HighScore::HighScore(GameStateManager* mgr) : manager(mgr) {}

void HighScore::enter() {
    std::cout << "Zorkish :: New High Score \n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "Congratulations!\n";
    std::cout << "You have made it to the Zorkish Hall Of Fame\n";
    std::cout << "Adventure : [the adventure world played]\n";
    std::cout << "Score : [the players score]\n";
    std::cout << "Moves : [number of moves player made]\n";
    std::cout << "Please type your name and press enter :\n";
    std::cout << ": >";
}

void HighScore::update() {
    std::cin.get();
    manager->setGameState(new MainMenu(manager));
}

void HighScore::exit() {

}
