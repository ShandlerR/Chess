/***********************************************************************
 * SOURCE File:
 *    PIECE: Represents all the pieces on the chess board.
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    Everything to do with the pieces on the chess board happens here.
 ************************************************************************/
#include "Piece.h"
#include "Move.h"

 /***************************************************
 * PIECE : DEFAULT CONSTRUCTOR
 ***************************************************/
Piece::Piece()
{
   type = Type::GENERIC_PIECE;
}

Piece::Piece(bool isBlack, Type type)
{
   this->isBlack = isBlack;
   this->type = type;
}

/***************************************************
* PIECE : SET POSITION
***************************************************/
void Piece::setPosition(Position& position)
{
   this->position = Position(position.getLocation());
}

std::set <Move> Piece::getMoves(const Board* board) const
{
   std::set <Move> possible;
   return possible;
}