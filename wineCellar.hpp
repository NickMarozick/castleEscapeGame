/*********************************************
 * Author: Nick Marozick
 * Description: WineCellar Class Header File 
 * Date: 11/27/17
 ********************************************/

#include <iostream>
#include <vector>
#include <string>
#include "space.hpp" 
#include "item.hpp"
#include "player.hpp" 

#ifndef WINECELLAR_HPP
#define WINECELLAR_HPP 

class WineCellar: public Space
{
public: 
WineCellar(std::string); 

virtual void menu(Player* p, Space* &s);  
virtual void print(Player* p); 
virtual std::string getName();
void headToTownExit(Space* &s);
void drinkWine();  
void hopInBarrel(Space* &s);  
void checkMap(Player* p); 
bool drink1;
bool drink2; 

Space* wTracePtr; 

};
#endif 
