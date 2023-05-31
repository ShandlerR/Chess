/***********************************************************************
 * CPP File:
 *    SPACE: Represents the empty space on the board
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    Space is a type of piece
 ************************************************************************/
#include "Piece.h"
#include "Move.h"

Space::Space()
{
   type = Type::SPACE;
}

std::set <Move> Space::getMoves(const Board* board) const
{
   std::set <Move> possible;
   return possible;
}