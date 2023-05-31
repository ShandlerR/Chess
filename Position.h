/***********************************************************************
 * Header File:
 *    POSITION: Pieces' and board position happens here.
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    Everything to do with position of the pieces and board is calculated
 *    here.
 ************************************************************************/
#pragma once

class Position
{
public:
   // Constructor
   Position() { location = 1; }
   Position(int location) { this->location = location; }
   Position(char x, char y);

   // Getters
   char getLocation()const { return location; }
   char getX() const { return location % 8; }
   char getY() const { return location / 8; }

   // Setters
   void set(char x, char y) { location = calculateLocation(x, y); }

   void set(int location) { this->location = location; }

   // Methods
   bool operator<(const Position& rhs) const { return this->location < rhs.location; }

private:
   // Attributes
   char location;
   char calculateLocation(char x, char y);
};