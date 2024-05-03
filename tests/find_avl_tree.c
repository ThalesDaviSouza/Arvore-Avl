#include "../libs/minunit.h"
#include "../src/avl_tree.c"
#include <stdbool.h>

MU_TEST(find1){
    node* tree = addNode(10, NULL);
    tree = addNode(40, tree);
    tree = addNode(20, tree);
    tree = addNode(30, tree);

    bool nodeFound = findNode(40, tree) != NULL ? true : false;
    
    freeTree(tree);

    mu_assert(nodeFound, "In find node test 1, the expected result is different from the code's output.");
}

MU_TEST(find2){
    node* tree = addNode(10, NULL);
    tree = addNode(40, tree);
    tree = addNode(20, tree);
    tree = addNode(30, tree);

    bool nodeFound = findNode(50, tree) != NULL ? false : true;
    
    freeTree(tree);

    mu_assert(nodeFound, "In find node test 2, the expected result is different from the code's output.");
}

MU_TEST(find3){
    node* tree = addNode(10, NULL);
    tree = addNode(40, tree);
    tree = addNode(20, tree);
    tree = addNode(30, tree);
    tree = addNode(-30, tree);
    tree = addNode(-20, tree);
    tree = addNode(-12, tree);
    tree = addNode(-22, tree);
    tree = addNode(-22, tree);
    tree = addNode(122, tree);
    tree = addNode(280, tree);
    tree = addNode(50, tree);

    bool nodeFound = findNode(50, tree) != NULL ? true : false;
    
    freeTree(tree);

    mu_assert(nodeFound, "In find node test 3, the expected result is different from the code's output.");
}

MU_TEST(find4){
    node* tree = addNode(10, NULL);
    tree = addNode(40, tree);
    tree = addNode(20, tree);
    tree = addNode(30, tree);
    tree = addNode(-30, tree);
    tree = addNode(-20, tree);
    tree = addNode(-12, tree);
    tree = addNode(-22, tree);
    tree = addNode(-22, tree);
    tree = addNode(122, tree);
    tree = addNode(280, tree);
    tree = addNode(50, tree);

    bool nodeFound = findNode(-12, tree) != NULL ? true : false;
    
    freeTree(tree);

    mu_assert(nodeFound, "In find node test 4, the expected result is different from the code's output.");
}

MU_TEST(find5){
    node* tree = addNode(10, NULL);
    tree = addNode(40, tree);
    tree = addNode(20, tree);
    tree = addNode(30, tree);
    tree = addNode(-30, tree);
    tree = addNode(-20, tree);
    tree = addNode(-12, tree);
    tree = addNode(-22, tree);
    tree = addNode(-22, tree);
    tree = addNode(122, tree);
    tree = addNode(280, tree);
    tree = addNode(50, tree);

    bool nodeFound = findNode(-22, tree) != NULL ? true : false;
    
    freeTree(tree);

    mu_assert(nodeFound, "In find node test 5, the expected result is different from the code's output.");
}


MU_TEST_SUITE(test_suite){
    MU_RUN_TEST(find1);
    MU_RUN_TEST(find2);
    MU_RUN_TEST(find3);
    MU_RUN_TEST(find4);
    MU_RUN_TEST(find5);
    
}


int main(int argc, char** argv){
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}