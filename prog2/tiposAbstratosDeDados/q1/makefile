## Makefile

all: app

app: aplicacao.o app.o
	gcc -o app aplicacao.o app.o -lm

float_vector.o: aplicacao.c
	gcc -c aplicacao.c

app.o: app.c
	gcc -c app.c

clean:
	rm -rf *.o

rmproper: clean
	rm -rf app
