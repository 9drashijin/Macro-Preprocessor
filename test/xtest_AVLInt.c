#include "unity.h"
#include "AVL.h"
#include "AVLInt.h"
#include "Rotation.h"
#include <stdio.h>
#include "CustomAssert.h"

void setUp(){}
void tearDown(){}

/**
  *        (1)
  *
  */
void test_avlAddInt_for_1st_element(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt *root = NULL;

    root = (NodeInt *) avlAddInt(root,&Node1);

	TEST_ASSERT_EQUAL_PTR(&Node1, root);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
}
/**
  *   (1)
  *     \
  *     (50)
  *
  */
void test_avlAddInt_for_2nd_element(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt *root = NULL;

    root = (NodeInt *) avlAddInt(root,&Node1);
	root = (NodeInt *) avlAddInt(root,&Node50);

	TEST_ASSERT_EQUAL_PTR(&Node1, root);
	TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node50.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node50.rightChild);

	TEST_ASSERT_EQUAL(1, Node1.balance);
	TEST_ASSERT_EQUAL(0, Node50.balance);

}
/**
  *   (1)              (50)
  *     \              / \
  *     (50)    =>   (1)  (100)
  *      \
  *      (100)
  */
void test_avlAddInt_for_3rd_element(){
	NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};

	NodeInt *root = NULL;

    root = (NodeInt *) avlAddInt(root,&Node1);
	root = (NodeInt *) avlAddInt(root,&Node50);
	root = (NodeInt *) avlAddInt(root,&Node100);

	// printf("root1 %p\n",&Node1);
	// printf("root50 %p\n",&Node50);
	// printf("root100 %p\n",&Node100);

	TEST_ASSERT_EQUAL_PTR(&Node50, root);
	TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild);

	TEST_ASSERT_NOT_NULL(Node50.leftChild);
	TEST_ASSERT_NOT_NULL(Node50.rightChild);

	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node100.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node100.rightChild);

	TEST_ASSERT_EQUAL(0, Node1.balance);
	TEST_ASSERT_EQUAL(0, Node50.balance);
	TEST_ASSERT_EQUAL(0, Node100.balance);
}
/**     (50)
  *    /   \
  *  (1)   (100)
  *         /
  *       (75)
  *
  */
void test_avlAddInt_for_4th_element(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};

	NodeInt *root = NULL;

    root = (NodeInt *) avlAddInt(root,&Node1);
	root = (NodeInt *) avlAddInt(root,&Node50);
	root = (NodeInt *) avlAddInt(root,&Node100);
	root = (NodeInt *) avlAddInt(root,&Node75);

	TEST_ASSERT_EQUAL_PTR(&Node50, root);
	TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node75, root->rightChild->leftChild);

	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.rightChild);

	TEST_ASSERT_EQUAL(0, Node1.balance);
	TEST_ASSERT_EQUAL(1, Node50.balance);
	TEST_ASSERT_EQUAL(-1, Node100.balance);
	TEST_ASSERT_EQUAL(0, Node75.balance);
}
/**	  (50)
  *   /  \
  * (1)  (100)
  *       /  \
  *    (75)  (150)
  *
  */
void test_avlAddInt_for_5th_element(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt *root = NULL;

	// printf("root1 %p\n",&Node1);
	// printf("root50 %p\n",&Node50);
	// printf("root100 %p\n",&Node100);
	// printf("root70 %p\n",&Node75);
	// printf("root150 %p\n",&Node150);

    root = (NodeInt *) avlAddInt(root,&Node1);
	root = (NodeInt *) avlAddInt(root,&Node50);
	root = (NodeInt *) avlAddInt(root,&Node100);
	root = (NodeInt *) avlAddInt(root,&Node75);
	root = (NodeInt *) avlAddInt(root,&Node150);

	TEST_ASSERT_EQUAL_PTR(&Node50, root);
	TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node75, root->rightChild->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node150, Node50.rightChild->rightChild);

	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node150.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node150.rightChild);

	TEST_ASSERT_EQUAL(0, Node1.balance);
	TEST_ASSERT_EQUAL(1, Node50.balance);
	TEST_ASSERT_EQUAL(0, Node100.balance);
	TEST_ASSERT_EQUAL(0, Node75.balance);
	TEST_ASSERT_EQUAL(0, Node150.balance);
}
/**
  *      (100)
  *      /   \
  *    (50)  (150)
  *    /  \		 \
  *  (1)  (75)   (200)
  */
