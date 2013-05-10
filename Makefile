all:
	g++ board.cpp logic.cpp intel.cpp -o tictak.out

debug:
	g++ -DDEBUG board.cpp logic.cpp intel.cpp -o tictak.out

gui:
	gcc gui.c `pkg-config --cflags --libs --static libglfw` -o gui

clean:
	rm -f tictak
