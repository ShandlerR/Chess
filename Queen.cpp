/***********************************************************************
 * Source File:
 *    QUEEN: Queen's main functionality
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    All of the Queen's functionality is calculated here.
 ************************************************************************/
#include "Piece.h"
#include "Move.h"
#include "Board.h"

/***********************************************
* QUEEN : CONSTRUCTOR
**********************************************/
Queen::Queen()
{
   type = Type::QUEEN;
}

/***********************************************
* QUEEN::GET MOVES
* Calculates all the possible moves for Queen.
***********************************************/
std::set <Move> Queen::getMoves(const Board* board) const
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

   RC moves[8] =
   {
      {-1,  1}, {0,  1}, {1,  1},
      {-1,  0},          {1,  0},
      {-1, -1}, {0, -1}, {1, -1}
   };

   for (int i = 0; i < 8; i++)
   {
      r = row + moves[i].row;
      c = col + moves[i].col;

      while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
         board->getPiece(c, r)->getType() == Type::SPACE)
      {
         Position pDes(c, r);
         Move mDes(position, pDes);
         possible.insert(mDes);

         r += moves[i].row;
         c += moves[i].col;
      }

      if (amBlack && board->getPiece(c, r) != NULL && !board->getPiece(c, r)->getColor())
      {
         Position pDes(c, r);
         Move mDes(position, pDes);
         possible.insert(mDes);
      }

      if (!amBlack && board->getPiece(c, r) != NULL && board->getPiece(c, r)->getColor())
      {
         Position pDes(c, r);
         Move mDes(position, pDes);
         possible.insert(mDes);
      }
   }

   return possible;
}