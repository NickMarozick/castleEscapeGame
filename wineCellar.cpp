/****************************************************
* Author: Nick Marozick
* Description: WineCellar Class Implementation File 
* Date: 11/27/17
*****************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "space.hpp"
#include "wineCellar.hpp"
#include "player.hpp"

/********************************************************
 * WineCellar::WineCellar(std::string x)
 *******************************************************/

WineCellar::WineCellar(std::string x)
{
	top= NULL; 
	bottom= NULL; 
	left=NULL;
	right=NULL;
	
	spaceName= x; 
}

/*********************************************************************
 * std::string WineCellar::getName()
 *********************************************************************/

std::string WineCellar::getName()
{
	return spaceName;
}


/*************************************************************************
 * void WineCellar::menu(Player* &p, Space* &s)- handles all player 
 * action sequences
 ************************************************************************/

void WineCellar::menu(Player* p, Space* &s)
{
std::string input;
int playerChoice;
		std::cout << "\n"; 
		std::cout << "Select Action for the Round: " << "\n"; 
		std::cout << "1) Drink Wine" << "\n"; 
		std::cout << "2) Hop in Barrel" << "\n"; 
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
			drinkWine();
		}
		
		if (playerChoice==2)
		{
			hopInBarrel(s);
		}

		if (playerChoice==3)
		{
			checkMap(p); 
		}
}

/***************************************************************
 * void WineCellar::drinkWine(Player* p)- waste of turns for 
 * some fine wine   
 ***************************************************************/

void WineCellar::drinkWine()
{

	std::cout << "\n"; 
 
	if (drink2==true)
	{
		std::cout << "Losing count of his siphons of wine directly from the barrel, the Prisoner may have forgotten about his quest..." << "\n";  
	}
	
	if (drink1==true && drink2==false)
	{
		std::cout << "Feeling a little too loosey, goosey- after all this is an escape run" << "\n"; 
		drink2=true;
	}
	
	if (drink1==false)
	{
		std::cout << "This one is on the castle!" << "\n"; 
		drink1=true;
	}
}

/************************************************************
 * void WineCellar::hopInBarrel(Space* &s)- per the Friar's
 * ramblings, this is a way to escape the castle 
 ************************************************************/

void WineCellar::hopInBarrel(Space* &s)
{
	std::cout << "\n"; 	
	std::cout << "After a bumpy ride and likely a couple of bruises, your barrel finally reached the river, and you slowly floated into town" << "\n"; 

	headToTownExit(s);
}

/**************************************************************
 * void WineCellar::headToTownExit(Space* &s)- navigates you
 * to your escape down the river 
 *************************************************************/

void WineCellar::headToTownExit(Space* &s)
{
	wTracePtr= s; 
	wTracePtr= wTracePtr->bottom;
	s = wTracePtr; //player Location is town exit 	
}	

/******************************************************************************
 * void WineCellar::checkMap(Player* p)- checks if player has a map and calls
 * to print if so 
 ******************************************************************************/

void WineCellar::checkMap(Player* p)
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
	

	std::cout << "Has Map: " << hasMap << "\n";
	
	if (hasMap==true)
	{
		print(p); 
	}
	
	if (hasMap==false)
	{
		std::cout << "You don't have a map to look at. Trust your insticts!" << "\n"; 
	}
}	

/*****************************************************************************
 * void WineCellar::print(Player* p)- prints map with WineCellar marked by X
 ****************************************************************************/

void WineCellar::print(Player* p)
{
std::cout << "\n" << "\n"; 
std::cout << "############################################################" << "\n";
std::cout << "|OOOOOOOOOOO|------|OOOOOOOOO|----------| OOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOOOO|(EXIT)|-------- |<<<(W)<<<<| OOOOOOOOOOOOOOOOO#" << " Level 3" <<"\n"; 
std::cout << "|OOOOOOOOOOO|------|OOOOOOOOO|----------| OOOOOOOOOOOOOOOOO#" << "\n"; 
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOO#" <<"\n"; 
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOO__________#" << "\n";	
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|---------------|OOOOOOO|$$$$$$$$|#" << "\n";	
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|^^^^^^(GH)>>>>>|-------|$$(WC)$$|#" << " Level 2" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|---------------|OOOOOOO|___X____|#" << "\n";
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
