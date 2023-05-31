/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include "Board.h"        // for board
#include "Piece.h"
#include "Move.h"
#include <set>            // for STD::SET
#include <cassert>
#include <iostream>
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
using namespace std;

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface* pUI, Board* board)
{
   set <Move> possible;
   board->getDrawBoard()->drawBoard(); // Previous change: ->drawBoard();

   // draw any selections
   board->getDrawBoard()->drawHover((*pUI).getHoverPosition());
   board->getDrawBoard()->drawSelected((*pUI).getSelectPosition());

   // Move
   Position source(pUI->getPreviousPosition());
   Position des(pUI->getSelectPosition());
   Move move(source, des);
   cout << "Pre: " << pUI->getPreviousPosition() << "Selec: " << pUI->getSelectPosition() << endl;
   if (board->move(move))
      pUI->clearSelectPosition();
   else
      if(board->getPiece(des.getX(), des.getY()) != NULL)
         possible = board->getPiece(des.getX(), des.getY())->getMoves(board);//getMoves(board, pUI->getSelectPosition());

   // if we clicked on a blank spot, then it is not selected

   if (pUI->getSelectPosition() != -1 && board->getPiece(des.getX(), des.getY()) != NULL && board->getPiece(des.getX(), des.getY())->getType() == Type::SPACE) //board[pUI->getSelectPosition()] == ' '
      pUI->clearSelectPosition();

   if (board->getPiece(des.getX(), des.getY()) != NULL && board->getPiece(des.getX(), des.getY())->getColor() != board->getTurn())
   { 
      pUI->clearSelectPosition();
   }

   set <Move> ::iterator it;
   for (it = possible.begin(); it != possible.end(); ++it)
      board->getDrawBoard()->drawPossible(*it);

   for (int y = 0; y < 8; y++)
   {
      for (int x = 0; x < 8; x++)
      {
         Piece* piece = board->getPiece(x, y);
         bool isBlack = piece->getColor();
         switch (piece->getType())
         {
            case Type::ROOK:
               board->getDrawBoard()->drawRook(piece->getPosition().getLocation(), isBlack);
               break;
            case Type::KNIGHT:
               board->getDrawBoard()->drawKnight(piece->getPosition().getLocation(), isBlack);
               break;
            case Type::BISHOP:
               board->getDrawBoard()->drawBishop(piece->getPosition().getLocation(), isBlack);
               break;
            case Type::KING:
               board->getDrawBoard()->drawKing(piece->getPosition().getLocation(), isBlack);
               break;
            case Type::QUEEN:
               board->getDrawBoard()->drawQueen(piece->getPosition().getLocation(), isBlack);
               break;
            case Type::PAWN:
               board->getDrawBoard()->drawPawn(piece->getPosition().getLocation(), isBlack);
               break;
         }
      }
   }
}

int main()
{
   Board board;
   Interface ui("Chess");
   ui.run(callBack, &board);
   return 0;
}