void test_avlAddInt_for_6th_element(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt *root = NULL;

	// printf("root1 %p\n",&Node1);
	// printf("root50 %p\n",&Node50);
	// printf("root100 %p\n",&Node100);
	// printf("root70 %p\n",&Node75);
	// printf("root150 %p\n",&Node150);
	// printf("root200 %p\n",&Node200);

    root = (NodeInt *) avlAddInt(root,&Node1);
	root = (NodeInt *) avlAddInt(root,&Node50);
	root = (NodeInt *) avlAddInt(root,&Node100);
	root = (NodeInt *) avlAddInt(root,&Node75);
	root = (NodeInt *) avlAddInt(root,&Node150);
	root = (NodeInt *) avlAddInt(root,&Node200);

	TEST_ASSERT_EQUAL_PTR(&Node100, root);
	TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node150, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node75, root->leftChild->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node1, Node50.leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node200, Node150.rightChild);

	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node150.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node200.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node200.rightChild);

	TEST_ASSERT_EQUAL(0, Node1.balance);
	TEST_ASSERT_EQUAL(0, Node50.balance);
	TEST_ASSERT_EQUAL(0, Node100.balance);
	TEST_ASSERT_EQUAL(0, Node75.balance);
	TEST_ASSERT_EQUAL(1, Node150.balance);
	TEST_ASSERT_EQUAL(0, Node200.balance);
}
/**
  *       (100)
  *       /    \
  *    (50)    (150)
  *    /  \	   /   \
  *  (1) (75)(120) (200)
  */
void test_avlAddInt_for_7th_element(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node120 = {.data = 120, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt *root = NULL;

	// printf("root1 %p\n",&Node1);
	// printf("root50 %p\n",&Node50);
	// printf("root100 %p\n",&Node100);
	// printf("root70 %p\n",&Node75);
	// printf("root150 %p\n",&Node150);
	// printf("root200 %p\n",&Node200);
	// printf("root120 %p\n",&Node120);

    root = (NodeInt *) avlAddInt(root,&Node1);
	root = (NodeInt *) avlAddInt(root,&Node50);
	root = (NodeInt *) avlAddInt(root,&Node100);
	root = (NodeInt *) avlAddInt(root,&Node75);
	root = (NodeInt *) avlAddInt(root,&Node150);
	root = (NodeInt *) avlAddInt(root,&Node200);
	root = (NodeInt *) avlAddInt(root,&Node120);

	TEST_ASSERT_EQUAL_PTR(&Node100, root);
	TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node150, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node75, root->leftChild->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node1, Node50.leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node200, Node150.rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node120, Node150.leftChild);

	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node200.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node200.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node120.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node120.rightChild);

	TEST_ASSERT_EQUAL(0, Node1.balance);
	TEST_ASSERT_EQUAL(0, Node50.balance);
	TEST_ASSERT_EQUAL(0, Node100.balance);
	TEST_ASSERT_EQUAL(0, Node75.balance);
	TEST_ASSERT_EQUAL(0, Node150.balance);
	TEST_ASSERT_EQUAL(0, Node200.balance);

	TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node150,0,&Node100);
}
 /**          -2
  *         (50)               0  (30)
  *         /  \                  /  \
  *     1(10) (100)         -1 (10)  (50)
  *       / \           =>     /     /  \
  *     (5) (30) 1        0 (5)   (40) (100)
  *           \
  *           (40)
  */
