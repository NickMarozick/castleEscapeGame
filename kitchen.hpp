/******************************************
 * Author: Nick Marozick
 * Description: Kitchen Class Header File 
 * Date: 11/27/17
 *******************************************/

#include <iostream>
#include <vector>
#include <string>
#include "space.hpp" 
#include "item.hpp"
#include "player.hpp"

#ifndef KITCHEN_HPP
#define KITCHEN_HPP 

class Kitchen: public Space
{
public:
Kitchen(std::string); 

virtual void print(Player* p);
virtual void menu(Player*, Space* &s);  
void getTurkeyLeg(Player*);
virtual std::string getName(); 

void serveFriarMead(); 
void eatFood(); 
void enterBarracks(Space* &s);
void deleteItem(Item*); 
void checkMap(Player* p);

Item* turkeyLegPtr; 
Space* kTracePtr; 
bool hasTurkeyLeg=false; 
bool firstDrink= false;
bool secondDrink= false;
bool thirdDrink= false;

}; 

#endif
