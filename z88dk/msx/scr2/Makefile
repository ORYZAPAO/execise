TARGET=sc2.rom

$(TARGET) : mymsx1.c
	#zcc +x1 -create-app -lm myx1.c
	#zcc +msx -create-app -subtype=rom mymsx1.c
	zcc +msx -vn -llib3d  -lm -lndos -lmsxbios -create-app -DAMALLOC -subtype=rom mymsx1.c -o $@
	ctags -Re

clean :
	rm $(TARGET)
	rm *.bin
	rm zcc_opt.def
