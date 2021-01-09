/******************************************
 * Author: Nick Marozick
 * Description: Space Class Header File 
 * Date: 11/27/17
 *******************************************/

#include <iostream>
//#include <vector>
#include <string>
#include "player.hpp" 

#ifndef SPACE_HPP
#define SPACE_HPP

class Space //abstract class 
{
public: 

virtual void menu(Player* p, Space* &s)=0; //menu function called in all space classes before every move 
virtual void print(Player* p)=0; 
virtual std::string getName()=0; 

Space* top; 
Space* bottom;
Space* left;	
Space* right; 

std::string spaceName;	
	
}; 

#endif 
