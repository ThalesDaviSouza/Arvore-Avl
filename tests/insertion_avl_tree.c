#include "../libs/minunit.h"
#include "../src/avl_tree.c"
#include <stdbool.h>

bool treesEqual(node* h1, node* h2){
    if(h1 == NULL && h2 == NULL) return true;
    else if(h1 == NULL) return false;
    else if(h2 == NULL) return false;
    
    if(h1->value == h2->value){
        bool left = treesEqual(h1->left, h2->left);
        bool right = treesEqual(h1->right, h2->right);

        return left && right;
    }
    else{
        return false;
    }
}


// MU_TEST(testeCase){
    

// }

MU_TEST(SimpleRR){
    node* head1 = addNode(1, NULL);
    head1 = addNode(2, head1);
    head1 = addNode(3, head1);
    head1 = addNode(4, head1);
    
    node* head2 = createNode(2);
    head2->left = createNode(1);
    head2->right = createNode(3);
    head2->right->right = createNode(4);    


    bool isEqual = treesEqual(head1, head2); 

    freeTree(head1);
    freeTree(head2);

    mu_assert(isEqual, "In simple RR test 1, the expected result is different from the code's output.");
}

MU_TEST(SimpleRR2){
    node* head1 = addNode(10, NULL);
    head1 = addNode(20, head1);
    head1 = addNode(30, head1);
    head1 = addNode(40, head1);
    head1 = addNode(22, head1);
    head1 = addNode(43, head1);
    

    node* head2 = createNode(30);
    head2->left = createNode(20);
    head2->left->left = createNode(10);
    head2->left->right = createNode(22);
    head2->right = createNode(40);
    head2->right->right = createNode(43);

    bool isEqual = treesEqual(head1, head2); 

    freeTree(head1);
    freeTree(head2);

    mu_assert(isEqual, "In simple RR test 2, the expected result is different from the code's output.");
}

MU_TEST(SimpleLL){
    node* head1 = addNode(10, NULL);
    head1 = addNode(-20, head1);
    head1 = addNode(-30, head1);
    head1 = addNode(-40, head1);
    
    node* head2 = createNode(-20);
    head2->left = createNode(-30);
    head2->left->left = createNode(-40);
    head2->right = createNode(10);

    bool isEqual = treesEqual(head1, head2); 

    freeTree(head1);
    freeTree(head2);

    mu_assert(isEqual, "In simple LL test 1, the expected result is different from the code's output.");
}


MU_TEST(SimpleLL2){
    node* head1 = addNode(10, NULL);
    head1 = addNode(-20, head1);
    head1 = addNode(-30, head1);
    head1 = addNode(-40, head1);
    head1 = addNode(-22, head1);
    head1 = addNode(-50, head1);
    

    node* head2 = createNode(-30);
    head2->left = createNode(-40);
    head2->left->left = createNode(-50);
    head2->right = createNode(-20);
    head2->right->right = createNode(10);
    head2->right->left = createNode(-22);
    
    
    bool isEqual = treesEqual(head1, head2); 

    freeTree(head1);
    freeTree(head2);

    mu_assert(isEqual, "In simple LL test 2, the expected result is different from the code's output.");

}

MU_TEST(LR){
    node* head1 = addNode(10, NULL);
    head1 = addNode(-20, head1);
    head1 = addNode(-30, head1);
    head1 = addNode(-23, head1);
    head1 = addNode(-22, head1);
    

    node* head2 = createNode(-23);
    head2->left = createNode(-30);
    head2->right = createNode(-20);
    head2->right->right = createNode(10);
    head2->right->left = createNode(-22);


    bool isEqual = treesEqual(head1, head2); 

    freeTree(head1);
    freeTree(head2);

    mu_assert(isEqual, "In simple LL test 2, the expected result is different from the code's output.");

}


MU_TEST_SUITE(test_suite){
    MU_RUN_TEST(SimpleRR);
    MU_RUN_TEST(SimpleRR2);
    MU_RUN_TEST(SimpleLL);
    MU_RUN_TEST(SimpleLL2);
    MU_RUN_TEST(LR);
    
}


int main(int argc, char** argv){
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}