void test_avlAddInt_for_doubleRightRotate(){
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node5 = {.data = 5, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node30  = {.data = 30,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node10  = {.data = 10,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node50  = {.data = 50,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt *root = NULL;

  root = (NodeInt *) avlAddInt(root,&Node30);
  root = (NodeInt *) avlAddInt(root,&Node10);
  root = (NodeInt *) avlAddInt(root,&Node50);
  root = (NodeInt *) avlAddInt(root,&Node5);
  root = (NodeInt *) avlAddInt(root,&Node40);
  root = (NodeInt *) avlAddInt(root,&Node100);

  // printf("30: %p\n",&Node30);
  // printf("50: %p\n",&Node50);
  // printf("10: %p\n",&Node10);
  // printf("5: %p\n",&Node5);
  // printf("40: %p\n",&Node40);
  // printf("100: %p\n",&Node100);

  TEST_ASSERT_EQUAL_PTR(&Node30, root);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node10, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node40, root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild->rightChild);

  TEST_ASSERT_EQUAL_PTR(NULL, Node5.leftChild);
  TEST_ASSERT_EQUAL_PTR(NULL, Node5.rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, Node100.leftChild);
  TEST_ASSERT_EQUAL_PTR(NULL, Node100.rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, Node40.leftChild);
  TEST_ASSERT_EQUAL_PTR(NULL, Node40.rightChild);

  TEST_ASSERT_EQUAL(0, Node30.balance);
  TEST_ASSERT_EQUAL(0, Node50.balance);
  TEST_ASSERT_EQUAL(-1, Node10.balance);
  TEST_ASSERT_EQUAL(0, Node5.balance);
  TEST_ASSERT_EQUAL(0, Node40.balance);
  TEST_ASSERT_EQUAL(0, Node100.balance);

  TEST_ASSERT_EQUAL_AVL_Node(&Node10,&Node50,0,&Node30);
  TEST_ASSERT_EQUAL_AVL_Node(&Node5,NULL,-1,&Node10);
  TEST_ASSERT_EQUAL_AVL_Node(&Node40,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node5);
 }
 /**           2
  *         (50)                 (30)
  *         /  \                /   \
  *     (100) (10)-1          (50)  (10) 1
  *           /  \     =>     /  \    \
  *      -1(30)  (5)      (100) (40)  (5)
  *         /
  *      (40)
  */
void test_avlAddInt_for_doubleLeftRotate(){
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node5 = {.data = 5, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node30  = {.data = 30,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node10  = {.data = 10,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node50  = {.data = 50,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt *root = NULL;

  root = (NodeInt *) avlAddInt(root,&Node50);
  root = (NodeInt *) avlAddInt(root,&Node100);
  root = (NodeInt *) avlAddInt(root,&Node10);
  root = (NodeInt *) avlAddInt(root,&Node30);
  root = (NodeInt *) avlAddInt(root,&Node5);
  root = (NodeInt *) avlAddInt(root,&Node40);

  // printf("30: %p\n",&Node30);
  // printf("50: %p\n",&Node50);
  // printf("10: %p\n",&Node10);
  // printf("5: %p\n",&Node5);
  // printf("40: %p\n",&Node40);
  // printf("100: %p\n",&Node100);

  TEST_ASSERT_EQUAL_AVL_Node(&Node10,&Node50,0,&Node30);
  TEST_ASSERT_EQUAL_AVL_Node(&Node5,NULL,-1,&Node10);
  TEST_ASSERT_EQUAL_AVL_Node(&Node40,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node5);

}

/////////////////////////////////////////////////
//             Test avlGetReplacer             //
/////////////////////////////////////////////////
/**
  *        (1)
  *
  */
void test_avlGetReplacer_for_the_first_case(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt *root = &Node1;
	NodeInt *temp;

    temp = (NodeInt *) avlGetReplacer((Node **) &root);
	TEST_ASSERT_EQUAL_PTR(&Node1, temp);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}
/**
  *   	  (1)
  *       /
  *     (50)
  *
  */
void test_avlGetReplacer_for_the_2nd_case(){
	NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node1 = {.data = 1, .balance = 1, .leftChild =  &Node50, . rightChild = NULL};
	NodeInt *root = &Node1;
	NodeInt *temp;

    temp = (NodeInt *) avlGetReplacer((Node **) &root);

	TEST_ASSERT_EQUAL_PTR(&Node1, temp);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
}
/**
  *   (1)
  *     \
  *     (50)
  *
  */
void test_avlGetReplacer_for_the_3rd_case(){
	NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node1 = {.data = 1, .balance = 1, .leftChild = NULL, . rightChild = &Node50};
	NodeInt *root = &Node1;
	NodeInt *temp;

    temp = (NodeInt *) avlGetReplacer((Node **) &root);

	TEST_ASSERT_EQUAL_PTR(&Node50, temp);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}

/**
  *     (50)
  *    /   \
  *  (1)  (100)
  *
  */
void test_avlGetReplacer_for_the_4th_case(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = &Node1, . rightChild = &Node100};
	NodeInt *root = &Node50;
	NodeInt *temp;

	temp = (NodeInt *) avlGetReplacer((Node **) &root);

	TEST_ASSERT_EQUAL_PTR(&Node100, temp);
	TEST_ASSERT_EQUAL_PTR(NULL, Node50.rightChild);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node50);

}
/**     (50)
  *    /    \
  *  (1)   (100)
  *         /
  *       (75)
  *
  */
void test_avlGetReplacer_for_the_5th_case(){
	NodeInt Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = &Node75, . rightChild = NULL};
	NodeInt Node50 = {.data = 50, .balance = 1, .leftChild = &Node1, . rightChild = &Node100};
	NodeInt *root = &Node50;
	NodeInt *temp;

  // printf("root1 %p\n",&Node1);
	// printf("root50 %p\n",&Node50);
	// printf("root100 %p\n",&Node100);
	// printf("root70 %p\n\n",&Node75);

	temp = (NodeInt *) avlGetReplacer((Node **) &root);

	TEST_ASSERT_EQUAL_PTR(&Node100, temp);

  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node75,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);

}
/**    	  (50)
  *  	   /   \
  *  	 (10) (100)
  *    /    /  \
  *  (1) (75) (120)
  *  		       /
	*		      (110)
  */
void test_avlGetReplacer_for_the_6th_case(){
	NodeInt Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node110 = {.data = 110, .balance = 0, .leftChild = NULL, . rightChild = NULL};

	NodeInt Node120 = {.data = 120, .balance = -1, .leftChild = &Node110, . rightChild = NULL};

	NodeInt Node100 = {.data = 100, .balance = 1, .leftChild = &Node75, . rightChild = &Node120};
	NodeInt Node10 = {.data = 10, .balance = -1, .leftChild = &Node1, . rightChild = NULL};

	NodeInt Node50 = {.data = 50, .balance = 1, .leftChild = &Node10, . rightChild = &Node100};
	NodeInt *root = &Node50;
	NodeInt *temp;

  // printf("root120 %p\n",&Node120);
	// printf("root110 %p\n",&Node110);
	// printf("root100 %p\n",&Node100);
	// printf("root75 %p\n",&Node75);

	temp = (NodeInt *) avlGetReplacer((Node **) &root);

	TEST_ASSERT_EQUAL_PTR(&Node120, temp);

  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node110,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node10);

  TEST_ASSERT_EQUAL_AVL_Node(&Node10,&Node100,0,&Node50);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node110);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}
/**    	  (100)                 (75)
  *  	   /   \                  /   \
  *  	 (50) (120)             (50)  100
  *    /  \     \       =>   /  \   /  \
  *  (10) (75)  (150)      (10) 60 80   120
  *  		 /  \
	*		(60)  (80)
  */
void test_avlGetReplacer_for_the_7th_case(){
  NodeInt Node60 = {.data = 60, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node80 = {.data = 80, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node10 = {.data = 10, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node120 = {.data = 120, .balance = 1, .leftChild = NULL, . rightChild = &Node150};

	NodeInt Node75 = {.data = 75, .balance = 0, .leftChild = &Node60, . rightChild = &Node80};

  NodeInt Node50 = {.data = 50, .balance = 1, .leftChild = &Node10, . rightChild = &Node75};

	NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node50, . rightChild = &Node120};

	NodeInt *root = &Node100;
	NodeInt *temp;

	temp = (NodeInt *) avlGetReplacer((Node **) &root);

	TEST_ASSERT_EQUAL_PTR(&Node150, temp);

  TEST_ASSERT_EQUAL_AVL_Node(&Node80,&Node120,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node100,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(&Node10,&Node60,0,&Node50);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node120);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node80);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node60);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node10);
}

