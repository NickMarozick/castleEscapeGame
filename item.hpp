/***********************************************
 * Author: Nick Marozick
 * Description: Item Header File 
 * Date: 11/27/17
 **********************************************/

#include <iostream>
#include <string>

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{

public: 	
Item(std::string);
std::string getName(); 

protected:
std::string name;	
	
};

#endif 
