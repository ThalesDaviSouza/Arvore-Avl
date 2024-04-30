#ifndef AVL_TREE_H
#define AVL_TREE_H

/**
 * Main struct to avl tree 
 * Represents each node of tree
*/
typedef struct node_t {
    int value;
    int height;
    int count;
    struct node_t* left;
    struct node_t* right;
} node;

typedef enum NodeDirection_t{
    RIGHT,
    LEFT
}NodeDirection;

node* createNode(int value);

void addNode(int value, node* head);

void printTree(node* head);

#endif