RabbitStruct: RabbitStruct.o ReadUtils.o
	g++ RabbitStruct.o ReadUtils.o -o RabbitStruct


RabbitStruct.o: RabbitStruct.cpp
	g++ -c RabbitStruct.cpp -o RabbitStruct.o

ReadUtils.o: ReadUtils.cpp ReadUtils.h
	g++ -c ReadUtils.cpp -o ReadUtils.o
