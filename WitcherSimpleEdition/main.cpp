//
//  main.cpp
//  WitcherSimpleEdition
//
//  Copyright © 2018 Aleksandra Mokric. All rights reserved.
//
#include <iostream>
#include <stdlib.h> //standard library
#include <unistd.h> //header defines miscellaneous symbolic constants and types, and declares miscellaneous functions.
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL)); //should be run exactly once to intialise the PRNG. Do this in Main when the application starts.
    char enter;
    
    }
int createTheMonster() {
    if (rand() % 58 < 10)
        return 11;
    
    else
        return rand() % 10 + 1;
    
    // Game stats
    string witcherName = "";
    int witcherAlive = true;
    int witcherSkill = 20;
    int witcherScore = 0;
    int monsterCount = 0;
    int monstersKilled = 0;
    
    // Introduction
    cout << "A small village has been surrounded by deadly monsters and is in need of your help. The monsters have taken ten lives already...A Witcher is needed!" << endl << "Press [ENTER] to start.";
    cin.get();
    
    // asks the player for their name
    cout << "Please enter your name: ";
    cin >> witcherName;
    
    // this will ask how many monsters you wish to fight
    cout << "How many monsters do you want to fight? ";
    cin >> monsterCount;
    
    cout << "Save the village from the monsters!" << witcherName << "!" << endl;
    
    // The main game loop
    while (witcherAlive && monstersKilled < monsterCount) {
        // create a random monster
        int monsterSkill = createTheMonster();
        
        // the fight sequence
        if (monsterSkill > 11) {
            cout << endl << "Here comes a big monster!" << endl;
        }
        else {
            cout << endl << "Here comes a monster " << monstersKilled + 1 << endl;
        }
        
        cout << "Come on you need to finish them once and for all" << endl;
        sleep(2);
        
        // witcher killed the player
        if (witcherSkill < monsterSkill) {
            witcherAlive = false;
            cout << "Oh no we are doomed. Goodbye strong warrior. You are dead." << endl;
        }
        
        // witcher killed the monster
        else {
            if (witcherSkill - monsterSkill > 18) {
                cout << "MONSTER KILLED!" << endl;
                witcherScore = witcherScore * 2;
            }
            
            else if (witcherSkill - monsterSkill > 11) {
                cout << "You decapitated the monster!" << endl;
                witcherScore = witcherScore * 2;
            }
            
            else if (witcherSkill - monsterSkill > 5) {
                cout << "Monster slaughtered!" << endl;
                witcherScore = witcherScore * 2;
            }
            
            else if (witcherSkill - monsterSkill > 0) {
                cout << "You killed the monster!" << endl;
                witcherScore = witcherScore * 2;
            }
            
            else {
                cout << "You killed the monster, but you're bleeding..." << endl;
            }
            
            monstersKilled++;
        }
        
        cout << endl;
        sleep(1);
    }
    
    // end of game
    if (monstersKilled == monsterCount) {
        // victory - win
        cout << "The village is grateful. Here is a token of their appreciation ***" << endl;
    }
    else {
        // lost
        cout << "You did not survive. Geralt of Rivia will come to save the day now." << endl;
    }
    
    cout << "Monsters killed: " << monstersKilled << endl;
    cout << "Final score: " << witcherScore << endl << endl;
}