/**
  *     (50)            10
  *    /   \          /   \
  *  (10)  (100)  => 1    50
  *  /
  *(1)
  */
void test_avlGetReplacer_for_the_8th_case(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node10 = {.data = 10, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
	NodeInt Node50 = {.data = 50, .balance = -1, .leftChild = &Node10, . rightChild = &Node100};

	NodeInt *root = &Node50;
	NodeInt *temp;

	temp = (NodeInt *) avlGetReplacer((Node **) &root);

	TEST_ASSERT_EQUAL_PTR(&Node100, temp);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node50,0,&Node10);
}
/**     100                50
  *     / \               /  \
  *    25  150          25    100
  *   / \   \     =>   / \    / \
  *  1  50   200      1  40  75 150
  *     / \
  *   40  75
  */
void test_avlGetReplacer_for_the_9th_case(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = &Node40, . rightChild = &Node75};

  NodeInt Node25 = {.data = 25, .balance = 1, .leftChild = &Node1, . rightChild = &Node50};
  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};

	NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node25, . rightChild = &Node150};

	NodeInt *root = &Node100;
	NodeInt *temp;

	temp = (NodeInt *) avlGetReplacer((Node **) &root);

	TEST_ASSERT_EQUAL_PTR(&Node200, temp);
	TEST_ASSERT_EQUAL_PTR(&Node50 , root);

  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node40,0,&Node25);

  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,0,&Node100);//zxc

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
}
/**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /       /  \
 *   1   50    200       1   50             1      75  150
 *         \                   \
 *         75                  75
 *
 * where 200 is being removed
 */
void test_avlGetReplacer_for_the_10th_case(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = 1, .leftChild = NULL, . rightChild = &Node75};

  NodeInt Node25 = {.data = 25, .balance = 1, .leftChild = &Node1, . rightChild = &Node50};
  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};

	NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node25, . rightChild = &Node150};

	NodeInt *root = &Node100;
	NodeInt *temp;

	temp = (NodeInt *) avlGetReplacer((Node **) &root);

	TEST_ASSERT_EQUAL_PTR(&Node200, temp);
	TEST_ASSERT_EQUAL_PTR(&Node50 , root);

  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);

  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,0,&Node100);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
}
/**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /  \       \
 *   1   50    200       1   50             1   40      150
 *      /                   /
 *     40                  40
 *
 * where 200 is being removed
 */
