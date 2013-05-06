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

int board::make_move(char player, position pos){
	bd[pos.first][pos.second] = player;
}
	
char board::get_position(position pos){
	return bd[pos.first][pos.second];
}
	


	
