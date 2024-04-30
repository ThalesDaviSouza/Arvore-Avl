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

void printTree(node* head){
    if(head->right != NULL){
        printTree(head->right);
    }

    printf("Value: %d \t Height: %d \t Count: %d\n", head->value, head->height, head->count);
    
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

void addNode(int value, node* head){
    if(head == NULL) return;

    if(value == head->value){
        head->count++;
        return;
    }

    if(value > head->value){
        if(head->right == NULL){
            head->right = createNode(value);
        }
        else{
            addNode(value, head->right);
        }

        increaseNodeHeight(head, RIGHT);

    }else{
        if(head->left == NULL){
            head->left = createNode(value);
        }
        else{
            addNode(value, head->left);
        }

        increaseNodeHeight(head, LEFT);
    }

}