void test_avlGetReplacer_for_the_11th_case(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = -1, .leftChild = &Node40, . rightChild = NULL};

  NodeInt Node25 = {.data = 25, .balance = 1, .leftChild = &Node1, . rightChild = &Node50};
  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};

	NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node25, . rightChild = &Node150};

	NodeInt *root = &Node100;
	NodeInt *temp;

	temp = (NodeInt *) avlGetReplacer((Node **) &root);

	TEST_ASSERT_EQUAL_PTR(&Node200, temp);
	TEST_ASSERT_EQUAL_PTR(&Node50 , root);

  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,1,&Node50);//zxc
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node40,0,&Node25);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node150,0,&Node100); //zxc

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
}
/**
 *        100                  100                40
 *      /    \               /    \             /    \
 *     40    150           40     150         25     100
 *    /  \     \    =>    /  \          =>   /       /  \
 *   25  75   200        25  75             1      75   150
 *  /    /              /    /                    /
 * 1    50             1    50                  50
 *
 * where 200 is being removed
 */
void test_avlGetReplacer_for_the_12th_case(){
	NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node75 = {.data = 75, .balance = -1, .leftChild = &Node50, . rightChild = NULL};
  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};

  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = &Node25, . rightChild = &Node75};

  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};

	NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node40, . rightChild = &Node150};

	NodeInt *root = &Node100;
	NodeInt *temp;

	temp = (NodeInt *) avlGetReplacer((Node **) &root);

	TEST_ASSERT_EQUAL_PTR(&Node200, temp);
	TEST_ASSERT_EQUAL_PTR(&Node40 , root);

  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,1,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,NULL,-1,&Node75);

  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,-1,&Node100);//zxc

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
}

// ====================================================
//					REMOVE AVL
// ====================================================

//////////////////////////////////////////////////////////////
// Test avlRemoveInt() on deletion of node on the left subtree //
//////////////////////////////////////////////////////////////

/**
 *      50  => NULL
 *
 * where 50 is being removed
 */
void test_avlRemoveInt_for_1st_element(){
	NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node50);

	TEST_ASSERT_NULL(root);
	TEST_ASSERT_NOT_NULL(temp);

	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
}
/**
 *        50                 50
 *      /   \               /  \
 *     25   150    =>     25   150
 *             \                  \
 *             200                200
 *
 * Attempt to remove 1, which cannot be found in the tree.
 */
void test_avlRemoveInt_on_left_subtree_for_2nd_case(){
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node25 = {.data = 25, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};
  NodeInt Node50= {.data = 50, .balance = 1, .leftChild = &Node25, . rightChild = &Node150};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node1);

	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_NULL(temp);

	// printf("root200 %p\n",&Node200);
	// printf("root25 %p\n",&Node25);
	// printf("root150 %p\n",&Node150);
	// printf("root50 %p\n",&Node50);
	// printf("root1 %p\n",&Node1);

	TEST_ASSERT_EQUAL_AVL_Node(&Node25,NULL,0,&Node50); //zxc
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node200,0,&Node150); // zxc
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);

}
/**
 *      50             50
 *     /  \     =>       \
 *   25   100            100
 *
 * where 25 is being removed
 */
void test_avlRemoveInt_for_3rd_case(){
	NodeInt Node25 = {.data = 25, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = &Node25, . rightChild = &Node100};
	NodeInt *root = &Node50;
	NodeInt *temp;

	temp = (NodeInt *) avlRemoveInt(&root,&Node25);

	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_NOT_NULL(temp);
	TEST_ASSERT_NOT_NULL(&Node25);
	TEST_ASSERT_NOT_NULL(&Node50);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node100,1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node100);
}
/**
 *        50                 150
 *      /   \               /  \
 *     25   150    =>     50   200
 *             \
 *             200
 *
 * where 25 is being removed
 */
void test_avlRemoveInt_on_left_subtree_for_4th_case(){
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node25 = {.data = 25, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};
  NodeInt Node50= {.data = 50, .balance = 1, .leftChild = &Node25, . rightChild = &Node150};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node25);

  TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_NOT_NULL(temp);

  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node200,0,&Node150); //zxc

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
}

/**
 *        50                 50
 *      /   \               /  \
 *    25    150    =>     1    150
 *    /       \                  \
 *   1       200                 200
 *
 * where 25 is being removed
 */
void test_avlRemoveInt_on_left_subtree_for_5th_case(){
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};

  NodeInt Node50= {.data = 50, .balance = 0, .leftChild = &Node25, . rightChild = &Node150};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node25);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node150,1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node200,1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);


}
/**
 *        100                  100                    150
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     200
 *    /     /  \    =>            /  \     =>    /  \     /  \
 *   1    150  220              150  220        25  120 175  220
 *       /  \                  /  \
 *     120  175              120  175
 *
 * where 1 is being removed
 */
void test_avlRemoveInt_on_left_subtree_for_6th_case(){
  NodeInt Node220 = {.data = 220, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node120 = {.data = 120, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node175 = {.data = 175, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 0, .leftChild = &Node120, . rightChild = &Node175};
  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = -1, .leftChild = &Node150, . rightChild = &Node220};

  NodeInt Node100= {.data = 100, .balance = 1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node100;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node1);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node200,0,&Node150);
  // TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node120,0,&Node100);
  // TEST_ASSERT_EQUAL_AVL_Node(&Node175,&Node220,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node120);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
}
/**
 *        100                  100                    150
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     200
 *    /     /  \    =>            /  \     =>    /  \       \
 *   1    150  220              150  220        25  120     220
 *       /                     /
 *     120                   120
 *
 * where 1 is being removed
 */
