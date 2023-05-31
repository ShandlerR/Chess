/***********************************************************************
 * Source File:
 *    Move class: Everything about how pieces move happens here.
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    This code handles anything to do with the move.
 ************************************************************************/
#include "Move.h"
#include "Position.h"

/***********************************************
* MOVE : CONSTRUCTOR
**********************************************/
Move::Move(Position source, Position destination)
{
   this->source.set(source.getLocation());
   this->destination.set(destination.getLocation());
}

/***********************************************
* MOVE : EQUALITY
**********************************************/
bool Move::operator==(Move& rhs) const
{
   if (source.getX() == rhs.getSource().getX() && source.getY() == rhs.getSource().getY())
   {
      if (destination.getX() == rhs.getDestination().getX() && destination.getY() == rhs.getDestination().getY())
      {
         return true;
      }
   }
   return false;
}