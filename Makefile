SRC = ttxxx

CC     = clang++
CCOPT  = -std=c++11 
TARGET = a.out

$(TARGET) : $(SRC).cpp
	$(CC) $(CCOPT) $(SRC).cpp

clean :
	rm $(TARGET)

