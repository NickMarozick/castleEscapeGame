/********************************************
 * Author: Nick Marozick
 * Description: TheWall Class Header File 
 * Date: 11/27/17
 ******************************************/

#include <iostream>
#include <vector>
#include <string>
#include "space.hpp" 
#include "player.hpp"
#include "item.hpp"

#ifndef THEWALL_HPP
#define THEWALL_HPP 

class TheWall: public Space
{
public: 
TheWall(std::string); 

virtual void menu(Player* p, Space* &s); 
virtual void print(Player*); 
virtual std::string getName(); 

void gamble(); // wasting of turns 
void takeShiftOutsidePalace(Space* &s); 
void headToGateExit(Space* &s);
void checkMap(Player*); 

Space* wallTracePtr;

};

#endif  
