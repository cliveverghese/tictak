#include "intel.h"
#define COPY_BOARD(src,dst)\
for(int it = 0; it < 3; it++)\
	for(int jt = 0; jt < 3; jt++)\
		(dst)[it][jt] = (src)[it][jt];


using namespace::std;

/*
enum {
	OPONENT,
	PLAYER
};
struct tree_node{
	char bd[3][3];
	int level;
	int score;
	int num_children;
	bool finished;
	position move;
	tree_node *children[9];
	tree_node *parent;
	
	
};

check_status_player(char player, char[3][3] bd){
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
			if( bd[j][3-j] != player){
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


tree_node * minimax(tree_node * ret,char player,char oponent){
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
		ch = 
			if(ret->bd[i][j] == ' '){
				
				
				

position intel::next_move_minimax(char player, char oponent){
	tree_node * ret;
	ret = (tree_node *)malloc(sizeof(tree_node));
	COPY_BOARD(ret->bd,bd);
	ret->level = 0;
	ret = minimax(ret,player,oponent);
	return ret->move;
}
*/	


position intel::next_move(char player, char oponent){
	int oponent_moves = 0,player_moves = 0,i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(bd[i][j] == oponent){
				oponent_moves++;
			}
			if(bd[i][j] == player){
				player_moves++;
			}
		}
	}
	if(player_moves == 0){
		if(bd[0][0] == ' ') return make_pair(0,0);
		else if(bd[2][2] == ' ') return make_pair(2,2);
		else if(bd[0][2] == ' ') return make_pair(0,2);
	}
	position oponent_win;
	int oponent_win_status = false;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(bd[i][j] == ' '){
				bd[i][j] = player; 												//*< Check if the player has
				if(check_status(player) == WIN){					// won if yes that return that
					return make_pair(i,j);									// move **/
				}
				bd[i][j] = oponent;
				if(check_status(oponent) == WIN){
					oponent_win_status = true;
					oponent_win = make_pair(i,j);
				}
				bd[i][j] = ' ';
			}
		}
	}
	if(oponent_win_status){
		return oponent_win;
	}
	return make_pair(0,0);
}

void intel::set_board(board b){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			bd[i][j] = b.get_position(make_pair(i,j));
		}
	}
}
	
