/***********************************************************************
 * Header File:
 *    TEST KING: All the test cases for the king happen here.
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    Test cases for the king
 ************************************************************************/
#pragma once

#include <cassert>
#include "Board.h"
#include "Piece.h"
#include "Position.h"
#include "Move.h"

class TestKing
{
public:
   void run()
   {
      testEmptyBoard();
      testDefaultConstructor();
      testAssignBoard();
      testGetMovesFree();
   }

private:
   /***********************************************
    * TEST BOARD
    **********************************************/
   void testEmptyBoard()
   {
      // Set up
      Board b;

      // Exercise

      // Verify
      for (char y = 1; y < 8; y++)
      {
         for (char x = 1; x < 8; x++) {
            assert(b.getPiece(x, y)->getType() == Type::SPACE);
         }
      }
   }

   void testDefaultConstructor()
   {
      //Setup

      //Exercise
      King* k = new King;

      // Verify
      assert(k->getType() == Type::KING);
   }

   void testAssignBoard()
   {
      //Setup
      Board b;
      King* k = new King;

      Position p;

      p.set(7, 7);

      k->setPosition(p);

      //Exercise
      b.assign(k);

      // Verify
      assert(b.getPiece(7, 7)->getType() == Type::KING);
      assert(b.getPiece(2, 1)->getType() == Type::SPACE);
   }

   /*************************************
  * GET MOVES TEST - White king, free
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6         ~ ~ ~       6
  * 5         ~ k ~       5
  * 4         ~ ~ ~       4
  * 3                     3
  * 2                     2
  * 1                     1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  *************************************/

   void testGetMovesFree()
   {
      // setup
      Board b;
      King* k = new King;
      Position p;

      p.set(5, 5);
      k->setPosition(p);

      b.assign(k);

      // Exercise
      std::set<Move> moves = k->getMoves(b.getBoard());

      //p.getX()
      //p.getY()

      // Verify
      assert(moves.size() == 8);
   }
};