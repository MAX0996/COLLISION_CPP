CC=g++
EXEC = main
LIBS = -lm -lsfml-graphics -lsfml-window -lsfml-system
FLAGS=-Wall -pedantic 
O=OBJ_LINUX
B=BIN_LINUX

all: $(O) $(B) $(O)/main.o
	$(CC) $(O)/*.o -o $(B)/$(EXEC) $(LIBS)

$(O)/main.o: $(O)/Window.o
	$(CC) main.cpp -c -o $(O)/main.o $(FLAGS)

$(O)/Window.o: $(O)/Ball.o
	$(CC) Window.cpp -c -o $(O)/Window.o $(FLAGS)

$(O)/Ball.o:
	$(CC) Ball.cpp -c -o $(O)/Ball.o $(FLAGS)

clean: $(O) $(B)
	rm -r $(O)
	rm -r $(B)

$(O):
	mkdir $(O)

$(B):
	mkdir $(B)