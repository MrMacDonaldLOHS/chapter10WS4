RabbitDB: Rabbit.o FileUtils.o RabbitDataBase.o RabbitClient.o
	g++ Rabbit.o FileUtils.o RabbitDataBase.o RabbitClient.o -o RabbitDB

RabbitDataBase.o: RabbitDataBase.cpp RabbitDataBase.h Rabbit.h
	g++ -c RabbitDataBase.cpp -o RabbitDataBase.o

RabbitClient.o: RabbitClient.cpp Rabbit.h RabbitDataBase.h
	g++ -c RabbitClient.cpp -o RabbitClient.o

Rabbit.o: Rabbit.cpp Rabbit.h
	g++ -c Rabbit.cpp -o Rabbit.o

FileUtils.o: FileUtils.cpp FileUtils.h
	g++ -c FileUtils.cpp -o FileUtils.o
