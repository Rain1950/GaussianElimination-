all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
		gcc src/gauss.c src/mat_io.c src/backsubst.c  ../branches/testy_mr/testy_mr.c -o bin/test
	       	bin/test	
	
