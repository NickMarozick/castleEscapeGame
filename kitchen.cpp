/******************************************************
 * Author: Nick Marozick
 * Description: Kitchen Class Implementation File 
 * Date: 11/27/17
 *****************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "space.hpp" 
#include "kitchen.hpp" 
#include "item.hpp"
#include "player.hpp"

/******************************************************************
 * Kitchen::Kitchen(std::string x) - kitchen override constructor 
 *****************************************************************/

Kitchen::Kitchen(std::string x)
{
top=NULL; 
bottom=NULL; 
right=NULL; 
left= NULL; 

spaceName= x; 

turkeyLegPtr= new Item("turkeyLeg");
}

/********************************************************************************************
 * void Kitchen::menu(Player* p, Space* &s) -coordinates all moves within game. different 
 * menus are called depending on which derived Space Class playerLocation pointer is in  
 ********************************************************************************************/

void Kitchen::menu(Player* p, Space* &s)
{
std::string input;
int playerChoice;

	std::cout << "\n" << "\n"; 

	if (hasTurkeyLeg==true)
	{
		std::cout << "Select Action for the Round: " << "\n"; 
		std::cout << "1) Head East to Barracks" << "\n"; 
		std::cout << "2) Serve Friar drinks" << "\n"; 
		std::cout << "3) Eat some fine foods" << "\n"; 
		std::cout << "4) Attempt to Print Map" << "\n"; 
		do{
			getline(std::cin, input); 
			std::stringstream selection(input); 
			selection >> playerChoice;
			if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3 && playerChoice!=4)
			{	std::cout << "Invalid input, enter int value menu choice between 1 and 4" << "\n"; }
		} while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3) && (playerChoice!=4));

			if (playerChoice==1)
			{
				enterBarracks(s);
			}

			if (playerChoice==2)
			{
				serveFriarMead();
			}

			if (playerChoice==3)
			{
				eatFood(); 
			}

			if (playerChoice==4)
			{
				checkMap(p);
			}

	}

	if (hasTurkeyLeg==false)
	{
		std::cout << "Select Action for the Round: " << "\n"; 
		std::cout << "1) Head East to Barracks" << "\n"; 
		std::cout << "2) Serve Friar drinks" << "\n"; 
		std::cout << "3) Eat some fine foods" << "\n"; 
		std::cout << "4) Take Turkey Leg" << "\n"; 
		std::cout << "5) Attempt to Print Map" << "\n";  

		do{
			getline(std::cin, input); 
			std::stringstream selection(input); 
			selection >> playerChoice;
			if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3 && playerChoice!=4 && playerChoice!=5)
			{	std::cout << "Invalid input, enter int value menu choice between 1 and 5" << "\n"; }
		} while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3) && (playerChoice!=4) && (playerChoice!=5));

			if (playerChoice==1)
			{
				enterBarracks(s);
			}

			if (playerChoice==2)
			{
				serveFriarMead();
			}

			if (playerChoice==3)
			{
				eatFood(); 
			}
			
			if (playerChoice==4)
			{
				getTurkeyLeg(p);
			}

			if (playerChoice==5)
			{
				checkMap(p);
			}

	}

}

/*********************************************************************
 * std::string Kitchen::getName()
 *********************************************************************/

std::string Kitchen::getName()
{
	return spaceName;
}

/************************************************************************
 * void Kitchen::enterBarracks(Space* &s)- navigates game object Space 
 * pointer, playerLocation to Barracks
 ************************************************************************/

void Kitchen::enterBarracks(Space* &s)
{
	kTracePtr= s;
	
	kTracePtr= kTracePtr->right; 
	
	s= kTracePtr; 
	
	kTracePtr= NULL;
}

/*********************************************************************
 * void Kitchen::getTurkeyLeg(Player* &p) -adds turkeyLeg item to 
 * player container 
 ***********************************************************************/

void Kitchen::getTurkeyLeg(Player* p)  
{
hasTurkeyLeg=true;  

p->playerGetItem(turkeyLegPtr);
}

/********************************************************************
 * void Kitchen::serveFriarMead() - talking sequence has bools, the
 * more he drinks, the more the friar shares- till he hits a wall
 *********************************************************************/

void Kitchen::serveFriarMead() 
{

	std::cout << "\n" << "\n";  
	
	if (thirdDrink==true)
	{
		std::cout << "If I didn't know any better would say I'm repeating myself right now. Time to catch me some rest" << "\n"; 
	}
	
	if (secondDrink==true && thirdDrink==false)
	{
		std::cout << "What was that you asked....ahh yes, there are only 3 ways out of the castle really, well 2 for today." << "\n";
		std::cout << "Downriver from the wine cellar is one, some townsfolk swim there, but I've heard too many fish stories about what be lurking in the depths" << "\n"; 
		std::cout << "There's always the drawbridge, but the streets are so packed with commonfolk right now, they aren't lowering them" << "\n"; 
		std::cout << "The guards also have an exit and generally don't mind escorting castlefolk out for the tournament games" << "\n"; 
		thirdDrink=true;
	}
	
	if (firstDrink==true && secondDrink==false)
	{
		std::cout << "A lot of new guards in training right now. They send all the newbies out from the castle to watch the outer gates" << "\n"; 
		std::cout << "Would rather watch paint dry" << "\n"; 
		secondDrink=true;
	}

	if (firstDrink==false)
	{
		std::cout << "Well, where did you come from young lad? Nevermind, nevermind." << "\n"; 
		std::cout << "Go ahead and fetch yourself some ale or wine. As for me, pour me up some more mead would ya? " << "\n"; 
		std::cout << "That's some constume you got there, you almost look like one of the prisoners!" << "\n"; 
		std::cout << "Wouldn't go parading around the castle like that, don't want to be thrown in the Dungeons by mistake" << "\n"; 
		std::cout << "Too bad you got here too early, will be sealing the barrels of wine to send down river today" << "\n"; 
		std::cout << "We roll the barrels 20 yards from the wine cellar right into the river, and the river feeds clear out from the castle to the nearest town. And what a fun town that is" << "\n"; 
		
		firstDrink=true;
	}
}

/**************************************************************************
 * void Kitchen::eatFood()- wasted turn or well needed meal depending on
 * how you look at it 
 *************************************************************************/

void Kitchen::eatFood()
{
	std::cout << "What a meal. Nothing like a full belly after some long travels....I should probably make better use of my time though" << "\n"; 
}

/**************************************************************************
 * void Kitchen::deleteItem(Item* x)
 **************************************************************************/

void Kitchen::deleteItem(Item* x)
{
	delete x; 
	x= NULL; 
}

/*****************************************************************************
 * void Kitchen::checkMap(Player* p)- checks for player map and calls to
 * print if player container has one 
 ****************************************************************************/

void Kitchen::checkMap(Player* p)
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
 * void Kitchen::print(Player* p)- kitchen marked with X on map  
 ****************************************************************************/

void Kitchen::print(Player* p)
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
std::cout << "|OOOOOOOOOO|>>X>>>|OOOOOOOO|^^^^^^^|OOOOOOOO~~~~~~~~~~~~~ O#" << "\n";
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

