RabbitStruct: RabbitStruct.o FileUtils.o
	g++ RabbitStruct.o FileUtils.o -o RabbitStruct


RabbitStruct.o: RabbitStruct.cpp
	g++ -c RabbitStruct.cpp -o RabbitStruct.o

FileUtils.o: FileUtils.cpp FileUtils.h
	g++ -c FileUtils.cpp -o FileUtils.o
