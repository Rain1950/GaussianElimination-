all:
	gcc -Wall --pedantic ../branches/testy_mr/*.c src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
	bin/gauss dane/A2 dane/b2
