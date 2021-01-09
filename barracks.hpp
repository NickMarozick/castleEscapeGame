/*********************************************
 * Author: Nick Marozick
 * Description: Barracks Class Header File 
 * Date: 11/27/17
 ********************************************/

#include <iostream>
#include <vector>
#include <string>
#include "space.hpp" 
#include "item.hpp"
#include "player.hpp"

#ifndef BARRACKS_HPP
#define BARRACKS_HPP

class Barracks: public Space
{
public: 
Barracks(std::string);
virtual void menu(Player* p, Space* &s);  
virtual void print(Player*); 
virtual std::string getName();
void deleteItem(Item*);
void readGuardManual(Player* p);  
void getGuardArmor(Player* p); 
void getGuardID(Player* p); 
void enterGuardedHall(Space* &s); 
void headBackToKitchen(Space* &s);
void checkMap(Player*);
bool readManual=false;  
bool hasGuardArmor=false; 
bool hasGuardID= false; 

Space* bTracePtr; 

Item* guardUniformPtr;
Item* guardIDPtr;

};

#endif 
