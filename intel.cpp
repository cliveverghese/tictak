#include "board.h"
#include "intel.h"
#include <iostream>
#include <cstdio>
#define COPY_BOARD(src,dst)\
for(int it = 0; it < 3; it++)\
	for(int jt = 0; jt < 3; jt++)\
		(dst)[it][jt] = (src)[it][jt];
#define MIN(X,Y) (X)<(Y)?(X):(Y)
#define MAX(X,Y) (X)>(Y)?(X):(Y)


using namespace::std;

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

int check_status_player(char player, char bd[3][3]){
	int empty = false;
	//cout<<"Checking Board\n";
	for(int i = 0; i < 3; i++){
		
		int flag_h = true, flag_v = true, flag_d1 = true, flag_d2 = true;
	
		for(int j = 0; j < 3; j++){
			//cout<<bd[i][j];
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
		//cout<<"\n";
		if( flag_h | flag_v | flag_d1 | flag_d2 ){
			//cout<<"Won\n";
			return board::WIN;
		}
	}
	if(empty){
		return board::CONTD;
	} else {
		//cout<<"Draw\n";
		return board::DRAW;
	}
}


int minimax(char bd[3][3],char player,char oponent, position &pos,int level = 0){
	char playing = level % 2 == 0?player:oponent;
	int i,j;
	vector<position > moves;
	//cout<<"Level "<<level<<" move "<<playing<<"\n";
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			//cout<<bd[i][j]<<" ";
			if(bd[i][j] == ' '){

				bd[i][j] = playing;
				int status = check_status_player(playing,bd);
				bd[i][j] = ' ';
				if(status == board::WIN){
					//cout<<"Test\n";
					pos.first = i;
					pos.second = j;
					return (playing == player?1:-1);
				}
				
				moves.push_back(make_pair(i,j));
			}
			
		}
		//cout<<"\n";

	}
	int factor;
	//getchar();
	if (playing == oponent) factor = 50;
	else factor = -50;
	if (moves.size() == 0) factor = 0;
	for(i = 0; i < moves.size(); i++){
		int x = moves[i].first;
		int y = moves[i].second;
		bd[x][y] = playing;
		position temp;
		int ret = minimax(bd,player,oponent,temp,level+1);
		//cout<<"Level "<<level+1<<" returned "<<ret<<"\n";
		bd[x][y] = ' ';
		if ( ret == 0){
			pos.first = x;
			pos.second = y;
		}
		if(playing == oponent){
			factor = MIN(factor,ret);
			if (factor == -1){
				return factor;
			}
		} else {
			factor = MAX(factor,ret);
			if(factor == 1){
				pos.first = x;
				pos.second = y;
				return factor;
			}
		}
	}
	return factor;
}
			
		
		
		
				
				
				

position intel::next_move_minimax(char player, char oponent){
	tree_node * ret;
	position pos;
	char board[3][3];
	ret = (tree_node *)malloc(sizeof(tree_node));
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			board[i][j] = board::get_position(make_pair(i,j));
		}
	}
	ret->level = 0;
	int val = minimax(board,player,oponent,pos);
	#ifdef DEBUG
	cout<<"\nDEBUG:"<<pos.first<<" "<<pos.second<<" "<<val<<"\n"; 
	#endif
	return pos;
}
	


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
	
