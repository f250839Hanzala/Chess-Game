#include "Header.h"

Piece::Piece(char c, char s)
	:color(c), symbol(s)
{

}

char Piece::getColor()
{
	return color;
}
char Piece::getSymbol()
{
	return symbol;
}


Piece::~Piece()
{
}

bool Piece::rookcheck(int sx, int sy, int ex, int ey, Piece* board[8][8])
{
	bool check = true;
	if (ex == sx && ey == sy)
		return false;

	int temprow = 0, tempcol = 0;
	if (sx - ex < 0)
		temprow = ex - sx;
	else if (sx - ex > 0)
		temprow = sx - ex;
	else
		temprow = sx;

	if (sy - ey < 0)
		tempcol = ey - sy;
	else if (sy - ey > 0)
		tempcol = sy - ey;
	else
		tempcol = sy;

	if (ex == sx) {
		if (ey > sy) {
			for (int i = 1; i < tempcol; i++) {
				if (board[sx][sy + i] != nullptr)
					return false;
			}
		}
		else if (ey < sy) {
			for (int i = 1; i < tempcol; i++) {
				if (board[sx][sy - i] != nullptr)
					return false;
			}
		}
	}
	else if (ey == sy) {
		if (ex < sx) {
			for (int i = 1; i < temprow; i++) {
				if (board[sx - i][sy] != nullptr)
					return false;
			}
		}
		else if (ex > sx) {
			for (int i = 1; i < temprow; i++) {
				if (board[sx + i][sy] != nullptr)
					return false;
			}
		}
	}
	else {
		return false; // Not a straight line
	}
	return check;
}

bool Piece::Bishopcheck(int sx, int sy, int ex, int ey, Piece* board[8][8])
{
	bool check = true;
	if (ex == sx && ey == sy)
		return false;

	int temprow = 0, tempcol = 0;
	if (sx - ex < 0)
		temprow = ex - sx;
	else if (sx - ex > 0)
		temprow = sx - ex;

	if (sy - ey < 0)
		tempcol = ey - sy;
	else if (sy - ey > 0)
		tempcol = sy - ey;
	//moves diagonally dpwn towards right
	if (temprow == tempcol) {
		if (ex > sx && ey > sy) {
			for (int i = 1; i < temprow; i++) {
				if (board[sx + i][sy + i] != nullptr)
				{
					return false;
				}
			}
		}
		//moves diagonally
		else if (ex < sx && ey > sy) {
			for (int i = 1; i < temprow; i++) {
				if (board[sx - i][sy + i] != nullptr)
					return false;
			}
		}
		else if (ex > sx && ey < sy) {
			for (int i = 1; i < temprow; i++) {
				if (board[sx + i][sy - i] != nullptr)
					return false;
			}
		}
		else if (ex < sx && ey < sy) {
			for (int i = 1; i < temprow; i++) {
				if (board[sx - i][sy - i] != nullptr)
					return false;
			}
		}
	}
	else {
		return false; // Not a diagonal line
	}
	return check;
}

bool Piece::knightcheck(int sx, int sy, int ex, int ey, Piece* board[8][8])
{
	if (ex == sx && ey == sy)
		return false;

	if (ex == sx + 2 && ey == sy + 1)
		return true;
	else if (ex == sx + 1 && ey == sy + 2)
		return true;
	else if (ex == sx + 2 && ey == sy - 1)
		return true;
	else if (ex == sx + 1 && ey == sy - 2)
		return true;
	else if (ex == sx - 1 && ey == sy + 2)
		return true;
	else if (ex == sx - 2 && ey == sy + 1)
		return true;
	else if (ex == sx - 1 && ey == sy - 2)
		return true;
	else if (ex == sx - 2 && ey == sy - 1)
		return true;

	return false;
}

bool Piece::Kingcheck(int sx, int sy, int ex, int ey, Piece* board[8][8])
{
	if (ex == sx && ey == sy)
		return false;

	int temprow = sx - ex;
	int tempcol = sy - ey;

	if (temprow < 0)
		temprow = -temprow;
	if (tempcol < 0)
		tempcol = -tempcol;

	if (temprow <= 1 && tempcol <= 1)
	{
		return true;
	}
	return false;
}

//***********************child classes of Piece=========

Pawn::Pawn(char c)
	:Piece(c, 'P')
{
}

