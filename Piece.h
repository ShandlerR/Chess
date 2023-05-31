/***********************************************************************
 * Header File:
 *    PIECE: Main functionality of the various chess pieces.
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    All the main function for the different pieces is calculated here.
 ************************************************************************/
#pragma once

#include <set>
#include "Position.h"

class Board;
class Move;

// Enumeration of all the different Chess pieces.
enum class Type { SPACE, KING, QUEEN, BISHOP, ROOK, KNIGHT, PAWN, GENERIC_PIECE };

/***********************************************************************
 * PIECE CLASS
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    All the main function for the different pieces is calculated here.
 ************************************************************************/

struct RC
{
   int col;
   int row;
};

class Piece
{
public:
   // Constructors
   Piece();
   Piece(bool isBlack, Type type);

   // Getters
   Type getType() const { return type; }
   Position getPosition() const { return position; }
   bool getColor() const { return isBlack; }

   // Setters
   void setPosition(Position& position);

   virtual std::set<Move> getMoves(const Board* board) const;


protected:
   // Attributes
   bool isBlack;
   Type type;
   Position position;
};

/***********************************************************************
 * SPACE CLASS :: PIECE CLASS
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    All the main function for Space is calculated here.
 ************************************************************************/
class Space : public Piece
{
public:
   Space();
   Space(Position& position, bool isBlack) : Piece(isBlack, Type::SPACE) { this->position = position; }

   // Getters
   std::set<Move> getMoves(const Board* board) const;
};

/***********************************************************************
 * ROOK CLASS :: PIECE CLASS
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    All the main function for the Rook is calculated here.
 ************************************************************************/
class King : public Piece
{
public:
   // Constructors
   King();
   King(Position& position, bool isBlack) : Piece(isBlack, Type::KING) { this->position = position; }

   // Getters
   std::set<Move> getMoves(const Board* board) const;
};

/***********************************************************************
 * QUEEN CLASS :: PIECE CLASS
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    All the main function for the Queen is calculated here.
 ************************************************************************/
class Queen : public Piece
{
public:
   // Constructors
   Queen();
   Queen(Position& position, bool isBlack) : Piece(isBlack, Type::QUEEN) { this->position = position; }

   // Getters
   std::set<Move> getMoves(const Board* board) const;
};

/***********************************************************************
 * BISHOP CLASS :: PIECE CLASS
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    All the main function for the Bishop is calculated here.
 ************************************************************************/
class Bishop : public Piece
{
public:
   // Constructors
   Bishop();
   Bishop(Position& position, bool isBlack) : Piece(isBlack, Type::BISHOP) { this->position = position; }

   // Getters
   std::set<Move> getMoves(const Board* board) const;
};

/***********************************************************************
 * ROOK CLASS :: PIECE CLASS
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    All the main function for the Rook is calculated here.
 ************************************************************************/
class Rook : public Piece
{
public:
   // Constructors
   Rook();
   Rook(Position& position, bool isBlack) : Piece(isBlack, Type::ROOK) { this->position = position; }

   // Getters
   std::set<Move> getMoves(const Board* board) const;
};

/***********************************************************************
 * KNIGHT CLASS :: PIECE CLASS
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    All the main function for the Rook is calculated here.
 ************************************************************************/
class Knight : public Piece
{
public:
   // Constructors
   Knight();
   Knight(Position& position, bool isBlack) : Piece(isBlack, Type::KNIGHT) { this->position = position; }

   // Getters
   std::set<Move> getMoves(const Board* board) const;
  
};

/***********************************************************************
 * PAWN CLASS :: PIECE CLASS
 * Author:
 *    Shandler Rechenberger & Daryl Appleton
 * Summary:
 *    All the main function for the Pawn is calculated here.
 ************************************************************************/
class Pawn : public Piece
{
public:
   // Constructors
   Pawn();
   Pawn(Position& position, bool isBlack) : Piece(isBlack, Type::PAWN) { this->position = position; }

   // Getters
   std::set<Move> getMoves(const Board* board) const;
};