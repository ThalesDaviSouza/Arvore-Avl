#include "./include/avl_tree.h"

#include <stdio.h>

int main(int argc, char** argv){

    node* head = createNode(20);

    addNode(30, head);
    addNode(40, head);
    addNode(20, head);
    addNode(22, head);
    addNode(10, head);

    printTree(head);

    freeTree(head);
    
    return 0;
}