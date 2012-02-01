CFLAGS=-Wall -Werror -pedantic

peek: main.o peek.o
	g++ $(CFLAGS) -o peek peek.o main.o

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

peek.o: peek.cpp
	g++ $(CFLAGS) -c peek.cpp

clean:
	@rm -f peek *.o peek.tar.bz2

test: peek
	./peek test/01.tar
	./peek test/02.tar.gz
	./peek test/03.tar.bz2
	./peek test/04.tgz
	./peek test/05.tbz2
	./peek test/06.gz
	./peek -p test/06.gz
	./peek test/07.bz2
	./peek test/08.rar
	./peek test/09.zip
	./peek test/10.zoo
	./peek test/11.arj
	./peek test/12.ace
	./peek test/13.tar.Z
	./peek test/14.7z

pack:
	tar -cjf peek.tar.bz2 main.cpp peek.cpp peek.hpp makefile ChangeLog
