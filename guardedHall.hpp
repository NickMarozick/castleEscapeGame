/***********************************************
 * Author: Nick Marozick
 * Description: GuardedHall Class Header File 
 * Date: 11/27/17
 ***********************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "space.hpp" 
#include "item.hpp"
#include "player.hpp"


#ifndef GuardedHall_HPP
#define GuardedHall_HPP 

class GuardedHall: public Space
{
public: 
GuardedHall(std::string); 

virtual void menu(Player* p, Space* &s);  
virtual void print(Player*);
virtual std::string getName(); 

void checkItems(Player* p);
void approachGuards(Player* p, Space* &s); //need ID & Armor to pass 
void feedHound(Player* p); // option available based on checkItems 
void wait(); //wait for hound to fall asleep 

void caughtByGuards(Player* p, Space* &s);
void caughtByHound(Player* p, Space* &s);  

void headBacktoBarracks(Space* &s); 
void headToTheWall(Space* &s);
void headToWineCellar(Space* &s); 
void checkMap(Player*); 

Space* gHTracePtr; 

bool hasArmor=false; //set based on binarySearch conditions 
bool hasGuardID=false; //set based on binarySearch conditions
bool hasFood=false; 

bool houndSleep= false; 
bool houndFed= false;  
};

#endif
