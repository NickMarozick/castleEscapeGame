/*************************************************
 * Author: Nick Marozick
 * Description: Final Project Main File
 * Date: 12/2/17
 *************************************************/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string> 
#include "game.hpp"

int main()
{
bool go; 

Game game1("Dungeon", "Kitchen", "Barracks", "GuardedHall", "WineCellar", "TheWall", "RiverEscape", "GateEscape"); 

go= game1.gameStartMenu();

if (go==true)
{
	game1.gameOn();
}

return 0; 
}
