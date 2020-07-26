CC=g++
EXEC = main
LIBS = -lm -lsfml-graphics -lsfml-window -lsfml-system
FLAGS=-Wall -pedantic 
S=src
O=obj
B=bin

all: $(O) $(B) $(O)/main.o
	$(CC) $(O)/*.o -o $(B)/$(EXEC) $(LIBS)

$(O)/main.o: $(O)/Window.o
	$(CC) $(S)/main.cpp -c -o $(O)/main.o $(FLAGS)

$(O)/Window.o: $(O)/Ball.o
	$(CC) $(S)/Window.cpp -c -o $(O)/Window.o $(FLAGS)

$(O)/Ball.o:
	$(CC) $(S)/Ball.cpp -c -o $(O)/Ball.o $(FLAGS)

clean: $(O) $(B)
	rm -r $(O)
	rm -r $(B)

$(O):
	mkdir $(O)

$(B):
	mkdir $(B)