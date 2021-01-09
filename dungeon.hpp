/***********************************************
 * Author: Nick Marozick
 * Description: Dungeon Class Header File 
 * Date: 11/27/17
 **********************************************/

#include <iostream>
#include <vector>
#include <string>
#include "space.hpp" 
#include "item.hpp" 
#include "player.hpp"

#ifndef DUNGEON_HPP
#define DUNGEON_HPP 

class Dungeon: public Space
{
public:
Dungeon(std::string);
virtual void menu(Player* p, Space* &s); //menu function called in all space classes before every move 
virtual void print(Player* p);
virtual std::string getName();

void getMap(Player* p);
void getFood(Player* p); 
void feedPrisoner1();
void interactWithPrisoner1(); //all tell you things
void interactWithPrisoner2(); //a bit deranged 
void escapeToHatch(Space* &s); 
void deleteItem(Item*); 
void checkItems(Player* p);
void checkMap(Player* p);

protected:
bool prisoner1Fed=false;
bool haveMap=false;
bool prisonerTalk1=false;
bool prisonerTalkMultiple=false;
bool hasFood=false;
Space* dungeonTracePtr;

Item* mapPtr; 
Item* slopPtr;

};

#endif
