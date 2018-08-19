## -------------------------------------
## How to use
##  > make SRC=<.cpp File Name>
## -------------------------------------
SRC = ttxxx

## アセンブル結果出力
##CCASM = -S -mllvm -x86-asm-syntax=intel 
CCASM =
##CCDBG = -g
CCDBG =

CC     = clang++
CCOPT  = -std=c++11 $(CCDBG) $(CCASM)
TARGET = a.out

LINKOPT = 

$(TARGET) : $(SRC)
	$(CC) $(CCOPT) $(LINKOPT) $(SRC) -o $@ 

clean :
	rm $(TARGET)

