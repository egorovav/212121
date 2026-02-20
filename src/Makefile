FLAGS = -Wall -Wextra -Werror -std=c11 -g

TARGET = game_of_life

OBJS = game_of_life.o adapters/messages.o usecases/game_logic.o adapters/data_io.o adapters/keyboard_actions.o

FILE ?= ../test_data/test.txt

start: ../build/Game
	./../build/Game < $(FILE)

../build/Game: $(OBJS)
	mkdir -p ../build
	gcc ${FLAGS} $(OBJS) -lncurses -lm -o ../build/Game

game_of_life.o: game_of_life.c
	gcc $(FLAGS) -c game_of_life.c -o game_of_life.o

messages.o: adapters/messages.c
	gcc $(FLAGS) -c adapters/messages.c -o adapters/messages.o

game_logic.o: usecases/game_logic.c
	gcc $(FLAGS) -c usecases/game_logic.c -o usecases/game_logic.o

data_io.o: adapters/data_io.c
	gcc $(FLAGS) -c adapters/data_io.c -o adapters/data_io.o

keyboard_actions.o: adapters/keyboard_actions.c
	gcc $(FLAGS) -c adapters/keyboard_actions.c -o adapters/keyboard_actions.o

clean:
	rm -f $(OBJS)
	rm -rf ../build

rebuild: clean start

.PHONY: clean rebuild start
