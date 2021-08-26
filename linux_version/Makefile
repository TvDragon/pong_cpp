CC=g++
CFLAGS=-std=c++14 -m64 -g -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf
EXCLUDE_TEST_SRC=src/main_test.cpp src/rectangle_test.cpp src/player_movement_test.cpp src/ball_movement_test.cpp
EXCLUDE_MAIN_SRC=src/main.cpp

play: src/*.cpp
	$(CC) $(filter-out $(EXCLUDE_TEST_SRC), $^) $(CFLAGS) -o $@

test: src/*.cpp
	$(CC) $(filter-out $(EXCLUDE_MAIN_SRC), $^) $(CFLAGS) -o $@

clean:
	rm play