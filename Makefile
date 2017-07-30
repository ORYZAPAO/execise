## -------------------------------------
## How to use
##  > make SRC=<.cpp File Name>
## -------------------------------------
SRC = ttxxx

CC     = clang++
CCOPT  = -std=c++11 
TARGET = a.out

LINKOPT = 

$(TARGET) : $(SRC)
	$(CC) $(CCOPT) $(LINKOPT) $(SRC) -o $@ 

clean :
	rm $(TARGET)

