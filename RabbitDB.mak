RabbitDB: Rabbit.o ReadUtils.o RabbitDataBase.o RabbitClient.o
	g++ Rabbit.o ReadUtils.o RabbitDataBase.o RabbitClient.o -o RabbitDB

RabbitDataBase.o: RabbitDataBase.cpp RabbitDataBase.h Rabbit.h
	g++ -c RabbitDataBase.cpp -o RabbitDataBase.o

RabbitClient.o: RabbitClient.cpp Rabbit.h RabbitDataBase.h
	g++ -c RabbitClient.cpp -o RabbitClient.o

Rabbit.o: Rabbit.cpp Rabbit.h
	g++ -c Rabbit.cpp -o Rabbit.o

ReadUtils.o: ReadUtils.cpp ReadUtils.h
	g++ -c ReadUtils.cpp -o ReadUtils.o
