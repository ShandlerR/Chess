/***********************************************************************
 * Header File:
 *    Board class: Everything about the board happens here.
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    This code handles anything to do with the board.
 ************************************************************************/
#pragma once
#include "uiDraw.h"

class ogstream;
class Move;
class Piece;

class Board
{
public:
   // Contructors
   Board();
   ~Board();

   // Getters
   Piece* getPiece(char x, char y) const;
   Piece* getBoard() const { return *playBoard; }
   ogstream* getDrawBoard() const { return adrawBoard; }
   bool getTurn() { return isBlackTurn; }

   // Setters
   void assign(Piece* p);
   bool move(const Move &move);

private:
   // Attributes
   ogstream* adrawBoard;
   bool isBlackTurn;
   Piece* playBoard[64];
   // ogstream* drawBoard;
};