void test_avlRemoveInt_on_left_subtree_for_7th_case(){
  NodeInt Node220 = {.data = 220, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node120 = {.data = 120, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = -1, .leftChild = &Node120, . rightChild = NULL};
  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = -1, .leftChild = &Node150, . rightChild = &Node220};

  NodeInt Node100= {.data = 100, .balance = 1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node100;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node1);

  TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node200,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node120,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node220,1,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node120);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
}
/**
 *        100                  100                    150
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     200
 *    /     /  \    =>            /  \     =>    /        /  \
 *   1    150  220              150  220        25      175  220
 *          \                     \
 *          175                   175
 *
 * where 1 is being removed
 */
void test_avlRemoveInt_on_left_subtree_for_8th_case(){
  NodeInt Node220 = {.data = 220, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node175 = {.data = 175, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node175};
  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = -1, .leftChild = &Node150, . rightChild = &Node220};

  NodeInt Node100= {.data = 100, .balance = 1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node100;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node1);

  TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node200,0,&Node150);
  // TEST_ASSERT_EQUAL_AVL_Node(&Node25,NULL,-1,&Node100);
  // TEST_ASSERT_EQUAL_AVL_Node(&Node175,&Node220,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
}
/**
 *        100                  100                    200
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     220
 *    /     /  \    =>            /  \     =>    /  \       \
 *   1    150  220              150  220        25  150     250
 *          \    \                \    \              \
 *          175  250              175  250            175
 *
 * where 1 is being removed
 */
void test_avlRemoveInt_on_left_subtree_for_9th_case(){
  NodeInt Node250 = {.data = 250, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node175 = {.data = 175, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node175};
  NodeInt Node220 = {.data = 220, .balance = 1, .leftChild = NULL, . rightChild = &Node250};
  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};


  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = &Node150, . rightChild = &Node220};

  NodeInt Node100= {.data = 100, .balance = 1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node100;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node1);

  TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node220,-1,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node250,1,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node175,1,&Node150);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node250);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
}

/**
 *      50             50
 *     /  \     =>    /  \
 *   25   200       40   200
 *    \
 *    40
 *
 * where 25 is being removed
 */
void test_avlRemoveInt_on_left_subtree_for_10th_case(){
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node25 = {.data = 25, .balance = 1, .leftChild = NULL, . rightChild = &Node40};
  NodeInt Node50 = {.data = 50, .balance = -1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node25);

	// printf("root200 %p\n",&Node200);
	// printf("root25 %p\n",&Node25);
	// printf("root40 %p\n",&Node40);
	// printf("root50 %p\n",&Node50);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node40,&Node200,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
}
/**
 *       50             50
 *      /  \     =>    /  \
 *    25   200        1   200
 *   / \               \
 *  1  40              40
 *
 * where 25 is being removed
 */
void test_avlRemoveInt_on_left_subtree_for_11th_case(){
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node25 = {.data = 25, .balance = 0, .leftChild = &Node1, . rightChild = &Node40};
  NodeInt Node50 = {.data = 50, .balance = -1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node25);
  // TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node200,-1,&Node50);
  // TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node40,1,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
}
 /**
 *      150              90
 *     /  \             /  \
 *   25   200    =>   25   200
 *  / \     \        / \     \
 * 1   50   250     1   50   250
 *       \
 *       90
 *
 * where 150 is being removed
 */
void test_avlRemoveInt_on_left_subtree_for_12th_case(){
  NodeInt Node250 = {.data = 250, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node90 = {.data = 90, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = 1, .leftChild = NULL, . rightChild = &Node90};
  NodeInt Node25 = {.data = 25, .balance = 1, .leftChild = &Node1, . rightChild = &Node50};
  NodeInt Node200 = {.data = 200, .balance = 1, .leftChild = NULL, . rightChild = &Node250};

  NodeInt Node150 = {.data = 150, .balance = -1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node150;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node150);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node200,0,&Node90);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node50,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node250,1,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node250);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  // TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
}
/**
 *      150              90
 *     /  \             /  \
 *   25   200    =>   25   200
 *  / \     \        / \     \
 * 1   50   250     1   50   250
 *    /  \              /
 *   40  90            40
 *
 * where 150 is being removed
 */
