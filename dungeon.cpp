/*****************************************************
 * Author: Nick Marozick
 * Description: Dungeon Class Implementation File 
 * Date: 12/4/17
 ****************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "space.hpp" 
#include "dungeon.hpp"
#include "item.hpp"
#include "player.hpp"

/*********************************************************************
 * Dungeon::Dungeon(std::string x)- Dungeon class override destructor  
 *********************************************************************/

Dungeon::Dungeon(std::string x)
{
top=NULL; 
bottom=NULL; 
right=NULL; 
left= NULL; 

spaceName= x; 

mapPtr= new Item("map");
slopPtr= new Item("slop");
}

/****************************************************************
 * std::string Dungeon::getName()
 ****************************************************************/

std::string Dungeon::getName()
{
		return spaceName;
}


/****************************************************************
 * void menu(Player* &p, Space* &s)- menu function runs all in  
 * game action and takes spcae pointer and address to be able to
 * change the game object Space pointer's address within the 
 * LinkedStructure and keep the game progressing. The player 
 * pointer is used to work with the items    
 ****************************************************************/

void Dungeon::menu(Player* p, Space* &s)
{
std::string input;
int playerChoice;

std::cout << "\n" << "\n"; 

checkItems(p);

if (prisoner1Fed==true && haveMap==true)
{
	std::cout << "Select Action for the Round: " << "\n"; 
	std::cout << "1) Interact with Prisoner 1" << "\n"; 
	std::cout << "2) Interact with Prisoner 2" << "\n"; 
	std::cout << "3) Have prisoner lead you to kitchen hatch" << "\n"; 
	std::cout << "4) Attempt to print map" << "\n"; 
	do{
		getline(std::cin, input); 
		std::stringstream selection(input); 
		selection >> playerChoice;
		if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3 && playerChoice!=4)
		{	std::cout << "Invalid input, enter int value menu choice between 1 and 4" << "\n"; }
	  } while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3) && (playerChoice!=4));


		if (playerChoice==1)
		{
			interactWithPrisoner1();
		}

		if (playerChoice==2)
		{
			interactWithPrisoner2();
		}

		if (playerChoice==3)
		{ 
			escapeToHatch(s);   // navigate to kitchen through structure 
		}
		
		if (playerChoice==4)
		{
			checkMap(p); // if no map item in player container, doesn't print 
		}
}


if (prisoner1Fed==true && haveMap==false)
{
	std::cout << "Select Action for the Round: " << "\n"; 
	std::cout << "1) Interact with Prisoner 1" << "\n"; 
	std::cout << "2) Interact with Prisoner 2" << "\n"; 
	std::cout << "3) Take Map" << "\n"; 

	do{
		getline(std::cin, input); 
		std::stringstream selection(input); 
		selection >> playerChoice;
		if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3)
		{	std::cout << "Invalid input, enter int value menu choice between 1 and 3" << "\n"; }
	  } while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3));

		if (playerChoice==1)
		{
			interactWithPrisoner1();
		}

		if (playerChoice==2)
		{
			interactWithPrisoner2();
		}

		if (playerChoice==3)
		{
		getMap(p);
		}
		
}

	
if (prisoner1Fed==false && hasFood==true)
{
	std::cout << "Select Action for the Round: " << "\n"; 
	std::cout << "1) Interact with Prisoner 1" << "\n"; 
	std::cout << "2) Interact with Prisoner 2" << "\n"; 
	std::cout << "3) Feed Prisoner 1" << "\n"; 
	
		do{
			getline(std::cin, input); 
			std::stringstream selection(input); 
			selection >> playerChoice;
			if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3)
			{	std::cout << "Invalid input, enter int value menu choice between 1 and 3" << "\n"; }
		  } while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3)); 

			if (playerChoice==1)
			{
				interactWithPrisoner1();
			}

			if (playerChoice==2)
			{
				interactWithPrisoner2();
			}

			if (playerChoice==3)
			{
				feedPrisoner1(); // cannot get map or to next area without feeding prisoner food item
			}
									

}

