SRC = src\Queue.cpp
SRC += src\main.cpp


# object list
OBJS = $(SRC:.cpp=.o)


CXX = g++

CXXFLAGS = -std=c++11 -Wall -Wextra

#build
all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o queue

#build rules 
%.o: %.cpp 
	$(CXX) -c $(CXXFLAGS) $< -o $@

#clean
clean:
	DEL /F /S *.o
	DEL queue.exe
	DEL out.txt
	DEL err.txt


help:
	@echo "all		->	build all"
	@echo "clean		->	delete .o and executeable"
	@echo "save 		->	save output to out.txt"
	@echo "saveERR	->	save errors to err.txt"