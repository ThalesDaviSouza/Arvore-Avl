#include "./include/avl_tree.h"

#include <stdio.h>

int main(int argc, char** argv){

    node* head = addNode(100, NULL);
    head = addNode(200, head);
    head = addNode(300, head);
    head = addNode(400, head);
    head = addNode(220, head);
    head = addNode(430, head);
    head = addNode(390, head);
    head = addNode(380, head);
    head = addNode(440, head);
    head = addNode(370, head);
    head = addNode(420, head);
    head = addNode(421, head);

    head = removeNode(440, head);
    head = removeNode(421, head);

    printTree(head);

    freeTree(head);
    
    return 0;
}