#include <vector>
#include <algorithm>
#include <utility>
#include <stack>


#ifndef BOARD_H
#define BOARD_H



typedef std::pair<int, int> position;



class board{
	char bd[3][3];
	
	public:
	enum {
		WIN_X,
		WIN_O,
		DRAW,
		CONTD
	};
	
	int make_move(char player, position pos);
	
	char get_position(position pos);
	
};

#endif //MAIN_H
