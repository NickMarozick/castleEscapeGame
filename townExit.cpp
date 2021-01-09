/*************************************************
 * Author: Nick Marozick
 * Description: TownExit Class Implementation File 
 * Date: 12/2/17
 * *************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "space.hpp"
#include "townExit.hpp"
#include "player.hpp"

/******************************************************
 * TownExit::TownExit(std::string x)
 *******************************************************/

TownExit::TownExit(std::string x)
{
	top= NULL; 
	bottom= NULL; 
	left=NULL;
	right=NULL;
	
	spaceName= x; 
}

/***********************************************************************
 * std::string TownExit::getName()- based on the string returned from 
 * TownExit object and reaching the address, game is won! 
 **********************************************************************/

std::string TownExit::getName()
{
	return spaceName;
}


/*****************************************************
 * void TownExit::menu(Player* &p, Space* &s)- last
 * menu call of game as Town Exit location means that
 * you won1
 ****************************************************/

void TownExit::menu(Player* p, Space* &s)
{
	std::cout << "\n" << "\n"; 
	std::cout << "Congratulations on your escape!" << "\n";
}

/*****************************************************************************
 * void TownExit::print(Player* p)
 ****************************************************************************/

void TownExit::print(Player* p)
{
std::cout << "\n" << "\n"; 
std::cout << "############################################################" << "\n";
std::cout << "|OOOOOOOOOOO|------|OOOOOOOOO|----------| OOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOOOO|(EXIT)|-------- |<<<(W)<<<<| OOOOOOOOOOOOOOOOO#" << "Level 3" <<"\n"; 
std::cout << "|OOOOOOOOOOO|------|OOOOOOOOO|----------| OOOOOOOOOOOOOOOOO#" << "\n"; 
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOO#" <<"\n"; 
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOO__________#" << "\n";	
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|---------------|OOOOOOO|$$$$$$$$|#" << "\n";	
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|^^^^^^(GH)>>>>>|-------|$$(WC)$$|#" << "Level 2" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|---------------|OOOOOOO|________|#" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOO|------|OOOOOOOO|-------|OOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOO|>>>>>>|OOOOOOOO|^^^^^^^|OOOOOOOOOOOOOOOO | OOOO#" << "Level 1" << "\n"; 
std::cout << "|OOOOOOOOOO|>(K)>>|--------|^^(B)^^|OOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOO|>>>>>>|OOOOOOOO|^^^^^^^|OOOOOOOO~~~~~~~~~~~~~ O#" << "\n";
std::cout << "|OOOOOOOOOO|------|OOOOOOOO|-------|OOOOOOOO<<<<(EXIT)<<< O#" << "\n";	
std::cout << "|OOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOOOOOOO~~~~~~~~~~~~~ O#" << "\n"; 
std::cout << "|OOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n"; 
std::cout << "|OOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|-------| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|^^^^^^^| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|^^^^^^^| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "BSMT Level" << "\n";
std::cout << "|OOOOOOOOO|^^(D)^^| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|-------| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "############################################################" << "\n";
std::cout << "\n" << "\n"; 
}	

