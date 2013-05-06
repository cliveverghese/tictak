#include "board.h"
#include "intel.h"
#include <iostream>

using namespace::std;

int main(){
	board bd;
	char cur,next;
	cur = 'O';
	next = 'X';
	int status;
	intel ai;
	do {

		int x,y;
		if(cur == 'O'){
			cin>>x>>y;
			status = bd.make_move(cur,make_pair(x,y));
			if ( status == board::WIN ){
				cout<<cur<<" WON\n";
				return 0;
			}
		}
		else {
			ai.set_board(bd);
			status = bd.make_move(cur,ai.next_move(cur,next));
			if(status == board::WIN ){
				cout<<cur<<" WON\n";
				return 0;
			}
		}
			
		cur = cur ^ next;
		next = cur ^ next;
		cur = cur ^ next; 
		for( int i = 0; i < 3 ; i++ ){
			for( int j = 0; j < 3 ; j++){
				cout<<bd.get_position(make_pair(i,j))<<" ";
			}
			cout<<"\n";
		}
	} while ( status == board::CONTD );
	cout<<"DRAW\n";
	
		
	
	return 0;
}
