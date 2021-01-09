/************************************************
 * Author: Nick Marozick
 * Description: Barracks Class Implementation File 
 * Date: 11/27/17
 * ************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "space.hpp" 
#include "barracks.hpp"
#include "player.hpp"
#include "item.hpp"

/**********************************************************
 * Barracks::Barracks(std::string)
 **********************************************************/

Barracks::Barracks(std::string x)
{
	top= NULL; 
	bottom= NULL; 
	left=NULL;
	right=NULL;
	
	spaceName= x; 
	
	guardUniformPtr= new Item("guardArmor"); 
	guardIDPtr= new Item("guardID"); 
}

/*********************************************************************
 * std::string Barracks::getName()
 *********************************************************************/

std::string Barracks::getName()
{
	return spaceName;
}

/**************************************************************
 * void Barracks::menu(Player* &p, Space* &s)
 ***************************************************************/

void Barracks::menu(Player* p, Space* &s)
{
std::string input;
int playerChoice;

	std::cout << "\n" << "\n"; 
	
	if (readManual==true && hasGuardArmor==true)
	{
		std::cout << "Select Action for the Round: " << "\n"; 
		std::cout << "1) Enter Guarded Hall" << "\n"; 
		std::cout << "2) Head back to the Kitchen" << "\n"; 
		std::cout << "3) Attempt to Print Map" << "\n"; 
		std::cout << "Enter choice: " << "\n"; 
	
		do{
			getline(std::cin, input); 
			std::stringstream selection(input); 
			selection >> playerChoice;
			if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3)
			{	std::cout << "Invalid input, enter int value menu choice between 1 and 3" << "\n"; }
		} while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3));
		
			if (playerChoice==1)
			{
				enterGuardedHall(s); 
			}
		
			if (playerChoice==2)
			{
				headBackToKitchen(s); 
			}

			if (playerChoice==3)
			{
				checkMap(p);
			}
	}
	
	if (readManual==false && hasGuardArmor==true) 
	{
		std::cout << "Select Action for the Round: " << "\n"; 
		std::cout << "1) Enter Guarded Hall" << "\n"; 
		std::cout << "2) Read Guard Handbook" << "\n"; 
		std::cout << "3) Head back to the Kitchen" << "\n"; 
		std::cout << "4) Attempt to Print Map" << "\n"; 
		std::cout << "Enter choice" << "\n"; 

		do{
			getline(std::cin, input); 
			std::stringstream selection(input); 
			selection >> playerChoice;
			if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3 && playerChoice!=4)
			{	std::cout << "Invalid input, enter int value menu choice between 1 and 4" << "\n"; }
		} while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3) && (playerChoice!=4));
		
			if (playerChoice==1)
			{
				enterGuardedHall(s); 
			}
		
			if (playerChoice==2)
			{
				readGuardManual(p);
			}
		
			if (playerChoice==3)
			{
				headBackToKitchen(s); 
			}

			if (playerChoice==4)
			{
				checkMap(p); 
			}

	}
	
	if (readManual==true && hasGuardArmor==false) 
	{
		std::cout << "Select Action for the Round: " << "\n";
		std::cout << "1) Take the Guard Armor for Disguise" << "\n";		
		std::cout << "2) Enter Guarded Hall" << "\n";  
		std::cout << "3) Head back to the Kitchen" << "\n"; 
		std::cout << "4) Attempt to Print Map" << "\n";
		std::cout << "Enter choice: " << "\n"; 

		do{
			getline(std::cin, input); 
			std::stringstream selection(input); 
			selection >> playerChoice;
			if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3 && playerChoice!=4)
			{	std::cout << "Invalid input, enter int value menu choice between 1 and 4" << "\n"; }
		} while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3) && (playerChoice!=4));
	
				if (playerChoice==1)
				{
					getGuardArmor(p); 
				}
		
				if (playerChoice==2)
				{
					enterGuardedHall(s);
				}
		
				if (playerChoice==3)
				{
					headBackToKitchen(s); 
				}
		
				if (playerChoice==4)
				{
					checkMap(p);
				}
	}

	
	if (readManual==false && hasGuardArmor==false )
	{
		std::cout << "Select Action for the Round: " << "\n"; 
		std::cout << "1) Take the Guard Armor for disguise" << "\n"; 
		std::cout << "2) Read Guard Handbook" << "\n"; 
		std::cout << "3) Enter Guarded Hall" << "\n";
		std::cout << "4) Head back to the Kitchen" << "\n"; 
		std::cout << "5) Attempt to Print Map" << "\n"; 
		std::cout << "Enter Choice: " << "\n"; 

		do{
			getline(std::cin, input); 
			std::stringstream selection(input); 
			selection >> playerChoice;
			if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3 && playerChoice!=4 && playerChoice!=5)
			{	std::cout << "Invalid input, enter int value menu choice between 1 and 5" << "\n"; }
		} while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3) && (playerChoice!=4) && (playerChoice!=5));
			
			
				if (playerChoice==1)
				{
					getGuardArmor(p); 
				}
		
				if (playerChoice==2)
				{
					readGuardManual(p);
				}
				
				if (playerChoice==3)
				{
					enterGuardedHall(s); 
				}
		
				if (playerChoice==4)
				{
					headBackToKitchen(s); 
				}

				if (playerChoice==5)
				{
					checkMap(p); 
				}

	}
	
	
}

