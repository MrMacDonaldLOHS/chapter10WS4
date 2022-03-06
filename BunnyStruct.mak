BunnyStruct: BunnyStruct.o FileUtils.o
	g++ BunnyStruct.o FileUtils.o -o BunnyStruct


BunnyStruct.o: BunnyStruct.cpp
	g++ -c BunnyStruct.cpp -o BunnyStruct.o

FileUtils.o: FileUtils.cpp FileUtils.h
	g++ -c FileUtils.cpp -o FileUtils.o
