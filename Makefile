## -------------------------------------
## How to use
##  > make SRC=<.cpp File Name>
## -------------------------------------
SRC = ttxxx

## アセンブル結果出力
##CCASM = -S -mllvm -x86-asm-syntax=intel 
CCASM =
DEBUG = 0

ifeq ($(DEBUG),1)
  CCDBG = -g
else
  CCDBG  =
endif

CC     = clang++

##CCOPT  = -std=c++1y $(CCDBG) $(CCASM)
CCOPT  = -std=c++17 $(CCDBG) $(CCASM)
TARGET = a.out
LINKOPT = 

$(TARGET) : $(SRC)
	$(CC) $(CCOPT) $(LINKOPT) $(SRC) -o $@ 

clean :
	rm $(TARGET)

