#pragma once
#include<iostream>
#include<string>
using namespace std;
using std::cout;

class Piece
{
	char color;   // 'W' for White, 'B' for Black
	char symbol;  // 'P', 'R', 'N', etc.
public:
	Piece(char c, char s);

	char getColor();
	char getSymbol();

	virtual bool isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8]) = 0;
	virtual ~Piece();
	static bool rookcheck(int sx, int sy, int ex, int ey, Piece* bord[8][8]);

	// BISHOP
	static bool Bishopcheck(int sx, int sy, int ex, int ey, Piece* bord[8][8]);

	// KNIGHT
	static bool knightcheck(int sx, int sy, int ex, int ey, Piece* bord[8][8]);

	// KING
	static bool Kingcheck(int sx, int sy, int ex, int ey, Piece* bord[8][8]);


};

//***********************child classes of Piece=========

class Pawn : public Piece
{
public:
	Pawn(char c);

	virtual bool isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8]);
};

class Rook : public Piece
{
public:
	Rook(char c);

	virtual bool isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8]);
};

class Knight : public Piece
{
public:
	Knight(char c);

	virtual bool isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8]);
};

class Bishop : public Piece
{
public:
	Bishop(char c);

	virtual bool isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8]);
};

class Queen : public Piece
{
public:
	Queen(char c);

	virtual bool isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8]);
};

class King : public Piece
{
public:
	King(char c);

	virtual bool isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8]);
};


//****************All child classes of Piece end here 

class Board
{
	Piece* board[8][8];
public:
	Board();

	void displayBoard();

	bool movePiece(int sx, int sy, int ex, int ey, char currentTurn);
	bool isKingInCheck(char color);
	bool isCheckmate(char color);
	void pawnPromotion(int ex, int ey, char currentTurn);
	bool isStaleMate(char color);
	~Board();
};


class Game
{
	Board board;
	char currentTurn;
public:
	void run();
};
