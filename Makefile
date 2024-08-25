
SRC = $(wildcard main.cpp map/*.cpp robot/*.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

CC = g++ -Wall -Wextra -g -std=c++20

TARGET = lab3

all: $(OBJ)
	bison -d B.y -b lab
	flex F.l
	$(CC) $(OBJ) lex.yy.c lab.tab.c -o $(TARGET)
	rm -f $(OBJ)

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm -f lab.tab.* lex.yy.* *.output $(OBJ) $(TARGET)