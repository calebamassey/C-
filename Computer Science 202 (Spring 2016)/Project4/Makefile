#
# File:   Makefile
# Author: Caleb Massey (cmassey1@umbc.edu)
# Desc:   Makefile for Project 4
#

a.out: card.o Cruno8.o CrunoDraw2.o CrunoSkip.o CrunoReverse.o player.o CrunoPlayer.o game.o CrunoGame.o mytest.o
	g++ -g -Wall card.o Cruno8.o CrunoDraw2.o CrunoSkip.o CrunoReverse.o player.o CrunoPlayer.o game.o CrunoGame.o mytest.o

card.o: card.cpp card.h player.h game.h
	g++ -g -Wall -c card.cpp

Cruno8.o: Cruno8.cpp Cruno8.h card.h CrunoPlayer.h
	g++ -g -Wall -c Cruno8.cpp

CrunoDraw2.o: CrunoDraw2.cpp CrunoDraw2.h CrunoSkip.h card.h CrunoPlayer.h player.h game.h
	g++ -g -Wall -c CrunoDraw2.cpp

CrunoSkip.o: CrunoSkip.cpp CrunoSkip.h CrunoReverse.h card.h game.h CrunoGame.h
	g++ -g -Wall -c CrunoSkip.cpp

CrunoReverse.o: CrunoReverse.cpp CrunoReverse.h card.h CrunoGame.cpp
	g++ -g -Wall -c CrunoReverse.cpp

player.o: player.cpp player.h card.h game.h
	g++ -g -Wall -c player.cpp

CrunoPlayer.o: CrunoPlayer.cpp CrunoPlayer.h Cruno8.h player.h CrunoGame.h
	g++ -g -Wall -c CrunoPlayer.cpp

game.o: game.cpp game.h card.h player.h
	g++ -g -Wall -c game.cpp

CrunoGame.o: CrunoGame.cpp CrunoGame.h CrunoDraw2.h CrunoSkip.h CrunoReverse.h game.h card.h CrunoPlayer.h
	g++ -g -Wall -c CrunoGame.cpp

mytest.o: mytest.cpp game.h card.h player.h
	g++ -g -Wall -c mytest.cpp

make:
	xemacs Makefile &

run:
	./a.out

ddd:
	ddd a.out &

########################################
# rules for cleaning away excess files #
########################################
# removes .o and executable files
clean:
	rm  -f *.o a.out
# removes any temporary (~) files
cleaner: 
	rm  -f *~
# runs both clean and cleaner
c: clean cleaner