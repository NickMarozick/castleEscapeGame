/*************************************************
 * Author: Nick Marozick
 * Description: Item Class Implementation File 
 * Date: 11/27/17
 ************************************************/

#include <iostream> 
#include <string>
#include "item.hpp"

/***************************************************
 * Item::Item(std::string x) 
 ****************************************************/

Item::Item(std::string x)
{
name= x; 
}

/**********************************************************
 * std::string Item::getName()- return name of item
 **********************************************************/

std::string Item::getName()
{
	return name; 
}