void test_avlRemoveInt_on_left_subtree_for_13th_case(){
  NodeInt Node250 = {.data = 250, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node90 = {.data = 90, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = &Node40, . rightChild = &Node90};
  NodeInt Node25 = {.data = 25, .balance = 1, .leftChild = &Node1, . rightChild = &Node50};
  NodeInt Node200 = {.data = 200, .balance = 1, .leftChild = NULL, . rightChild = &Node250};

  NodeInt Node150 = {.data = 150, .balance = -1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node150;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node150);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node200,-1,&Node90);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node50,1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node250,1,&Node200);
  // TEST_ASSERT_EQUAL_AVL_Node(&Node40,NULL,-1,&Node50);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node250);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
}


///////////////////////////////////////////////////////////////
// Test avlRemoveInt() on deletion of node on the right subtree //
///////////////////////////////////////////////////////////////


/**
 *        50                 50
 *      /   \               /  \
 *     25   150    =>     25   150
 *    /                  /
 *   1                  1
 *
 * Attempt to remove 200, which cannot be found in the tree.
 */
void test_avlRemoveInt_on_right_subtree_for_1st_case(){
  NodeInt Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node50= {.data = 50, .balance = -1, .leftChild = &Node25, . rightChild = &Node150};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node200);

	TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_NULL(temp);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,-1,&Node50);
  // TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}
/**
 *      50             50
 *     /  \     =>    /
 *   25   150       25
 *
 * where 150 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_2nd_case(){
  NodeInt Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node25 = {.data = 25, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = &Node25, . rightChild = &Node150};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node150);

  TEST_ASSERT_EQUAL_AVL_Node(&Node25,NULL,-1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);

}
/**
 *        50                 50            25
 *      /   \               /            /   \
 *     25   150    =>     25       =>   1    50
 *    /                  /
 *   1                  1
 *
 * where 150 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_3rd_case(){
  NodeInt Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = -1, .leftChild = &Node25, . rightChild = &Node150};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node150);

  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node50,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}
/**
 *        50                 50
 *      /   \               /  \
 *     25   150    =>     25   200
 *    /       \          /
 *   1       200        1
 *
 * where 150 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_4th_case(){
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};

  NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = &Node25, . rightChild = &Node150};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node150);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node200,-1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);

}
/**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /  \    /  \
 *   1   50    200       1   50             1   40  75  150
 *      /  \                /  \
 *     40  75              40  75
 *
 * where 200 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_5th_case(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = &Node40, . rightChild = &Node75};

  NodeInt Node25 = {.data = 25, .balance = 1, .leftChild = &Node1, . rightChild = &Node50};
  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};

	NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node25, . rightChild = &Node150};
  NodeInt *root = &Node100;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node200);

  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node40,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,0,&Node100);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);

}
/**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /       /  \
 *   1   50    200       1   50             1      75  150
 *         \                   \
 *         75                  75
 *
 * where 200 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_6th_case(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = 1, .leftChild = NULL, . rightChild = &Node75};

  NodeInt Node25 = {.data = 25, .balance = 1, .leftChild = &Node1, . rightChild = &Node50};
  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};

	NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node25, . rightChild = &Node150};
  NodeInt *root = &Node100;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node200);

  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,0,&Node100);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}
/**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /  \       \
 *   1   50    200       1   50             1   40      150
 *      /                   /
 *     40                  40
 *
 * where 200 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_7th_case(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = -1, .leftChild = &Node40, . rightChild = NULL};

  NodeInt Node25 = {.data = 25, .balance = 1, .leftChild = &Node1, . rightChild = &Node50};
  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};

	NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node25, . rightChild = &Node150};
  NodeInt *root = &Node100;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node200);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node40,0,&Node25);
  // TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node150,1,&Node100);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}
/**
 *        100                  100                40
 *      /    \               /    \             /    \
 *     40    150           40     150         25     100
 *    /  \     \    =>    /  \          =>   /       /  \
 *   25  75   200        25  75             1      75   150
 *  /    /              /    /                    /
 * 1    50             1    50                  50
 *
 * where 200 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_8th_case(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node75 = {.data = 75, .balance = -1, .leftChild = &Node50, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = &Node25, . rightChild = &Node75};

	NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node40, . rightChild = &Node150};
  NodeInt *root = &Node100;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node200);

  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,1,&Node40);

  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,-1,&Node100);

  TEST_ASSERT_EQUAL_AVL_Node(&Node50,NULL,-1,&Node75);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}
/**
 *      50             50
 *     /  \     =>    /  \
 *   25   200       25   150
 *        /
 *      150
 *
 * where 200 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_9th_case(){
  NodeInt Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node25 = {.data = 25, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node200 = {.data = 200, .balance = -1, .leftChild = &Node150, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = 1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node200);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
}
/**
 *      50             50
 *     /  \     =>    /  \
 *   25   200       25   150
 *        / \              \
 *      150 220            220
 *
 * where 200 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_10th_case(){
  NodeInt Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node25 = {.data = 25, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node220 = {.data = 220, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = &Node150, . rightChild = &Node220};

  NodeInt Node50 = {.data = 50, .balance = 1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node200);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,1,&Node50);
  // TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node220,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);

}
/**
 *      50               50
 *     /  \             /  \
 *   25   200    =>   25   175
 *  /     / \        /    /  \
 * 1    150 250     1   150  250
 *        \
 *        175
 *
 * where 200 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_11th_case(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node250 = {.data = 250, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node175 = {.data = 175, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node175};

  NodeInt Node200 = {.data = 200, .balance = -1, .leftChild = &Node150, . rightChild = &Node250};
  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = 1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node200);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node175,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  // TEST_ASSERT_EQUAL_AVL_Node(&Node150,&Node250,0,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  // TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node250);
}
/**
 *      50               50
 *     /  \             /  \
 *   25   200    =>   25   175
 *  /     / \        /    /  \
 * 1    150 250     1   150  250
 *      / \             /
 *    120 175         120
 *
 * where 200 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_12th_case(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node250 = {.data = 250, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node175 = {.data = 175, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node120 = {.data = 120, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 0, .leftChild = &Node120, . rightChild = &Node175};

  NodeInt Node200 = {.data = 200, .balance = -1, .leftChild = &Node150, . rightChild = &Node250};
  NodeInt Node25 = {.data = 25, .balance = -1, .leftChild = &Node1, . rightChild = NULL};

  NodeInt Node50 = {.data = 50, .balance = 1, .leftChild = &Node25, . rightChild = &Node200};
  NodeInt *root = &Node50;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node200);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node175,1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  // TEST_ASSERT_EQUAL_AVL_Node(&Node150,&Node250,-1,&Node175);
  // TEST_ASSERT_EQUAL_AVL_Node(&Node120,NULL,-1,&Node150);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node120);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node250);
}
/**
 *              175                                   175
 *          /          \                         /          \
 *        100          400                     100          350
 *       /   \       /     \                  /   \       /     \
 *     50    150   250     500       =>     50    150   250     500
 *    / \    /   /    \     / \            / \    /   /    \     / \
 *  25  65 120 200    300 450 550        25  65 120 200    300 450 550
 *   \          \     / \      \          \          \     / \      \
 *   40         220 270 350    600        40         220 270 330    600
 *                      /
 *                    330
 *
 * where 400 is being removed
 */
