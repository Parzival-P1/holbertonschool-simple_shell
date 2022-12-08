main: libshell.a
	gcc -L. -o shell main.c -lshell
libshell.a: shell.o
	ar -cvq libshell.a shell.o
shell.o:
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c shell.c shell2.c
clean:
	rm -f shell *.a *.o 
