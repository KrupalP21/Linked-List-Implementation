llist: llist.c
	gcc -Wall -Werror -fsanitize=address -o llist llist.c

clean:
	rm -f llist