if (prisoner1Fed==false && hasFood==false)
{
	std::cout << "Select Action for the Round: " << "\n"; 
	std::cout << "1) Interact with Prisoner 1" << "\n"; 
	std::cout << "2) Interact with Prisoner 2" << "\n"; 
	std::cout << "3) Pick Up Food Tray" << "\n"; 
	
		do{
			getline(std::cin, input); 
			std::stringstream selection(input); 
			selection >> playerChoice;
			if (playerChoice!=1 && playerChoice!=2 && playerChoice!=3)
			{	std::cout << "Invalid input, enter int value menu choice between 1 and 3" << "\n"; }
		  } while ((playerChoice!= 1) && (playerChoice!=2) && (playerChoice!=3)); 

			if (playerChoice==1)
			{
				interactWithPrisoner1();
			}

			if (playerChoice==2)
			{
				interactWithPrisoner2();
			}

			if (playerChoice==3)
			{
				getFood(p); //used to feed Prisoner 1 who helps share details on escape routes
			}
			
}
}

/**************************************************************
 * void getMap(Player* &p)- adds map to player container
 *************************************************************/

void Dungeon::getMap(Player* p)
{
std::cout << "\n" << "\n";
std::cout << "Prisoner 2 may not look like much now, but he was sharp as a whip back when he was making his escape runs" << "\n"; 
std::cout << "Just very unlucky and learned the hard way to wait for the opportune time" << "\n"; 
std::cout << "The map is accurate and there are at least 2 ways out of this place" << "\n"; 
std::cout << "He told me but with this old age I can't remember anymore" << "\n"; 
std::cout << "ahhh some of it is coming back" << "\n"; 
std::cout << "If you run into the friar, treat yourself to some of whatever is cooking. No finer cook in all the kingdoms!" << "\n"; 
std::cout << "He's a bit of a drinker, you fill his cup and all the castle's secrets come pouring out the friar without filter. Keep on pouring him up to get the good intel"  << "\n"; 
std::cout << "I think that's where Prisoner 2 originally got his map and ideas on escape routes" << "\n";
std::cout << "Now just cus you got a map, don't go wasting all your time looking through it" << "\n";  
std::cout << "Damnit....I seem to forget more every year. Not a lot of mental stimuli down here..." << "\n"; 
 
haveMap=true;

p->playerGetItem(mapPtr); //stores map Item in player container
}

/**************************************************************
 * void getFood(Player* p)- adds food/slop to player container
 **************************************************************/

void Dungeon::getFood(Player* p)
{
p->playerGetItem(slopPtr);  
}

/***************************************************************************
 * void Dungeon::feedPrisoner1()- once fed, the prisoner helps you devise
 * an escape plan 
 ***************************************************************************/

void Dungeon::feedPrisoner1()
{
	std::cout << "\n" << "\n" << "Thank you, they don't feed us enough here. Which is why I'm all skin and bones" << "\n"; 
	std::cout << "Bread and the occassional stray rat is about the only thing keeping me alive down here" << "\n"; 
	std::cout << "As you can tell, Prisoner 2 is not much for company" << "\n"; 
	std::cout << "They locked the young buck in solitary after his third botched escape plan" << "\n"; 
	std::cout << "Hasn't been the same since. What're you in for anyways, ahhh....no bother." << "\n"; 
	std::cout << "I'm much too old and easily recognized to try and escape....but we gotta get you the hell outta here" << "\n"; 
	std::cout << "This place is decently guarded, but I have some close kept secrets and tips that may help you make an escape" << "\n"; 
	std::cout << "Each time Prisoner 2 failed, we got more detail and he even sketched out a map, before he lost his mind" << "\n"; 
	
	prisoner1Fed=true; //this bool sets bool conditions within menu, so you get different options after  
}

/***************************************************************************
 * void Dungeon::interactWithPrisoner1()- based on how many times you have
 * talked with him, different bools are set and he says something different
 * next 
 **************************************************************************/

