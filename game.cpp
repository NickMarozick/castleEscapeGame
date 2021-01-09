/**************************************************
 * Author: Nick Marozick
 * Description: Game Class Implementation File 
 * Date: 11/27/17
 ***************************************************/

#include <iostream> 
#include <string>
#include <sstream>
#include "space.hpp" 
#include "kitchen.hpp"
#include "dungeon.hpp"
#include "barracks.hpp"
#include "guardedHall.hpp" 
#include "wineCellar.hpp"
#include "theWall.hpp" 
#include "gateExit.hpp" 
#include "townExit.hpp"
#include "player.hpp"
#include "item.hpp"
#include "game.hpp"

/******************************************************************************************************************************
 * Game::Game(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string)- game
 * override constructor
 *****************************************************************************************************************************/

Game::Game(std::string d, std::string k, std::string b, std::string gH, std::string w, std::string tW, std::string rE, std::string gE)
{
headPtr= new Dungeon(d); //headPtr= new Dungeon('Dungeon'); 
headPtr->right= NULL; 
headPtr->left= NULL; 
headPtr->bottom= NULL; 
headPtr->top= new Kitchen(k); //headPtr->top= new Kitchen('Kitchen');  //set up dungeon right below kitchen 

buildPtr= headPtr; 
buildPtr=buildPtr->top;  //buildPtr is now in kitchen 

/*building from the kitchen now */
buildPtr->bottom=headPtr;  //design choice (friar can't see the hideout) // only used for heading back to dungeon if you get caught 
buildPtr->top= NULL; 
buildPtr->left=NULL; 
buildPtr->right= new Barracks(b); //buildPtr->right= new Barracks('Barracks'); 
tracePtr= buildPtr;  //used to build back from barracks  

buildPtr= buildPtr->right; //buildPtr is now in the barracks
buildPtr->right= NULL;
buildPtr->left= tracePtr; 
buildPtr->bottom= NULL; 
buildPtr->top= new GuardedHall(gH); //buildPtr->top= new GuardedHall('GuardedHall');
tracePtr= buildPtr; //used to build back from guardedHall 

buildPtr=buildPtr->top; //buildPtr is now in the new GuardedHall 
buildPtr->bottom= tracePtr;
buildPtr->right= new WineCellar(w); //buildPtr->right= new WineCellar('WineCellar'); 
buildPtr->left= NULL; 
buildPtr->top= new TheWall(tW); //buildPtr->top= new TheWall('TheWall'); 
tracePtr= buildPtr; //will be used to build back from wineCellar and theWall 

buildPtr= buildPtr->right;  //at the WineCellar
buildPtr->left= tracePtr; 
buildPtr->right= NULL; 
buildPtr->top=NULL; 
buildPtr->bottom= new TownExit(rE); //buildPtr->bottom= new TownExit('RiverEscape'); 
townExitPtr= buildPtr->bottom;  //used for destructor in the future )easier)
buildPtr= tracePtr; //back to the GuardedHall for build out to TheWall //could build new spaces exit1 or exit2 


buildPtr= buildPtr->top; //at TheWall
buildPtr->bottom= tracePtr; 
buildPtr->left= new GateExit(gE); //buildPtr->left= new GateExit('GateEscape'); 
buildPtr->right= NULL; 
buildPtr->top= NULL; 
gateExitPtr= buildPtr->right; //will be used for destructor (easier)


tracePtr=NULL;
buildPtr=NULL;

PrisonerPtr= new Player(); //sets up a new player 

std::cout << "\n"; 
std::cout << "Welcome to Castle Dungeon Escape Game!" << "\n"; 
std::cout << "Your goal is to escape the dungeon within a 25 turn limit- any longer and you will be discovered by the guards and locked in a higher security cell." << "\n"; 
std::cout << "You must utilize your resources around you- your wits, select items throughout, and information gathered from people along your journey to escape..." << "\n" << "\n"; 
}


/****************************************************************************************
 * void Game::gameOn()- runs game sequences and ends game if 25 turn limit is reached
 * or player reaches either gateExit or townExit locations 
 ***************************************************************************************/

void Game::gameOn()
{

playerLocation= headPtr; 
	
	while (gameWon!=true && turnTracker<26)
	{

		std::cout << "\n" << "Player is in the " << playerLocation->getName() << "\n" << "\n";
		std::cout << "Turn Count: " << turnTracker << " of 25" << "\n" << "\n"; 

			if (playerLocation->getName()=="RiverEscape") // if townExit location is reached sets bool to true
			{
				gameWon=true;
			}

			if (playerLocation->getName()=="GateEscape") // if gateExit location is reached sets bool to true 
			{
				gameWon=true;
			}		

		
		playerLocation->menu(PrisonerPtr, playerLocation); //Player*, Space* both housed within game  

		turnTracker++;   
	}	

		if (gameWon==false)
		{
			std::cout << "\n" << "The prisoner was found and locked into higher security quarters. Game Over!" << "\n"; 
		}

		if (gameWon==true)
		{
			std::cout << "\n" << "Congratulations on making your escape...now try and stay out of trouble!" << "\n"; 
		}			
}

/**************************************************************************
 * bool Game::gameStartMenu()- used at beginning of game to start or quit
 *************************************************************************/

bool Game::gameStartMenu()
{
bool play;
std::string input; 
int playerChoice; 

std::cout << "Dungeon Escape Game Start Menu" << "\n"; 
std::cout << "1) Play" << "\n";
std::cout << "2) Quit" << "\n";; 
std::cout << "Enter Choice: " << "\n"; 

	do{
		getline(std::cin, input); 
		std::stringstream selection(input); 
		selection >> playerChoice;
		if (playerChoice!=1 && playerChoice!=2)
		{	std::cout << "Invalid input, enter int value menu choice between 1 and 2" << "\n"; }
	  } while ((playerChoice!= 1) && (playerChoice!=2));

	if (playerChoice==1)
	{
		play=true;
	}
	
	if (playerChoice==2)
	{
		play=false;
	}
	
	return play;
}
