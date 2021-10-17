
all: test

debug: test.c lehmer.o count_tree.o
	gcc -o test -g -fsanitize=address test.c lehmer.o count_tree.o

test: test.c lehmer.o count_tree.o
	gcc -o test test.c lehmer.o count_tree.o

lehmer.o: lehmer.c lehmer.h
	gcc -c lehmer.c

count_tree.o: count_tree.c count_tree.h
	gcc -c count_tree.c

clean:
	rm -f test
	rm -f *.o