/*************************************************************************
 * void Barracks::readGuardManual(Player* &p)-leads to a sequence where 
 * you discover and add to player container a guard ID
 *************************************************************************/

void Barracks::readGuardManual(Player* p)
{
	std::cout << "\n" << "\n"; 
	std::cout << "Learned the guard secret handshake and marching pointers" << "\n"; 
	std::cout << "Guard ID fell out of the book!...could come in handy" << "\n"; 

	readManual=true; 
	
	getGuardID(p);

	hasGuardID=true; 
}

/*************************************************************************
 * void Barracks::getGuardArmor(Player* &p)- adds guard Armor to player
 * container
 *************************************************************************/

void Barracks::getGuardArmor(Player* p)
{ 
	std::cout << "Put on the guard armor...much heavier than expected" << "\n"; 
	std::cout << "....will take some time to get used to moving in the armor" < "\n";

	p->playerGetItem(guardUniformPtr);  //getItem sequence  

	hasGuardArmor=true;
}

/****************************************************************************
 * void Barracks::getGuardID(Player* &p)- adds guard ID to player container
 ***************************************************************************/

void Barracks::getGuardID(Player* p)
{ 
	std::cout << "Pocketed the guard ID" << "\n";  

	p->playerGetItem(guardIDPtr); //getItem sequence 
}

/***************************************************************************
 * void Barracks::deleteItem(Item* x)
 ****************************************************************************/

void Barracks::deleteItem(Item* x)
{
	delete x; 
	x= NULL; 
}

/************************************************************************
 * void Barracks::enterGuardedHall(Space* &s)- moves game object Space*
 * pointer "playerLocation" to GuardedHall address
 ************************************************************************/

void Barracks::enterGuardedHall(Space* &s)
{ 
	bTracePtr= s; 
	bTracePtr= bTracePtr->top; //move to guardedHall
	
	s = bTracePtr; 
	
	bTracePtr= NULL;
}

/**************************************************************************
 * void Barracks::headBackToKitchen(Space* &s)- moves player Location back
 * to the kitchen- concievably to get more items as needed
 **************************************************************************/

void Barracks::headBackToKitchen(Space* &s)
{
	bTracePtr= s; 
	bTracePtr= bTracePtr->left; 
	
	s = bTracePtr; //moved to Barracks 
	
	bTracePtr=NULL; 
}

/*****************************************************************************
 * void Barracks::checkMap(Player* p)- checks if player has a map and calls
 * to print if so
 ****************************************************************************/

void Barracks::checkMap(Player* p)
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
 * void Barracks::print(Player* p)- prints map with X marking Barracks
 ***************************************************************************/

void Barracks::print(Player* p)
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
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOO|---------------|OOOOOOO|________|#" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOOOOOOOOOOOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOO|------|OOOOOOOO|-------|OOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOO|>>>>>>|OOOOOOOO|^^^^^^^|OOOOOOOOOOOOOOOO | OOOO#" << " Level 1" << "\n";
std::cout << "|OOOOOOOOOO|>(K)>>|--------|^^(B)^^|OOOOOOOOOOOOOOOO | OOOO#" << "\n";
std::cout << "|OOOOOOOOOO|>>>>>>|OOOOOOOO|^^^X^^^|OOOOOOOO~~~~~~~~~~~~~ O#" << "\n";
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