void Dungeon::interactWithPrisoner1() //all tell you things
{

	std::cout << "\n" << "\n"; 
	
	if (prisoner1Fed==true)
	{
		std::cout << "What you still talking to me for!? Go on' get! Half the guards are out parading for the ceremonies all week, no better time to make your escape then today" << "\n"; 
		std::cout << "Your wasting time! At dusk, all the guards are back and you'll be stuck here, eating slop a full year until the next medieval games tournament" << "\n"; 
	}
	
	if (prisonerTalkMultiple==true && prisoner1Fed==false)
	{	std::cout << "Go ahead and rot away in this cell then. I know you aren't planning on eating that. Toss it over and we'll hitch a plan to get you out of here" << "\n"; 
	}

	if (prisonerTalk1==true && prisoner1Fed==false && prisonerTalkMultiple==false)
	{	std::cout << "So damn hungry, c'mon jolly old lad, toss me some of that there bread you haven't touched" << "\n"; 
		std::cout << "You need allies down here" << "\n"; 
		prisonerTalkMultiple=true;
	}

	if (prisonerTalk1==false)	
	{	std::cout << "Wasted youth...this is no place for a young lad..." << "\n"; 
		prisonerTalk1=true; 
	}

}

/*********************************************************************
 * void Dungeon::interactWithPrisoner2()- not a very helpful fellow
 *********************************************************************/

void Dungeon::interactWithPrisoner2() //a bit deranged 
{
	std::cout << "\n" << "Despite varied attemps to get Prisoner 2's attention, he continues to blankly scan the wall from corner to corner" << "\n"; 
}

/****************************************************************************
 * void Dungeon::escapeToHatch(Space* &s)- uses game object Space pointer 
 * and address to move to kitchen and set the Space pointer to the kitchen
 * address
 ****************************************************************************/

void Dungeon::escapeToHatch(Space* &s)
{
	dungeonTracePtr= s; 
	
	dungeonTracePtr= dungeonTracePtr->top;

	s = dungeonTracePtr; //navigates you to kitchen through Linked Structure 
	
	dungeonTracePtr= NULL;
}

/*********************************************************************
 * void Dungeon::deleteItem(Item* x)
 ***********************************************************************/

void Dungeon::deleteItem(Item* x)  
{
	delete x; 
	x= NULL; 
}

/******************************************************************************
 * void Dungeon::checkItems(Player* p)- used to check if you have food item
 * for use and sets hasFood bool conditional to true if so
 *****************************************************************************/


void Dungeon::checkItems(Player* p)
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
  	
	
	/*for (int i=0; i<checkItems.size(); i++)
	{
	  std::cout << "Check Item " << i+1 << ": " << checkItems[i] << "\n"; 
	}*/

	hasFood= std::binary_search (checkItems.begin(), checkItems.end(), "slop");
	

	//std::cout << "Has Food: " << hasFood << "\n";
}

/********************************************************************************
 * void Dungeon::checkMap(Player* p)- checks if you have map, if so, it calls to
 * the function print to do, otherwise notifies the player of no map
 ********************************************************************************/

void Dungeon::checkMap(Player* p)
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

/****************************************************************************
 * void Dungeon::print(Player* p)- Map marked with X in dungeon location
 ***************************************************************************/

void Dungeon::print(Player* p)
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
std::cout << "|OOOOOOOOOO|>>>>>>|OOOOOOOO|^^^^^^^|OOOOOOOO~~~~~~~~~~~~~ O#" << "\n";
std::cout << "|OOOOOOOOOO|------|OOOOOOOO|-------|OOOOOOOO<<<<(EXIT)<<< O#" << "\n";	
std::cout << "|OOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOOOOOOO~~~~~~~~~~~~~ O#" << "\n"; 
std::cout << "|OOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n"; 
std::cout << "|OOOOOOOOOOOO | OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|-------| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|^^^^^^^| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|^^^X^^^| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << " BSMT Level" << "\n";
std::cout << "|OOOOOOOOO|^^(D)^^| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "|OOOOOOOOO|-------| OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO#" << "\n";
std::cout << "############################################################" << "\n";
std::cout << "\n" << "\n"; 
}	
