#include <vector>
#include <algorithm>
#include <utility>
#include <stack>


#ifndef BOARD_H
#define BOARD_H



typedef std::pair<int, int> position;


/** 
* Class board. It handles the board functions and maintains the board status
* after each move.
**/ 

class board{
	protected:
	char bd[3][3];
	
	public:
	/**
	* An enum
	* The various states the board can be in at a point of time. CONTD signifies
	* the game is not yet over.
	**/
	enum {
		WIN,
		DRAW,
		CONTD,
		INVALID
	};
	
	/**
	* Constructor to initilize all values with a ' '
	**/
	board();
	
	/**
	* Check the status of the game at the point of the call.
	* @param player The player whose status is to be checked
	* @return Value from the enumeration.
	**/
	int check_status(char player);
	
	/**
	* Make a move on the board. 
	* @param player The player making the move. This could either be a 'X' or a 'O'
	* @param pos The position where the player made the move.
	* @return The current status of the board after the move is made.
	**/
	int make_move(char player, position pos);
	
	/**
	* Return the value at a position.
	* @param pos position whose value is to be returned.
	* @return The character at the position pos. ' ' if no player has played the
	* box.
	**/
	char get_position(position pos);
	
};

#endif //MAIN_H
