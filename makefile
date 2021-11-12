all: work14.o
	gcc -o output work14.o

work13.o: work14.c
	gcc -c work14.c

run:
	./output

clean:
	rm *.o
	rm output
	rm *.txt


