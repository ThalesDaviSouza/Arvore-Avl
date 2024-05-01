output: main.o avl_tree.o
	gcc main.o avl_tree.o -o main
	main

main.o: main.c
	gcc -c main.c

avl_tree.o: ./src/avl_tree.c ./include/avl_tree.h
	gcc -c .\src\avl_tree.c

clean:
	del *.o *.exe