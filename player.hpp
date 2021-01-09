/*********************************************
 * Author: Nick Marozick
 * Description: Player Class Header File 
 * Date: 11/27/17
 ********************************************/

#include <iostream> 
#include <vector> 
#include <string>
#include "item.hpp" 


#ifndef PLAYER_HPP
#define PLAYER_HPP 

class Player
{
public: 

Player(); 

void playerGetItem(Item* &x);  

std::vector<Item*> carriedItems {NULL, NULL, NULL, NULL, NULL, NULL};
  
}; 

#endif
