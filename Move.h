/***********************************************************************
 * Header File:
 *    Move class: Everything about how pieces move happens here.
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    This code handles anything to do with the move.
 ************************************************************************/
#pragma once
#include "Position.h"

class Move
{

public:
   // Constructor
   Move(Position source, Position destination);

   // Getters
   Position getSource() const { return source; }
   Position getDestination() const { return destination; }
   
   //Setters

   // Methods
   bool operator==(Move& rhs) const;
   bool operator<(const Move& rhs) const { return this->destination < rhs.destination; }

private:
   // Attributes
   Position source;
   Position destination;
};