## Makefile

all: app

app: float_vector.o app.o
	gcc -o app float_vector.o app.o -lm

float_vector.o: float_vector.c
	gcc -c float_vector.c

app.o: app.c
	gcc -c app.c

clean:
	rm -rf *.o

rmproper: clean
	rm -rf app
