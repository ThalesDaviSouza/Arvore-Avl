#include "./include/avl_tree.h"

#include <stdio.h>

int main(int argc, char** argv){

    node* head = createNode(10);
    
    // printf("Adding: 20\n\n");
    // head = addNode(20, head);
    
    // printf("Adding: 30\n\n"); 
    // head = addNode(30, head);
    
    // printf("Adding: 40\n\n");
    // head = addNode(40, head);
    
    // printf("Adding: 22\n\n");
    // head = addNode(22, head);
    
    // printf("Adding: 43\n\n");
    // head = addNode(43, head);

    printf("Adding: -2\n\n");
    head = addNode(-2, head);
    
    printf("Adding: -3\n\n");
    head = addNode(-3, head);
    
    printf("Adding: -4\n\n");
    head = addNode(-4, head);

    printTree(head);

    freeTree(head);
    
    return 0;
}