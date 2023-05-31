/***********************************************************************
 * Source File:
 *    BOARD: Represents the chess playBoard
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    Everything to do with the chess playBoard happens here.
 ************************************************************************/
#include "Board.h"
#include "Piece.h"
#include "Position.h"
#include "Move.h"
#include "uiDraw.h"
#include <iostream>
#include <cassert>



 /***************************************************
 * Board : DEFAULT CONSTRUCTOR
 ***************************************************/
Board::Board()
{
   isBlackTurn = false;

   char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
   };

   //char board[64] = {
   //   'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   // ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
   //   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
   //};



   adrawBoard = new ogstream();
   int i = 0;
   for (int y = 0; y < 8; y++)
   {
      for (int x = 0; x < 8; x++)
      {
         Position pos(x, y);
         // Rooks
         if (board[i] == 'r')
            playBoard[i] = new Rook(pos, true);
         else if (board[i] == 'R')
            playBoard[i] = new Rook(pos, false);
         // Knights
         else if (board[i] == 'n')
            playBoard[i] = new Knight(pos, true);
         else if (board[i] == 'N')
            playBoard[i] = new Knight(pos, false);
         // Bishops
         else if (board[i] == 'b')
            playBoard[i] = new Bishop(pos, true);
         else if (board[i] == 'B')
            playBoard[i] = new Bishop(pos, false);
         // Kings
         else if (board[i] == 'k')
            playBoard[i] = new King(pos, true);
         else if (board[i] == 'K')
            playBoard[i] = new King(pos, false);
         // Queens
         else if (board[i] == 'q')
            playBoard[i] = new Queen(pos, true);
         else if (board[i] == 'Q')
            playBoard[i] = new Queen(pos, false);
         // Queens
         else if (board[i] == 'p')
            playBoard[i] = new Pawn(pos, true);
         else if (board[i] == 'P')
            playBoard[i] = new Pawn(pos, false);
         else
            playBoard[i] = new Space(pos, true);
         i++;
      }
   }

}

/***************************************************
* BOARD : DESTRUCTOR
***************************************************/
Board::~Board()
{
   delete adrawBoard;
   for (int i = 0; i < 64; i++)
      delete playBoard[i];
}

/***************************************************
* BOARD : GET PIECE
***************************************************/
Piece* Board::getPiece(char x, char y) const
{
   if (y < 0 || y >= 8 || x < 0 || x >= 8)
      return NULL;

   Position pos(x, y);
   return playBoard[pos.getLocation()];
}

/***************************************************
* BOARD : ASSIGN
***************************************************/
void Board::assign(Piece* p)
{
   delete playBoard[p->getPosition().getLocation()];
   playBoard[p->getPosition().getLocation()] = p;
}


/***************************************************
* BOARD : MOVE
***************************************************/
bool Board::move(const Move& move)
{
   int source = move.getSource().getLocation();
   int des = move.getDestination().getLocation();

   // std::cout << "Source: " << source << "Dest: " << des << std::endl;
   // do not move if a move was not indicated
   if (source == -1 || des == -1)
      return false;
   assert(source >= 0 && des < 64);
   assert(des >= 0 && source < 64);

   // find the set of possible moves from our current location
   std::set <Move> possiblePrevious = playBoard[source]->getMoves(this);
 
   if (possiblePrevious.find(move) != possiblePrevious.end())
   {
      isBlackTurn = !isBlackTurn;
      // Swap
      Piece* temp = playBoard[source];
      Position position(temp->getPosition().getLocation());
      int location = temp->getPosition().getLocation();

      playBoard[source]->setPosition(playBoard[des]->getPosition());
      delete playBoard[des];
      playBoard[des] = playBoard[source];
      
      playBoard[source] = new Space(position, true);
      return true;
   }

   return false;
}
