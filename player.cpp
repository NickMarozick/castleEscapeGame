/*************************************************
 * Author: Nick Marozick
 * Description: Player Class Implementation File 
 * Date: 11/27/17
 *************************************************/

#include <iostream> 
#include <vector> 
#include "item.hpp" 
#include "space.hpp"


/*************************************************************
 * Player::Player() - player default constructor
 ***************************************************************/

Player::Player() 
{

for (int i=0; i<6; i++)
{
	carriedItems[i]= NULL; 
}
}

/***************************************************************
 * void Player::playerGetItem(Item* &x) - adds item to player
 * item container 
 ***************************************************************/

void Player::playerGetItem(Item* &x)
{
int i=0; 

if (carriedItems[i]==NULL)
{
	carriedItems[i]= x;
}

else{
	while (carriedItems[i]!=NULL)
	{
		i++;
	}
	
	carriedItems[i]= x;}
		
}  

