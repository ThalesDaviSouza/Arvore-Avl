#include "./include/avl_tree.h"

#include <stdio.h>

int main(int argc, char** argv){

    node* head = createNode(10);
    
    printf("Adding: 20\n\n");
    head = addNode(20, head);
    
    printf("Adding: 30\n\n"); 
    head = addNode(30, head);
    
    printf("Adding: 40\n\n");
    head = addNode(40, head);
    
    printf("Adding: 22\n\n");
    head = addNode(22, head);
    
    printf("Adding: 43\n\n");
    head = addNode(43, head);
    
    printf("Adding: 39\n\n");
    head = addNode(39, head);
    
    printf("Adding: 38\n\n");
    head = addNode(38, head);
    
    printf("Adding: 44\n\n");
    head = addNode(44, head);
    
    printf("Adding: 37\n\n");
    head = addNode(37, head);

    // printf("Adding: -20\n\n");
    // head = addNode(-20, head);
    
    // printf("Adding: -30\n\n");
    // head = addNode(-30, head);
    
    // printf("Adding: -33\n\n");
    // head = addNode(-23, head);
    
    // printf("Adding: -40\n\n");
    // head = addNode(-22, head);

    printTree(head);

    freeTree(head);
    
    return 0;
}