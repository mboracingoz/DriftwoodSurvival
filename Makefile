CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC = src/main.cpp src/Player.cpp src/HUDSystem.cpp
OUT = game

all:
	$(CXX) $(SRC) -o $(OUT) $(CXXFLAGS) $(LIBS)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)