bool Pawn::isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8])
{


	if (this->getColor() == 'W')
	{
		// White initial 2-step
		if (sx == 6 && board[sx - 1][sy] == nullptr)
		{
			if (ex == sx - 2 && ey == sy && board[ex][ey] == nullptr)
			{
				return true;
			}
		}
		// White 1-step
		if (ex == sx - 1 && ey == sy && board[ex][ey] == nullptr)
		{
			return true;
		}
		// White diagonal capture
		else if (ex == sx - 1 && (ey == sy - 1 || ey == sy + 1) &&
			board[ex][ey] != nullptr && board[ex][ey]->getColor() != 'W')
		{
			return true;
		}
	}
	else
	{
		// Black initial 2-step
		if (sx == 1 && board[sx + 1][sy] == nullptr)
		{
			if (ex == sx + 2 && ey == sy && board[ex][ey] == nullptr)
			{
				return true;
			}
		}
		// Black 1-step
		if (ex == sx + 1 && ey == sy && board[ex][ey] == nullptr)
		{
			return true;
		}
		// Black diagonal capture
		else if (ex == sx + 1 && (ey == sy - 1 || ey == sy + 1) &&
			board[ex][ey] != nullptr && board[ex][ey]->getColor() != 'B')
		{
			return true;
		}
	}

	return false;
}

Rook::Rook(char c)
	:Piece(c, 'R')
{
}

bool Rook::isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8])
{
	return rookcheck(sx, sy, ex, ey, board);
}

Knight::Knight(char c)
	:Piece(c, 'N')
{
}

bool Knight::isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8])
{
	return knightcheck(sx, sy, ex, ey, board);
}

Bishop::Bishop(char c) :Piece(c, 'B')
{
}

bool Bishop::isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8])
{
	return Bishopcheck(sx, sy, ex, ey, board);
}

Queen::Queen(char c) :Piece(c, 'Q')
{
}

bool Queen::isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8])
{
	if (Bishopcheck(sx, sy, ex, ey, board) == true || rookcheck(sx, sy, ex, ey, board) == true)
	{
		return true;
	}
	else
		return false;
}

King::King(char c) :Piece(c, 'K')
{
}

bool King::isLegalMove(int sx, int sy, int ex, int ey, Piece* board[8][8])
{
	return Kingcheck(sx, sy, ex, ey, board);
}


//****************All child classes of Piece end here 

Board::Board()
{

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = nullptr;

	// Place White pieces (row 7)
	board[7][0] = new Rook('W');
	board[7][1] = new Knight('W');
	board[7][2] = new Bishop('W');
	board[7][3] = new Queen('W');
	board[7][4] = new King('W');
	board[7][5] = new Bishop('W');
	board[7][6] = new Knight('W');
	board[7][7] = new Rook('W');

	// Place White Pawns (row 6)
	for (int j = 0; j < 8; j++)
		board[6][j] = new Pawn('W');

	// Place Black pieces (row 0)
	board[0][0] = new Rook('B');
	board[0][1] = new Knight('B');
	board[0][2] = new Bishop('B');
	board[0][3] = new Queen('B');
	board[0][4] = new King('B');
	board[0][5] = new Bishop('B');
	board[0][6] = new Knight('B');
	board[0][7] = new Rook('B');

	//  Place Black Pawns (row 1)
	for (int j = 0; j < 8; j++)
		board[1][j] = new Pawn('B');
}

void Board::displayBoard()
{
	cout << "  a b c d e f g h" << endl << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << (8 - i) << " ";

		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == nullptr)
			{
				cout << "-" << " ";
			}
			else
			{
				if (board[i][j]->getColor() == 'B')
				{
					cout << "\033[34m" << board[i][j]->getSymbol() << "\033[0m" << " ";
				}
				else
				{
					cout << "\033[97m" << board[i][j]->getSymbol() << "\033[0m" << " ";
				}
			}
		}
		cout << endl;
	}

}

bool Board::movePiece(int sx, int sy, int ex, int ey, char currentTurn)
{

	// 1. Destination must be inside the board

	if (ex < 0 || ex > 7 || ey < 0 || ey > 7 || sx < 0 || sx >7 || sy < 0 || sy > 7)
	{
		cout << "Out of bounds!" << endl;
		return false;
	}

	// 2. Source must not be empty

	if (board[sx][sy] == nullptr)
	{
		cout << "No piece at source!" << endl;
		return false;
	}

	// 3. Cannot capture your own piece

	// Player must move their OWN piece
	if (board[sx][sy]->getColor() != currentTurn) {
		cout << "That is not your piece!" << endl;
		return false;
	}

	if (board[ex][ey] != nullptr && board[ex][ey]->getColor() == board[sx][sy]->getColor())
	{
		cout << "Cannot capture your own piece!" << endl;
		return false;
	}

	// 4. Ask the piece itself if the move is legal

	if (!board[sx][sy]->isLegalMove(sx, sy, ex, ey, board))
	{
		cout << "Illegal move for this piece!" << endl;
		return false;
	}

	// SIMULATE THE MOVE 
	// we do not delete the target for the condition "check" 
	Piece* capturedPiece = board[ex][ey];
	board[ex][ey] = board[sx][sy];
	board[sx][sy] = nullptr;

	// CHECK IF THIS MOVE PUTS/LEAVES CURRENT PLAYER'S KING IN CHECK
	if (isKingInCheck(currentTurn)) {
		// back the move safely
		board[sx][sy] = board[ex][ey];
		board[ex][ey] = capturedPiece;
		cout << "\n=======================================================" << endl;
		cout << "Invalid move: Your King will be in check after this move!" << endl;
		cout << "\n=======================================================" << endl;
		return false;
	}

	// IF SAFE, FINALIZE THE MOVE
	if (capturedPiece != nullptr) {
		delete capturedPiece; // Now it is safe to delete the captured piece if any
	}

	return true;
}

