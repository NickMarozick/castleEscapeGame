/********************************************
 * Author: Nick Marozick
 * Description: Game Class Header File 
 * Date: 11/27/17
 *******************************************/

#include <iostream> 
#include <string>
#include "space.hpp" 
#include "player.hpp" 
#include "item.hpp" 


#ifndef GAME_HPP
#define GAME_HPP

class Game
{
public: 

Game(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);  

void gameOn(); 
bool gameStartMenu();

Space* headPtr; //beginning
Space* townExitPtr; //exit 
Space* gateExitPtr; //exit 
Space* buildPtr;
Space* tracePtr; // sets up board 

Space* playerLocation; 

Player* PrisonerPtr; 

int turnTracker=1; 
bool gameWon=false; //set to true if townExit or gateExit locaton reached
};

#endif 
