/***********************************************************************
 * Source File:
 *    POSITION: Pieces' and board position happens here.
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    Everything to do with position of the pieces and board is calculated
 *    here.
 ************************************************************************/
#include "Position.h"

/***************************************************
* POSITION : CONSTRUCTOR
***************************************************/
Position::Position(char x, char y)
{
   location = calculateLocation(x, y);
}

/***************************************************
* POSITION : CALCULATE LOCATION
***************************************************/
char Position::calculateLocation(char x, char y)
{
   return (8 * y + x);
}