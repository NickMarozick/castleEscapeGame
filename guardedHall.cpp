/*((***************************************************
 * Author: Nick Marozick
 * Description: GuardedHall Class Implementation File 
 * Date: 11/27/17
 ******************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include "space.hpp"
#include "guardedHall.hpp" 
#include "item.hpp"
#include "player.hpp"


/****************************************************************
 * GuardedHall::GuardedHall(std::string x)- override constructor
 ****************************************************************/

GuardedHall::GuardedHall(std::string x)
{
	top= NULL; 
	bottom= NULL; 
	left=NULL;
	right=NULL;
	
	spaceName= x; 
}

/************************************************************************
 * std::string GuardedHall::getName()
 * *********************************************************************/

std::string GuardedHall::getName()
{
	return spaceName;
}


/**************************************************************
 * void GuardedHall::menu(Player* &p, Space* &s)- conducts 
 * all player moves within the game based on playerLocation 
 * Space pointer address
 **************************************************************/
	
void GuardedHall::menu(Player* p, Space* &s)
{
std::string input;
int playerChoice;


checkItems(p); //checks to make sure items are there and sets room bool conditions 

std::cout << "\n" << "\n"; 

if (houndFed==true || houndSleep==true)
	{
		std::cout << "Select Action for the Round: " << "\n"; 
		std::cout << "1) Approach the Guards to try and reach 'The Wall'" << "\n"; 
		std::cout << "2) Head past hound to Wine Cellar" << "\n"; 
		std::cout << "3) Head back to the Barracks" << "\n"; 
		std::cout << "4) Attempt to Print Map" << "\n";
		std::cout << "Enter Choice: " << "\n"; 

		do{
			getline(std::cin, input); 
			std::stringstream selection(input); 
			selection >> playerChoice;
			if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3 && playerChoice!=4)
			{	std::cout << "Invalid input, enter int value menu choice between 1 and 4" << "\n"; }
		} while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3) && (playerChoice!=4));
	  
		if (playerChoice==1)
		{
			approachGuards(p, s);
		}
		
		if (playerChoice==2)
		{
			headToWineCellar(s);
		}
		
		if (playerChoice==3)
		{
			headBacktoBarracks(s); 
		}

		if (playerChoice==4)
		{
			checkMap(p);
		}
	}


if (houndFed==false && houndSleep==false)
	{
		std::cout << "Select Action for the Round: " << "\n"; 
		std::cout << "1) Approach the Guards to try and reach 'The Wall'" << "\n"; 
		std::cout << "2) Attempt to walk past the hound to Wine Cellar" << "\n"; 
		std::cout << "3) Feed the hound" << "\n";
		std::cout << "4) Wait a turn hoping hound falls asleep" << "\n"; 
		std::cout << "5) Head back to the Barracks" << "\n"; 
		std::cout << "6) Attempt to Print Map" << "\n"; 
		std::cout << "Enter Choice: " << "\n"; 

		do{
			getline(std::cin, input); 
			std::stringstream selection(input); 
			selection >> playerChoice;
			if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3 && playerChoice!=4 && playerChoice!=5 && playerChoice!=6)
			{	std::cout << "Invalid input, enter int value menu choice between 1 and 6" << "\n"; }
		} while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3) && (playerChoice!=4) && (playerChoice!=5) && (playerChoice!=6));
	  
			if (playerChoice==1)
			{
				approachGuards(p, s);
			}
		
			if (playerChoice==2)
			{	 
				caughtByHound(p, s);
			}
		
			if (playerChoice==3)
			{
				if (hasFood==true)
				{
				feedHound(p); 
				}
				else { std::cout << "You had no food to feed the hound" << "\n"; }
			}
			
			if (playerChoice==4)
			{
				wait(); 
			}
			
			if (playerChoice==5)
			{
				headBacktoBarracks(s); 
			}

			if (playerChoice==6)
			{
				checkMap(p);
			}
	}
	
}

/************************************************************************
 * void GuardedHall::checkItems(Player* &p)- checks items whenever a 
 * player is in the Guarded Hall and sets bool conditions accordingly
 *************************************************************************/

void GuardedHall::checkItems(Player* p)
{

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
  	
	/*
	for (int i=0; i<checkItems.size(); i++)
	{
	  std::cout << "Check Item " << i+1 << ": " << checkItems[i] << "\n"; 
	}*/
		
	hasArmor= std::binary_search (checkItems.begin(), checkItems.end(), "guardArmor");
	hasGuardID= std::binary_search (checkItems.begin(), checkItems.end(), "guardID");
	hasFood= std::binary_search (checkItems.begin(), checkItems.end(), "turkeyLeg");
	

	/*std::cout << "Has Armor: " << hasArmor << "\n"; 
	std::cout << "Has Guard ID: " << hasGuardID << "\n"; 
	std::cout << "Has Food: " << hasFood << "\n";*/ 
}

/**************************************************************************************
 * void GuardedHall::approachGuards(Player* p, Space* &s)- based on bool conditionals
 * according to player items- guard armor and guard ID, gets different behavior. If 
 * player is dressed as a prisoner without ID, guards send player back to the dungeon
 * and take away all items  
 **************************************************************************************/

