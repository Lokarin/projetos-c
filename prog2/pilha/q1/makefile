## Makefile

all: app

app: implementacao.o app.o
	gcc -o app implementacao.o app.o -lm

float_vector.o: implementacao.c
	gcc -c implementacao.c

app.o: app.c
	gcc -c app.c

clean:
	rm -rf *.o

rmproper: clean
	rm -rf app
