SOURCE_DIR= .$(srcdir)/src

SOURCE= \
	$(SOURCE_DIR)/main.cpp \
	$(SOURCE_DIR)/Queue.cpp

OBJ_DIR= \
	.$(srcdir)/obj

OBJ= $(patsubst $(SOURCE_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCE)) 

EXEC= .$(srcdir)/queue.exe

CC=g++ 

VERSION = -std=c++11

BUILDFLAGS= -c 

CCFLAGS = -Wall -Wextra


all: build install

build:
	mkdir -p $(OBJ_DIR)
	$(foreach SRC_FILE,$(SOURCE),\
		$(CC) $(VERSION) $(BUILDFLAGS) $(CCFLAGS) $(SRC_FILE) -o\
		$(patsubst $(SOURCE_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILE));)

install:
	$(CC) $(VERSION) $(CCFLAGS) $(OBJ) -o $(EXEC)

clean:
	DEL /F /S *.o
	DEL queue.exe
	DEL err.txt