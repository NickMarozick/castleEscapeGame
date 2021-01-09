/**************************************************
 * Author: Nick Marozick
 * Description: TheWall Class Implementation File 
 * Date: 11/27/17
 **************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include "space.hpp" 
#include "player.hpp"
#include "theWall.hpp"

/***************************************************************
 * TheWall::TheWall(std::string x)- override constructor
 **************************************************************/

TheWall::TheWall(std::string x)
{
	top= NULL; 
	bottom= NULL; 
	left=NULL;
	right=NULL;
	
	spaceName= x; 
}

/*********************************************************************
 * std::string TheWall::getName()
 **********************************************************************/

std::string TheWall::getName()
{
	return spaceName;
}

/***************************************************************
 * void TheWall::menu(Player* &p, Space* &s)- controls all 
 * player action sequences
 ****************************************************************/

void TheWall::menu(Player* p, Space* &s)
{
std::string input;
int playerChoice;

	std::cout << "\n" << "\n"; 
	
	std::cout << "Select Action for the Round: " << "\n"; 
	std::cout << "1) Gamble" << "\n"; 
	std::cout << "2) Take Shift Outside Palace" << "\n";
	std::cout << "3) Attempt to Print Map" << "\n"; 
	std::cout << "Enter Choice: " << "\n";  
	
	do{
		getline(std::cin, input); 
		std::stringstream selection(input); 
		selection >> playerChoice;
		if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3)
		{	std::cout << "Invalid input, enter int value menu choice between 1 and 3" << "\n"; }
	  } while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3));
	  
	  if (playerChoice==1)
	  {
		  gamble();
	  }
	  
	  if (playerChoice==2)
	  {
		  takeShiftOutsidePalace(s); 
	  }

	  if (playerChoice==3)
	  {
		  checkMap(p);
	  }		
}

/****************************************************************
 * void TheWall::gamble()- gamble shifts with "fellow" guards 
 ***************************************************************/

void TheWall::gamble()
{
int poker; 

poker= rand() & 7+1; 

if (poker>3)
{
	std::cout << "Gambling Results: " << "\n"; 
	std::cout << "The Player wins another round and has offloaded his less favorable shifts" << "\n"; 
}

if (poker<4)
{
	std::cout << "Gambling Results: " << "\n"; 
	std::cout << "The Player lost another round and now is stuck with taking on extra shift hours: " << "\n"; 
}
}
	
/**************************************************************************
 * void TheWall::takeShiftOutsidePalace(Space* &s)- brings you to gateExit
 * function, which wins the game 
 **************************************************************************/

void TheWall::takeShiftOutsidePalace(Space* &s)
{
		headToGateExit(s);
}

/****************************************************************************
 * void TheWall::headToGateExit(Space* &s)- navigates you out of the castle 
 * to win the game 
 ***************************************************************************/

void TheWall::headToGateExit(Space* &s)
{
	wallTracePtr= s; 
	wallTracePtr= wallTracePtr->left; 
	
	s = wallTracePtr; //set to gate Exit
	
	wallTracePtr=NULL;
}

/*****************************************************************************
 * void TheWall::checkMap(Player* p)- checks for map and calls to print if 
 * available
 ****************************************************************************/

void TheWall::checkMap(Player* p)
{

bool hasMap;
std::vector<std::string> checkItems; 
std::string x;

	for (int i=0; i<6; i++)
	{
		if (p->carriedItems[i]!=NULL)
		{
		x= p->carriedItems[i]->getName();
		checkItems.push_back(x);
		}
	}
	
	std::sort (checkItems.begin(), checkItems.end());
  	

	hasMap= std::binary_search (checkItems.begin(), checkItems.end(), "map");
	

	/*std::cout << "Has Map: " << hasMap << "\n";*/
	
	if (hasMap==true)
	{
		print(p); 
	}
	
	if (hasMap==false)
	{
		std::cout << "You don't have a map to look at. Trust your insticts!" << "\n"; 
	}
}	

/**************************************************************************
 * void TheWall::print(Player* p)- prints map 
 *************************************************************************/

void TheWall::print(Player* p)
{
std::cout << "\n" << "\n"; 
std::cout << "############################################################" << "\n";
std::cout << "|OOOOOOOOOOO|------|OOOOOOOOO|----------| OOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOOOO|(EXIT)|-------- |<(W)<<X<<<| OOOOOOOOOOOOOOOOO#" << " Level 3" <<"\n"; 
std::cout << "|OOOOOOOOOOO|------|OOOOOOOOO|----------| OOOOOOOOOOOOOOOOO#" << "\n"; 
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOO#" <<"\n"; 
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOO__________#" << "\n";	
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|---------------|OOOOOOO|$$$$$$$$|#" << "\n";	
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|^^^^^^(GH)>>>>>|-------|$$(WC)$$|#" << " Level 2" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|---------------|OOOOOOO|________|#" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOO|------|OOOOOOOO|-------|OOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOO|>>>>>>|OOOOOOOO|^^^^^^^|OOOOOOOOOOOOOOOO | OOOO#" << " Level 1" << "\n";
std::cout << "|OOOOOOOOOO|>(K)>>|--------|^^(B)^^|OOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOO|>>>>>>|OOOOOOOO|^^^^^^^|OOOOOOOO~~~~~~~~~~~~~ O#" << "\n";
std::cout << "|OOOOOOOOOO|------|OOOOOOOO|-------|OOOOOOOO<<<<(EXIT)<<< O#" << "\n";	
std::cout << "|OOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOOOOOOO~~~~~~~~~~~~~ O#" << "\n"; 
std::cout << "|OOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n"; 
std::cout << "|OOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|-------| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|^^^^^^^| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|^^^^^^^| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << " BSMT Level" << "\n";
std::cout << "|OOOOOOOOO|^^(D)^^| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|-------| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "############################################################" << "\n";
std::cout << "\n" << "\n"; 
}	
