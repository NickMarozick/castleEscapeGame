/********************************************
 * Author: Nick Marozick
 * Description: GateExit Class Header File 
 * Date: 12/2/17
 *******************************************/

#include <iostream>
#include <vector>
#include <string>
#include "space.hpp" 
#include "item.hpp"
#include "player.hpp" 

#ifndef GATEEXIT_HPP
#define GATEEXIT_HPP 

class GateExit: public Space
{
public: 
GateExit(std::string); 

virtual void menu(Player* p, Space* &s);  
virtual void print(Player* p); 
virtual std::string getName();

};

#endif
