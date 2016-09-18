## -------------------------------------
## How to use
##  > make 
## -------------------------------------
SRC = main.cpp

CC     = clang++
##CC     = g++
CCOPT  = -std=c++11 
TARGET = a.exe

$(TARGET) : $(SRC)
	$(CC) $(CCOPT) $(SRC) -o $@

clean :
	rm $(TARGET)

