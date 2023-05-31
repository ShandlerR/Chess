/***********************************************************************
 * Source File:
 *    PAWN: Pawn's main functionality
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    All of the Pawn's functionality is calculated here.
 ************************************************************************/
#include "Piece.h"
#include "Move.h"
#include "Board.h"

 /***********************************************
 * PAWN : CONSTRUCTOR
 **********************************************/
Pawn::Pawn()
{
   type = Type::PAWN;
}

/***********************************************
* PAWN::GET MOVES
* Calculates all the possible moves for Pawn.
***********************************************/
std::set <Move> Pawn::getMoves(const Board* board) const
{
   std::set <Move> possible;
   int location = position.getLocation();

   // return the empty set if there simply are no possible moves

   if (position.getLocation() < 0 || position.getLocation() >= 64 || getType() == Type::SPACE)
      return possible;
   int row = position.getY();  // current location row
   int col = position.getX();  // current location column
   int r;                      // the row we are checking
   int c;                      // the column we are checking
   bool amBlack = isBlack;

   c = col;
   r = row + 2;

   if(amBlack == true)
   {
      if (row == 1 && board->getPiece(c, r)->getType() == Type::SPACE)
      {
         Position pDes(c, r);
         Move mDes(position, pDes);
         possible.insert(mDes);  // forward two blank spaces
      }

      r = row + 1;

      if (r >= 0 && board->getPiece(c, r)->getType() == Type::SPACE)
      {
         Position pDes(c, r);
         Move mDes(position, pDes);
         possible.insert(mDes);  // forward one black space
      }

      c = col + 1;

      if (board->getPiece(c, r) != NULL && !board->getPiece(c, r)->getColor())
      {
         Position pDes(c, r);
         Move mDes(position, pDes);
         possible.insert(mDes);    // attack left
      }

      c = col - 1;

      if (board->getPiece(c, r) != NULL && !board->getPiece(c, r)->getColor())
      {
         Position pDes(c, r);
         Move mDes(position, pDes);
         possible.insert(mDes);    // attack right
         // what about en-passant and pawn promotion
      }
   }

   if (amBlack == false)
   {
      c = col;
      r = row - 2;

      if (row == 6 && board->getPiece(c, r)->getType() == Type::SPACE)
      {
         Position pDes(c, r);
         Move mDes(position, pDes);
         possible.insert(mDes);  // forward two blank spaces
      }

      r = row - 1;

      if (r < 8 && board->getPiece(c, r)->getType() == Type::SPACE)
      {
         Position pDes(c, r);
         Move mDes(position, pDes);
         possible.insert(mDes);  // forward one black space
      }

      c = col - 1;

      if (board->getPiece(c, r) != NULL && (board->getPiece(c, r)->getColor() && board->getPiece(c, r)->getType() != Type::SPACE))
      {
         Position pDes(c, r);
         Move mDes(position, pDes);
         possible.insert(mDes);    // attack left
      }

      c = col + 1;

      if (board->getPiece(c, r) != NULL && (board->getPiece(c, r)->getColor() && board->getPiece(c, r)->getType() != Type::SPACE))
      {
         Position pDes(c, r);
         Move mDes(position, pDes);
         possible.insert(mDes);    // attack right
         // what about en-passant and pawn promotion
      }
   }

   return possible;
}