bool Board::isKingInCheck(char color)
{
	int kx = -1, ky = -1;

	// first we will trace the king's location
	//of the specified color
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != nullptr && board[i][j]->getColor() == color && board[i][j]->getSymbol() == 'K')
			{
				kx = i;
				ky = j;
				break;
			}
		}
	}

	// Fail-safe in case King is missing
	if (kx == -1)
		return false;

	//now Checking if any opponent's piece can kill the King
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != nullptr && board[i][j]->getColor() != color)
			{
				if (board[i][j]->isLegalMove(i, j, kx, ky, board)) {
					return true; // The king is in check
				}
			}
		}
	}
	return false;
}

bool Board::isCheckmate(char color)
{
	// If not in check, it can't be checkmate
	if (!isKingInCheck(color))
		return false;

	// Iterate through every piece of the given color
	for (int sx = 0; sx < 8; sx++)
	{
		for (int sy = 0; sy < 8; sy++)
		{
			if (board[sx][sy] != nullptr && board[sx][sy]->getColor() == color)
			{

				// Test every possible target square on the board for this piece
				for (int ex = 0; ex < 8; ex++)
				{
					for (int ey = 0; ey < 8; ey++)
					{

						// Prevent capturing own pieces
						if (board[ex][ey] != nullptr && board[ex][ey]->getColor() == color)
							continue;

						if (board[sx][sy]->isLegalMove(sx, sy, ex, ey, board))
						{

							// Simulate the move for test
							Piece* capturedPiece = board[ex][ey];
							board[ex][ey] = board[sx][sy];
							board[sx][sy] = nullptr;

							// Does this move make the king safe?
							bool isSafe = !isKingInCheck(color);

							// back the simulation completely
							board[sx][sy] = board[ex][ey];
							board[ex][ey] = capturedPiece;

							// If we found even ONE safe move, it's not checkmate
							if (isSafe) {
								return false;
							}
						}
					}
				}
			}
		}
	}

	// If we travel all moves and none save the king, it's checkmate.
	return true;
}

bool Board::isStaleMate(char color)
{

	// If in check, it can't be stalemate
	if (isKingInCheck(color))
	{
		return false;
	}


	// Iterate through every piece of the given color
	for (int sx = 0; sx < 8; sx++)
	{
		for (int sy = 0; sy < 8; sy++)
		{
			if (board[sx][sy] != nullptr && board[sx][sy]->getColor() == color)
			{

				// Test every possible target square on the board for this piece
				for (int ex = 0; ex < 8; ex++)
				{
					for (int ey = 0; ey < 8; ey++)
					{

						// Prevent capturing own pieces
						if (board[ex][ey] != nullptr && board[ex][ey]->getColor() == color)
							continue;

						if (board[sx][sy]->isLegalMove(sx, sy, ex, ey, board))
						{

							// Simulate the move for test
							Piece* capturedPiece = board[ex][ey];
							board[ex][ey] = board[sx][sy];
							board[sx][sy] = nullptr;

							// Does this move make the king safe?
							bool isSafe = !isKingInCheck(color);

							// back the simulation completely
							board[sx][sy] = board[ex][ey];
							board[ex][ey] = capturedPiece;

							// If we found even ONE safe move, it's not stalemate
							if (isSafe) {
								return false;
							}
						}
					}
				}
			}
		}
	}

	return true;
}

