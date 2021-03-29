##TARGET=sc2.rom
##TARGET=sc2.com
##TARGET=sc2.msx

#$(TARGET) : mymsx1.c
#	#zcc +x1 -create-app -lm myx1.c
#	#zcc +msx -create-app -subtype=rom mymsx1.c
#	#zcc +msx -vn -llib3d  -lm -lndos -lmsxbios -create-app -DAMALLOC -subtype=rom mymsx1.c -o $@
#	##zcc +msx -vn -llib3d  -lm -lndos -lmsxbios -create-app -DAMALLOC -subtype=msxdos mymsx1.c -o $@
#	##zcc +msx -vn -llib3d  -lm -lndos -lmsxbios -create-app -DAMALLOC -subtype=disk mymsx1.c -o $@
#	ctags -Re


rom : mymsx1.c
	zcc +msx -vn -llib3d  -lm -lndos -lmsxbios -create-app -DAMALLOC -subtype=rom mymsx1.c -o sc2.rom
	ctags -Re

disk : mymsx1.c
	zcc +msx -vn -llib3d  -lm -lndos -lmsxbios -create-app -DAMALLOC -subtype=disk mymsx1.c -o sc2.msx
	ctags -Re

dos : mymsx1.c
	zcc +msx -vn -llib3d  -lm -lndos -lmsxbios -create-app -DAMALLOC -subtype=msxdos mymsx1.c -o sc2.com

clean :
	rm sc2.*
	rm *.bin
	rm zcc_opt.def
