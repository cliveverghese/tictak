#ifndef INTEL_H
#define INTEL_H
#include "board.h"


class intel: public board{
	public : 
	
	position next_move_minimax(char player,char oponent);
	
	/**
	* Predict the next move.
	* @param player The player whose move is to be pridicted
	* @param oponent The oponent player
	* @return The position of the next move.
	**/
	position next_move(char player, char oponent);
	
	/**
	* Initilize the board values with the board
	* @param b The original board values
	**/
	void set_board(board b);
};

#endif //INTEL_H