void GuardedHall::approachGuards(Player* p, Space* &s)
{

std::cout << "\n" << "\n"; 

		if (hasGuardID==true && hasArmor==true)
		{	
			headToTheWall(s);
		}
		
		if (hasGuardID==true && hasArmor==false)
		{
			std::cout << "What are you doing lad? Go get your armor from the barracks and report back for duty." << "\n"; 
			std::cout << "I swear the recruits are getting dumber every year" << "\n"; 
		}
		
		if (hasGuardID==false && hasArmor==true)
		{
			std::cout << "What are you doing rook? Go get your ID and report back on the double." << "\n"; 
			std::cout << "We've got work to do, get moving!" << "\n"; 
		}
		
		if (hasGuardID==false && hasArmor==false)
		{
			std::cout << "Well you don't have a whole lot for brains do you, straight back to the Dungeon you go!" << "\n"; 
			std::cout << "I'll be taking those items as well" << "\n"; 
			
			caughtByGuards(p, s);
		}
}

/*******************************************************************
 * void GuardedHall::feedHound(Player* &p)- uses player item turkey
 * leg. If hound is fed, then you can walk by him
 ********************************************************************/

void GuardedHall::feedHound(Player* p)
{
	houndFed=true;
}

/*****************************************************************
 * void GuardedHall::wait()- rand generator used to wait out if 
 * the hound falls alseep. Then you can pass without issue 
 *****************************************************************/

void GuardedHall::wait()
{
	int x= rand()% 3+1;
	
	if (x<2)
	{
		std::cout << "Hound is still wide alert and watching for intruders" << "\n"; 
		houndSleep=false; 
	}
	
	if (x<3)
	{
		std::cout << "Hound is still wide alert and watching for intruders" << "\n";
		houndSleep=false; 
	}
	
	if (x>2)
	{
		std::cout << "The hound is snoozing- this is a good time to make a break for it" << "\n"; 
		houndSleep=true; 
	}
}

/*********************************************************************************
 * void GuardedHall::caughtByGuards(Player* &p, Space* &s)- guards take all your
 * items and send you back to the dungeon 
 *********************************************************************************/

void GuardedHall::caughtByGuards(Player* p, Space* &s)
{
houndSleep= false;
houndFed= false; 

for (int i=0; i<6; i++)
{
p->carriedItems[i]=NULL;
}

gHTracePtr= s;

gHTracePtr= gHTracePtr->bottom->left->bottom; 

s = gHTracePtr; //put player back to dungeon 
gHTracePtr=NULL;
}

/******************************************************************
 * void GuardedHall::caughtByHound(Player* &p, Space* &s) -hound
 * alerts gaurds and you are sent back to the dungeon itemless   
 ******************************************************************/

void GuardedHall::caughtByHound(Player* p, Space* &s)  
{
houndSleep= false;
houndFed= false; 

std::cout << "\n" << "\n" << "CAUGHT by the hound!" << "\n"; 
std::cout << "The ol' hounds nose is uncanny....not his first time snuffing out Prisoners in disguise" << "\n"; 
std::cout << "Will have to get the hound on my side somehow...." << "\n"; 
std::cout << "Blast it all, the guards took all my stuff....hope I remember how to get out of this wretched place" << "\n"; 

for (int i=0; i<6; i++)
{ 
p->carriedItems[i]=NULL; //cleared vector of player items. Guard armor and ID deleted and cant be retrieved again
}

gHTracePtr= s;

gHTracePtr= gHTracePtr->bottom->left->bottom; 

s = gHTracePtr; //player is back at dungeon (headPtr)

gHTracePtr=NULL;
}

/**********************************************************************
 * void GuardedHall::headBacktoBarracks(Space* &s) - navigates player
 * location back to the Barracks- conceivably to get more items 
 *********************************************************************/

void GuardedHall::headBacktoBarracks(Space* &s) 
{
	gHTracePtr= s; 
	
	gHTracePtr= gHTracePtr->bottom; 
	
	s = gHTracePtr; 
	
	gHTracePtr= NULL; 
}

/********************************************************************
 * void GuardedHall::headToTheWall(Space* &s)- navigates player
 * location to theWall
 ********************************************************************/

void GuardedHall::headToTheWall(Space* &s)
{
	gHTracePtr= s; 
	
	gHTracePtr= gHTracePtr->top;
	
	s= gHTracePtr; 
	
	gHTracePtr=NULL; 
}

/****************************************************************************
 * void GuardedHall::headToWineCellar(Space* &s)- navigates playerLocation
 * to the Wine Cellar
 ***************************************************************************/

void GuardedHall::headToWineCellar(Space* &s) 
{
	gHTracePtr=s; 

	gHTracePtr= gHTracePtr->right; 

	s= gHTracePtr; 

	gHTracePtr= NULL;
}

/*****************************************************************************
 * void GuardedHall::checkMap(Player* p)- checks if player has map and prints
 * if so 
 ****************************************************************************/

void GuardedHall::checkMap(Player* p)
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

/**************************************************************************
 * void GuardedHall::print(Player* p)- prints map 
 **************************************************************************/

void GuardedHall::print(Player* p)
{
std::cout << "\n" << "\n"; 
std::cout << "############################################################" << "\n";
std::cout << "|OOOOOOOOOOO|------|OOOOOOOOO|----------| OOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOOOO|(EXIT)|-------- |<<<(W)<<<<| OOOOOOOOOOOOOOOOO#" << "Level 3" <<"\n"; 
std::cout << "|OOOOOOOOOOO|------|OOOOOOOOO|----------| OOOOOOOOOOOOOOOOO#" << "\n"; 
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOO#" <<"\n"; 
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOO__________#" << "\n";	
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|---------------|OOOOOOO|$$$$$$$$|#" << "\n";	
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|^^^X^^(GH)>>>>>|-------|$$(WC)$$|#" << "Level 2" << "\n";
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
