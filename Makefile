all:
	g++ board.cpp logic.cpp intel.cpp -o tictak.out

debug:
	g++ -DDEBUG board.cpp logic.cpp -o tictak.out

clean:
	rm -f tictak
