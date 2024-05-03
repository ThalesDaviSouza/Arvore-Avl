#include "../include/avl_tree.h"

#include <stdio.h>
#include <stdlib.h>


node* createNode(int value){
    node* newNode = (node*)malloc(sizeof(node));

    newNode->value = value;
    newNode->height = 0;
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/**
 * Calculates the factor of a node
 * Is used to check is necessary to make any rotation
*/
int _calculateFactor(node* head){
    int rightHeight = 0;
    int leftHeight = 0;

    if(head->right != NULL){
        rightHeight = head->right->height;
    }
    
    if(head->left != NULL){
        leftHeight = head->left->height;
    }

    return rightHeight - leftHeight;
}

/**
 * Calculates the height of a node
*/
int _height(node* _node){
    if(_node == NULL) return 0;

    return _node->height;
}

int _max(int x, int y){
    return x > y ? x : y;
}

void printTree(node* head){
    if(head->right != NULL){
        printTree(head->right);
    }

    printf("Value: %d \t Height: %d \t Count: %d \t Factor: %d\n", head->value, head->height, head->count,  _calculateFactor(head));
    
    if(head->left != NULL){
        printTree(head->left);
    }

}


/**
 * Inscrease the node Height
 * Gets the height of children nodes and return the bigger height + 1
*/
void increaseNodeHeight(node* head, NodeDirection nodeDirection){
    int rightHeight = 0;
    int leftHeight = 0;
    
    if(head->left != NULL)
        leftHeight = head->left->height;
    
    if(head->right != NULL)
        rightHeight = head->right->height;

    head->height = _max(rightHeight, leftHeight);

    head->height++;
}

/**
 * Insert a new node to the Avl Tree
*/
node* addNode(int value, node* head){
    int factor = 0;
    
    if(head == NULL) return createNode(value);

    if(value == head->value){
        head->count++;
        return head;
    }

    // Redirect the node to correct side of tree
    if(value > head->value){

        if(head->right == NULL){
            head->right = createNode(value);
        }
        else{
            head->right = addNode(value, head->right);
        }

        increaseNodeHeight(head, RIGHT);

    }
    else{

        if(head->left == NULL){
            head->left = createNode(value);
        }
        else{
            head->left = addNode(value, head->left);
        }

        increaseNodeHeight(head, LEFT);
    }


    factor = _calculateFactor(head);

    if(factor >= 2){
        int factorRight = _calculateFactor(head->right);

        if(factorRight > 0){
            head = rotateRR(head);
        }
        else{
            head = rotateRL(head);
        }
    }
    else if(factor <= -2){
        int factorLeft = _calculateFactor(head->left);
        
        if(factorLeft < 0){
            head = rotateLL(head);
        }
        else {
            head = rotateLR(head);
        }
    }

    return head;
}

node* rotateRR(node* head){
    node* old_head = head;
    node* new_head = NULL;
    node* aux = NULL;
    
    if(head == NULL) return NULL;
    if(head->right == NULL) return head;

    // Performs the Left Rotation
    new_head = head->right;
    aux = new_head->left;
    new_head->left = old_head;
    old_head->right = aux;

    // Recalculates the height of old head
    if(old_head->left == NULL && old_head->right == NULL) {
        old_head->height = 0;
    }
    else{
        old_head->height = _max(_height(old_head->left), _height(old_head->right)) + 1;
    }

    // Recalculates the height of new head
    if(new_head->left == NULL && new_head->right == NULL) {
        new_head->height = 0;
    }
    else{
        new_head->height = _max(_height(new_head->left), _height(new_head->right)) + 1;
    }

    return new_head;
}

node* rotateLL(node* head){
    node* old_head = head;
    node* new_head = NULL;
    node* aux = NULL;
    
    if(head == NULL) return NULL;
    if(head->left == NULL) return head;

    // Performs the Left Rotation
    new_head = head->left;
    aux = new_head->right;
    new_head->right = old_head;
    old_head->left = aux;

    // Recalculates the old head's height
    if(old_head->left == NULL && old_head->right == NULL) {
        old_head->height = 0;
    }
    else{
        old_head->height = _max(_height(old_head->left), _height(old_head->right)) + 1;
    }

    // Recalculates the new head's height
    if(new_head->left == NULL && new_head->right == NULL) {
        new_head->height = 0;
    }
    else{
        new_head->height = _max(_height(new_head->left), _height(new_head->right)) + 1;
    }

    return new_head;
}

node* rotateLR(node* head){
    head->left = rotateRR(head->left);
    head = rotateLL(head);

    return head;
}

node* rotateRL(node* head){
    head->right = rotateLL(head->right);
    head = rotateRR(head);

    return head;
}

node* findNode(int value, node* head){
    if(head == NULL) return NULL;
    if(head->value == value) return head;

    if(value > head->value) {
        return findNode(value, head->right);
    }
    else {
        return findNode(value, head->left);
    }
}

node* _deleteNode(node* n){
    if(n == NULL) return NULL;
    
    node* right = n->right;
    node* left = n->left;
    
    
    if(n->right == NULL){
        free(n);
        return left;
    }
    else{
        node* rightSmallest = NULL;
        node* aux = NULL; 

        rightSmallest = n->right;
        aux = n;

        while(rightSmallest->left != NULL){
            aux = rightSmallest;
            rightSmallest = rightSmallest->left;
        }

        n->value = rightSmallest->value;

        aux->right = rightSmallest->right;

        if(n != aux){
            aux->left = NULL;
        }

        free(rightSmallest);

        return n;
    }
}


int _recalculateTreeHeight(node* head){
    if(head == NULL) return -1;
    int rightHeight = 0;
    int leftHeight = 0;

    if(head->left == NULL && head->right == NULL){
        head->height = 0;
        return head->height;
    }

    if(head->right != NULL)
        rightHeight = _recalculateTreeHeight(head->right);

    if(head->left != NULL)
        leftHeight = _recalculateTreeHeight(head->left);

    head->height = _max(leftHeight, rightHeight) +1;
    
    return head->height;
}

node* _rebalanceTree(node* head){
    if(head == NULL) return NULL;
    int factor;

    head->left = _rebalanceTree(head->left);
    head->right = _rebalanceTree(head->right);

    factor = _calculateFactor(head);

    if(factor >= 2){
        int factorRight = _calculateFactor(head->right);

        if(factorRight > 0){
            head = rotateRR(head);
        }
        else{
            head = rotateRL(head);
        }
    }
    else if(factor <= -2){
        int factorLeft = _calculateFactor(head->left);
        
        if(factorLeft < 0){
            head = rotateLL(head);
        }
        else {
            head = rotateLR(head);
        }
    }

    return head;
}

node* removeNode(int value, node* head){
    if(head == NULL) return NULL;
    
    if(head->value == value){
        head = _deleteNode(head);
        
        _recalculateTreeHeight(head);

        _rebalanceTree(head);
        
    }
    else{
        if(value > head->value){
            head->right = removeNode(value, head->right);
        }
        else{
            head->left = removeNode(value, head->left);
        }
    }
}


void freeTree(node* head){
    if(head->right != NULL)
        freeTree(head->right);
    
    if(head->left != NULL)
        freeTree(head->left);
    
    free(head);
}