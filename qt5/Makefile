## -------------------------------------
## How to use
##  > make SRC=<.cpp File Name>
## -------------------------------------
SRC = ttxxx

CC     = clang++
CCOPT  = -std=c++11 $(shell pkg-config --cflags Qt5Widgets) -fPIC
TARGET = a.out
LINKOPT = $(shell pkg-config --libs Qt5Widgets)

$(TARGET) : $(SRC)
	$(CC) $(CCOPT) $(LINKOPT) $(SRC) -o $@ 

clean :
	rm $(TARGET)