void Board::pawnPromotion(int ex, int ey, char currentTurn)
{
	if (currentTurn == 'W')
	{
		if (board[ex][ey]->getSymbol() == 'P' && ex == 0)
		{
			bool valid = false;
			while (!valid)
			{
				cout << "\n=================================";
				cout << "\n=================================";
				cout << "Pawn is reached at the last row " << endl;
				cout << "In What piece you want to protmote it" << endl;
				cout << "Enter Q for Queen" << endl;
				cout << "Enter R for Rook" << endl;
				cout << "Enter B for Bishop" << endl;
				cout << "Enter N for Knight" << endl;
				char input;
				cin >> input;
				if (input == 'Q' || input == 'q')
				{
					delete board[ex][ey];
					board[ex][ey] = new Queen('W');
					valid = true;
				}
				else if (input == 'R' || input == 'r')
				{
					delete board[ex][ey];
					board[ex][ey] = new Rook('W');
					valid = true;
				}
				else if (input == 'B' || input == 'b')
				{
					delete board[ex][ey];
					board[ex][ey] = new Bishop('W');
					valid = true;

				}
				else if (input == 'N' || input == 'n')
				{
					delete board[ex][ey];
					board[ex][ey] = new Knight('W');
					valid = true;
				}
				else
				{
					cout << "Invalid input! Try Again" << endl;
				}
			}
		}
	}
	else
	{
		if (board[ex][ey]->getSymbol() == 'P' && ex == 7)
		{
			bool valid = false;
			while (!valid)
			{
				cout << "\n=================================";
				cout << "\n=================================";
				cout << "Pawn is reached at the last row " << endl;
				cout << "In What piece you want to protmote it" << endl;
				cout << "Enter Q for Queen" << endl;
				cout << "Enter R for Rook" << endl;
				cout << "Enter B for Bishop" << endl;
				cout << "Enter N for Knight" << endl;
				char input;
				cin >> input;
				if (input == 'Q' || input == 'q')
				{
					delete board[ex][ey];
					board[ex][ey] = new Queen('B');
					valid = true;
				}
				else if (input == 'R' || input == 'r')
				{
					delete board[ex][ey];
					board[ex][ey] = new Rook('B');
					valid = true;
				}
				else if (input == 'B' || input == 'b')
				{
					delete board[ex][ey];
					board[ex][ey] = new Bishop('B');
					valid = true;

				}
				else if (input == 'N' || input == 'n')
				{
					delete board[ex][ey];
					board[ex][ey] = new Knight('B');
					valid = true;
				}
				else
				{
					cout << "Invalid input! Try Again" << endl;
				}
			}
		}
	}

}

Board::~Board()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			delete board[i][j];
			board[i][j] = nullptr;
		}
}

void Game::run()
{
	cout << "Welcome to the Chess" << endl << endl;
	string P1, P2;
	cout << "Enter Player 1 name: ";
	cin >> P1;
	cout << "Enter Player 2 name: ";
	cin >> P2;
	system("cls");
	currentTurn = 'W';

	while (true)
	{
		system("cls");
		board.displayBoard();


		if (board.isStaleMate(currentTurn))
		{
			cout << "\n=========================\n";
			cout << "STALEMATE! It's a draw!" << endl;
			cout << "\n=========================\n";
			break;
		}

		// 1. CHECK FOR CHECKMATE FIRST
		// We check this at the start of the turn for the current player
		if (board.isCheckmate(currentTurn))
		{
			cout << "\nCHECKMATE! ";
			if (currentTurn == 'B')
			{
				cout << "\n=========================\n";
				cout << P1 << " (White) wins the game!" << endl;
				cout << "\n=========================\n";
			}
			else
			{
				cout << "\n=========================\n";
				cout << P2 << " (Blue) wins the game!" << endl;
				cout << "\n=========================\n";
			}
			break; // This breaks the while(true) loop and ends the game
		}

		// 2. WARN THE PLAYER IF THEY ARE IN CHECK (But not checkmate)
		if (board.isKingInCheck(currentTurn))
		{
			cout << "\n====================================================\n";
			cout << "\nWARNING: Your King is in CHECK! You must protect it." << endl;
			cout << "\n====================================================\n";
		}

		//display current turn
		if (currentTurn == 'B')
		{
			cout << "Current Turn: " << P2 << "  (Blue)" << endl;
		}
		else
			cout << "Current Turn: " << P1 << "  (White)" << endl;


		int sx, sy, ex, ey;
		char tempX;
		int tempY;
		cout << "Enter the initial coordinates (like a2): ";
		cin >> tempX >> tempY;


		sx = 8 - tempY;       // row
		sy = tempX - 'a';     // col

		cout << "Enter target coordinates: ";
		cin >> tempX >> tempY;
		ex = 8 - tempY;
		ey = tempX - 'a';


		bool success = board.movePiece(sx, sy, ex, ey, currentTurn);

		if (success)
		{
			board.pawnPromotion(ex, ey, currentTurn);
			currentTurn = (currentTurn == 'W') ? 'B' : 'W'; // switch turn5
		}
		else
		{
			cout << "Invalid move, try again!" << endl;
			system("pause");
		}
	}
}