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

void increaseNodeHeight(node* head, NodeDirection nodeDirection){
    int rightHeight = 0;
    int leftHeight = 0;
    
    if(head->left != NULL)
        leftHeight = head->left->height;
    
    if(head->right != NULL)
        rightHeight = head->right->height;

    head->height = rightHeight > leftHeight ? rightHeight : leftHeight;
    head->height++;
}


node* addNode(int value, node* head){
    int factor = 0;
    
    if(head == NULL) return NULL;

    if(value == head->value){
        head->count++;
        return head;
    }

    if(value > head->value){
        if(head->right == NULL){
            head->right = createNode(value);
        }
        else{
            head->right = addNode(value, head->right);
        }

        increaseNodeHeight(head, RIGHT);

    }else{
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
            printf("Node %d, Rotate RR\n\n", head->value);
            head = rotateRR(head);
        }else{
            printf("Node %d, Rotate RL\n\n", head->value);
            head = rotateRL(head);
        }
    }
    else if(factor <= -2){
        int factorLeft = _calculateFactor(head->left);
        
        if(factorLeft < 0){
            printf("Node %d, Rotate LL\n\n", head->value);
            head = rotateLL(head);
        }
        else {
            printf("Node %d, Rotate LR\n\n", head->value);
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

    new_head = head->right;

    aux = new_head->left;

    new_head->left = old_head;

    old_head->right = aux;

    if(old_head->left == NULL && old_head->right == NULL) {
        old_head->height = 0;
    }
    else{
        old_head->height = _max(_height(old_head->left), _height(old_head->right)) + 1;
    }

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

    new_head = head->left;

    aux = new_head->right;

    new_head->right = old_head;

    old_head->left = aux;

    if(old_head->left == NULL && old_head->right == NULL) {
        old_head->height = 0;
    }
    else{
        old_head->height = _max(_height(old_head->left), _height(old_head->right)) + 1;
    }

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

void freeTree(node* head){
    if(head->right != NULL)
        freeTree(head->right);
    
    if(head->left != NULL)
        freeTree(head->left);
    
    free(head);
}