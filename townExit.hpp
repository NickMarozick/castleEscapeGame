/********************************************
 * Author: Nick Marozick
 * Description: TownExit Class Header File 
 * Date: 12/2/17
 *******************************************/

#include <iostream>
#include <vector>
#include <string>
#include "space.hpp" 
#include "item.hpp"
#include "player.hpp" 

#ifndef TOWNEXIT_HPP
#define TOWNEXIT_HPP 

class TownExit: public Space
{
public: 
TownExit(std::string); 

virtual void menu(Player* p, Space* &s);  
virtual void print(Player*); 
virtual std::string getName();

};

#endif
