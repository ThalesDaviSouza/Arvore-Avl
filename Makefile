output: main.o avl_tree.o
	gcc main.o avl_tree.o -o main
	main

main.o: main.c
	gcc -c main.c

avl_tree.o: ./src/avl_tree.c ./include/avl_tree.h
	gcc -c .\src\avl_tree.c

test-insertion-avl-tree: ./tests/insertion_avl_tree.c 
	@echo "Starting insertion tests..."
	gcc ./tests/insertion_avl_tree.c -o insertion_avl_tree_test
	insertion_avl_tree_test
	@echo "Tests done"
	make clean

clean:
	del *.o *.exe