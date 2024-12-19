all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: 
	gcc -Wall --pedantic src/gauss.h src/backsubst.h src/gauss.c src/backsubst.c src/mat_io.c src/mat_io.h tests/test.c -o tests/test
	tests/test dane/A dane/b dane/A2 dane/b2 dane/A3 dane/b3 dane/A4 dane/b4 dane/A5 dane/b5
