#include "../libs/minunit.h"
#include "../src/avl_tree.c"
#include <stdbool.h>

MU_TEST(del1){
    node* tree = addNode(10, NULL);
    tree = addNode(20, tree);
    tree = addNode(30, tree);
    tree = addNode(40, tree);    
    tree = addNode(22, tree);
    tree = addNode(43, tree);
    tree = addNode(39, tree);
    tree = addNode(38, tree);
    tree = addNode(44, tree);    
    tree = addNode(37, tree);

    tree = removeNode(39, tree);

    bool sucess = true;
    
    if(findNode(39, tree)){
        printf("39 found?");
        sucess = false;
    }
    else if(!findNode(10, tree)){
        printf("10");
        sucess = false;
    }
    else if(!findNode(20, tree)){
        printf("20");
        sucess = false;
    }
    else if(!findNode(30, tree)){
        printf("30");
        sucess = false;
    }
    else if(!findNode(40, tree)){
        printf("40");
        sucess = false;
    }
    else if(!findNode(22, tree)){
        printf("22");
        sucess = false;
    }
    else if(!findNode(43, tree)){
        printf("43");
        sucess = false;
    }
    else if(!findNode(38, tree)){
        printf("38");
        sucess = false;
    }
    else if(!findNode(44, tree)){
        printf("44");
        sucess = false;
    }
    else if(!findNode(37, tree)){
        printf("37");
        sucess = false;
    }

    freeTree(tree);

    mu_assert(sucess, "In deletion node test 1, the expected result is different from the code's output.");
}

MU_TEST(del2){
    node* tree = addNode(10, NULL);
    tree = addNode(20, tree);
    tree = addNode(30, tree);
    tree = addNode(40, tree);    
    tree = addNode(22, tree);
    tree = addNode(43, tree);
    tree = addNode(39, tree);
    tree = addNode(38, tree);
    tree = addNode(44, tree);    
    tree = addNode(37, tree);

    tree = removeNode(30, tree);

    bool sucess = true;
    
    if(!findNode(39, tree)){
        printf("39");
        sucess = false;
    }
    else if(!findNode(10, tree)){
        printf("10");
        sucess = false;
    }
    else if(!findNode(20, tree)){
        printf("20");
        sucess = false;
    }
    else if(findNode(30, tree)){
        printf("30 found");
        sucess = false;
    }
    else if(!findNode(40, tree)){
        printf("40");
        sucess = false;
    }
    else if(!findNode(22, tree)){
        printf("22");
        sucess = false;
    }
    else if(!findNode(43, tree)){
        printf("43");
        sucess = false;
    }
    else if(!findNode(38, tree)){
        printf("38");
        sucess = false;
    }
    else if(!findNode(44, tree)){
        printf("44");
        sucess = false;
    }
    else if(!findNode(37, tree)){
        printf("37");
        sucess = false;
    }

    freeTree(tree);

    mu_assert(sucess, "In deletion node test 2, the expected result is different from the code's output.");
}

MU_TEST(del3){
    node* tree = addNode(10, NULL);
    tree = addNode(20, tree);
    tree = addNode(30, tree);
    tree = addNode(40, tree);    
    tree = addNode(22, tree);
    tree = addNode(43, tree);
    tree = addNode(39, tree);
    tree = addNode(38, tree);
    tree = addNode(44, tree);    
    tree = addNode(37, tree);

    tree = removeNode(22, tree);

    bool sucess = true;
    
    if(!findNode(39, tree)){
        printf("39");
        sucess = false;
    }
    else if(!findNode(10, tree)){
        printf("10");
        sucess = false;
    }
    else if(!findNode(20, tree)){
        printf("20");
        sucess = false;
    }
    else if(!findNode(30, tree)){
        printf("30");
        sucess = false;
    }
    else if(!findNode(40, tree)){
        printf("40");
        sucess = false;
    }
    else if(findNode(22, tree)){
        printf("22 found");
        sucess = false;
    }
    else if(!findNode(43, tree)){
        printf("43");
        sucess = false;
    }
    else if(!findNode(38, tree)){
        printf("38");
        sucess = false;
    }
    else if(!findNode(44, tree)){
        printf("44");
        sucess = false;
    }
    else if(!findNode(37, tree)){
        printf("37");
        sucess = false;
    }

    freeTree(tree);

    mu_assert(sucess, "In deletion node test 3, the expected result is different from the code's output.");
}

MU_TEST(del4){
    node* tree = addNode(10, NULL);
    tree = addNode(20, tree);
    tree = addNode(30, tree);
    tree = addNode(40, tree);    
    tree = addNode(22, tree);
    tree = addNode(43, tree);
    tree = addNode(39, tree);
    tree = addNode(38, tree);
    tree = addNode(44, tree);    
    tree = addNode(37, tree);

    tree = removeNode(43, tree);

    bool sucess = true;
    
    if(!findNode(39, tree)){
        printf("39");
        sucess = false;
    }
    else if(!findNode(10, tree)){
        printf("10");
        sucess = false;
    }
    else if(!findNode(20, tree)){
        printf("20");
        sucess = false;
    }
    else if(!findNode(30, tree)){
        printf("30");
        sucess = false;
    }
    else if(!findNode(40, tree)){
        printf("40");
        sucess = false;
    }
    else if(!findNode(22, tree)){
        printf("22");
        sucess = false;
    }
    else if(findNode(43, tree)){
        printf("43 found");
        sucess = false;
    }
    else if(!findNode(38, tree)){
        printf("38");
        sucess = false;
    }
    else if(!findNode(44, tree)){
        printf("44");
        sucess = false;
    }
    else if(!findNode(37, tree)){
        printf("37");
        sucess = false;
    }

    freeTree(tree);

    mu_assert(sucess, "In deletion node test 4, the expected result is different from the code's output.");
}

MU_TEST(del5){
    node* tree = addNode(10, NULL);
    tree = addNode(20, tree);
    tree = addNode(30, tree);
    tree = addNode(40, tree);    
    tree = addNode(22, tree);
    tree = addNode(43, tree);
    tree = addNode(39, tree);
    tree = addNode(38, tree);
    tree = addNode(44, tree);    
    tree = addNode(37, tree);

    tree = removeNode(38, tree);

    bool sucess = true;
    
    if(!findNode(39, tree)){
        printf("39");
        sucess = false;
    }
    else if(!findNode(10, tree)){
        printf("10");
        sucess = false;
    }
    else if(!findNode(20, tree)){
        printf("20");
        sucess = false;
    }
    else if(!findNode(30, tree)){
        printf("30");
        sucess = false;
    }
    else if(!findNode(40, tree)){
        printf("40");
        sucess = false;
    }
    else if(!findNode(22, tree)){
        printf("22");
        sucess = false;
    }
    else if(!findNode(43, tree)){
        printf("43");
        sucess = false;
    }
    else if(findNode(38, tree)){
        printf("38 found");
        sucess = false;
    }
    else if(!findNode(44, tree)){
        printf("44");
        sucess = false;
    }
    else if(!findNode(37, tree)){
        printf("37");
        sucess = false;
    }

    freeTree(tree);

    mu_assert(sucess, "In deletion node test 5, the expected result is different from the code's output.");
}

MU_TEST_SUITE(test_suite){
    MU_RUN_TEST(del1);
    MU_RUN_TEST(del2);
    MU_RUN_TEST(del3);
    MU_RUN_TEST(del4);
    MU_RUN_TEST(del5);
      
}


int main(int argc, char** argv){
    MU_RUN_SUITE(test_suite);
    MU_REPORT();

    return MU_EXIT_CODE;
}