#include "board.h"
#include <cstdio>


board::board(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){	
			bd[i][j] = ' ';
		
		}
	}
	#ifdef DEBUG
		printf("Initilized board with values\n");
	#endif
	
}

int board::check_status(char player){
	int empty = false;
	for(int i = 0; i < 3; i++){

		int flag_h = true, flag_v = true, flag_d1 = true, flag_d2 = true;
	
		for(int j = 0; j < 3; j++){
			if ( bd[i][j] == ' '){
				empty = true;
			}
			if( bd[i][j] != player ){
				flag_h = false;
			}
			if( bd[j][i] != player){
				flag_v = false;
			}
			if( bd[j][j] != player){
				flag_d1 = false;
			}
			if( bd[j][2-j] != player){
				flag_d2 = false;
			}
			
		}
		if( flag_h | flag_v | flag_d1 | flag_d2 ){
			return WIN;
		}
	}
	if(empty){
		return CONTD;
	} else {
		return DRAW;
	}
}

int board::make_move(char player, position pos){
	if (bd[pos.first][pos.second] != ' '){
		return INVALID;
	}
	bd[pos.first][pos.second] = player;
	return check_status(player);
}
	
char board::get_position(position pos){
	return bd[pos.first][pos.second];
}
	


	
