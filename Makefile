linear-algebra: main.o vector.o
	g++ main.o vector.o -o linear-algebra

main.o vector.o: main.cpp vector.cpp
	g++ -c -g main.cpp vector.cpp 

test: linear-algebra
	./linear-algebra

clean:
	rm *.o linear-algebra
