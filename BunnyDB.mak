BunnyDB: Bunny.o FileUtils.o BunnyDataBase.o BunnyClient.o
	g++ Bunny.o FileUtils.o BunnyDataBase.o BunnyClient.o -o BunnyDB

BunnyDataBase.o: BunnyDataBase.cpp BunnyDataBase.h Bunny.h
	g++ -c BunnyDataBase.cpp -o BunnyDataBase.o

BunnyClient.o: BunnyClient.cpp Bunny.h BunnyDataBase.h
	g++ -c BunnyClient.cpp -o BunnyClient.o

Bunny.o: Bunny.cpp Bunny.h
	g++ -c Bunny.cpp -o Bunny.o

FileUtils.o: FileUtils.cpp FileUtils.h
	g++ -c FileUtils.cpp -o FileUtils.o
