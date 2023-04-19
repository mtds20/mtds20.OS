all: myls mysearch mystat mytail

myls: myls-Mateus.c
	gcc -o myls myls-Mateus.c

mysearch: mysearch-Mateus.c
	gcc -o mysearch mysearch-Mateus.c

mystat: mystat-Mateus.c
	gcc -o mystat mystat-Mateus.c

mytail: mytail-Mateus.c
	gcc -o mytail mytail-Mateus.c


