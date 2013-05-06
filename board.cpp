#include "board.h"


int board::make_move(char player, position pos){
	bd[pos.first][pos.second] = player;
}
	
char board::get_position(position pos){
	return bd[pos.first][pos.second];
}
	


	
