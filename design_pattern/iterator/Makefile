## -------------------------------------
## How to use
##  > make 
## -------------------------------------
SRC = main.cpp

CC     = clang++ -g
##CC     = g++
CCOPT  = -std=c++14 
TARGET = a.exe

$(TARGET) : $(SRC)
	$(CC) $(CCOPT) $(SRC) -o $@

clean :
	rm $(TARGET)

