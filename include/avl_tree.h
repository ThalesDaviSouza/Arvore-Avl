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

/**
 * Enum to know the direction
 * that a node is added in function addNode
*/
typedef enum NodeDirection_t{
    RIGHT,
    LEFT
}NodeDirection;

/**
 * Function that creates a node with deafult values
*/
node* createNode(int value);

/**
 * Function that inserts a node
*/
node* addNode(int value, node* head);

/**
 * Function to Right Right case
 * Also called Left Rotation
*/
node* rotateRR(node* head);

/**
 * Function to Left Left case
 * Also called Right Rotation
*/
node* rotateLL(node* head);

void printTree(node* head);

void freeTree(node* head);

#endif