INC=-I./include

default:    main

main:
	g++ -Wall $(INC) src/*.cpp main.cpp -o main

build:
	g++ -Wall $(INC) -c src/exception.cpp src/string.cpp
	ar rcs libstl.a exception.o string.o

clean:
	rm -r *.o