void test_avlRemoveInt_on_right_subtree_for_13th_case(){
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node65 = {.data = 65, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node120 = {.data = 120, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node220 = {.data = 220, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node270 = {.data = 270, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node330 = {.data = 330, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node450 = {.data = 450, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node600 = {.data = 600, .balance = 0, .leftChild = NULL, . rightChild = NULL};   //8

  NodeInt Node25 = {.data = 25, .balance = 1, .leftChild = NULL, . rightChild = &Node40};
  NodeInt Node150 = {.data = 150, .balance = -1, .leftChild = &Node120, . rightChild = NULL};
  NodeInt Node200 = {.data = 200, .balance = 1, .leftChild = NULL, . rightChild = &Node220};
  NodeInt Node350 = {.data = 350, .balance = -1, .leftChild = &Node330, . rightChild = NULL};
  NodeInt Node550 = {.data = 550, .balance = 1, .leftChild = NULL, . rightChild = &Node600};     //5

  NodeInt Node300 = {.data = 300, .balance = 1, .leftChild = &Node270, . rightChild = &Node350};
  NodeInt Node500 = {.data = 500, .balance = 1, .leftChild = &Node450, . rightChild = &Node550};
  NodeInt Node50 = {.data = 50, .balance = -1, .leftChild = &Node25, . rightChild = &Node65};      //3

  NodeInt Node250 = {.data = 250, .balance = 1, .leftChild = &Node200, . rightChild = &Node300};

  NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node50, . rightChild = &Node150};
  NodeInt Node400 = {.data = 400, .balance = -1, .leftChild = &Node250, . rightChild = &Node500};

  NodeInt Node175 = {.data = 175, .balance = 1, .leftChild = &Node100, . rightChild = &Node400};

  NodeInt *root = &Node175;
	NodeInt *temp;

  temp = (NodeInt *) avlRemoveInt(&root,&Node400);

  // TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node350,0,&Node175);

  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node150,-1,&Node100);
  // TEST_ASSERT_EQUAL_AVL_Node(&Node250,&Node500,0,&Node350);

  TEST_ASSERT_EQUAL_AVL_Node(&Node450,&Node550,1,&Node500);   //3
  TEST_ASSERT_EQUAL_AVL_Node(&Node200,&Node300,0,&Node250);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node65,-1,&Node50);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node600,1,&Node550);     //5
  // TEST_ASSERT_EQUAL_AVL_Node(&Node270,&Node330,0,&Node300);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node220,1,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node120,NULL,-1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node40,1,&Node25);

  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);  //8
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node65);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node120);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node270);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node330);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node450);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node600);

}