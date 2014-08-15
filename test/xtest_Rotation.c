#include "unity.h"
#include "Rotation.h"
#include "AVL.h"
#include "AVLInt.h"

void setUp(){}
void tearDown(){}

/**
  *   (1)              (2)
  *     \              / \
  *     (2)    =>   (1)  (3)
  *      \
  *      (3)
  */

void test_leftRotate_given_3_elements_should_rotate_to_balance_tree(){
  NodeInt Node3 = {.data = 3, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node2 = {.data = 2, .balance = 1, .leftChild = NULL, . rightChild = &Node3};
  NodeInt Node1 = {.data = 1, .balance = 2, .leftChild = NULL, . rightChild = &Node2};
  NodeInt *root;

  root = (NodeInt *) leftRotate((Node *) &Node1);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);

  TEST_ASSERT_EQUAL(0, Node2.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node3.balance);
}

void test_Xbalance_same_case_with_above_test(){
  NodeInt Node3 = {.data = 3, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node2 = {.data = 2, .balance = 1, .leftChild = NULL, . rightChild = &Node3};
  NodeInt Node1 = {.data = 1, .balance = 2, .leftChild = NULL, . rightChild = &Node2};

  NodeInt *root;

  TEST_ASSERT_EQUAL(2, Node1.balance);

  root = (NodeInt *) leftRotate((Node *) &Node1);

  TEST_ASSERT_NOT_NULL(root);
  TEST_ASSERT_NOT_NULL(root->leftChild);
  TEST_ASSERT_NOT_NULL(root->rightChild);

  TEST_ASSERT_NULL(root->leftChild->leftChild);
  TEST_ASSERT_NULL(root->leftChild->rightChild);
  TEST_ASSERT_NULL(root->rightChild->leftChild);
  TEST_ASSERT_NULL(root->rightChild->rightChild);

}


/**
  *       (3)        (2)
  *       /          / \
  *     (2)   =>  (1)  (3)
  *     /
  *   (1)
  */

void test_rightRotate_given_3_elements_should_rotate_to_balance_tree(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node2 = {.data = 2, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node3 = {.data = 3, .balance = -2, .leftChild = &Node2, . rightChild = NULL};

  NodeInt *root;

  root = (NodeInt *) rightRotate((Node *) &Node3);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);

  TEST_ASSERT_NULL(root->leftChild->leftChild);
  TEST_ASSERT_NULL(root->leftChild->rightChild);
  TEST_ASSERT_NULL(root->rightChild->leftChild);
  TEST_ASSERT_NULL(root->rightChild->rightChild);

  TEST_ASSERT_EQUAL(0, Node2.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node3.balance);


}

/**
  *       (3)        (2)
  *       /          / \
  *     (1)   =>  (1)  (3)
  *       \
  *       (2)
  */

void test_doubleRightRotate_given_3_elements_should_rotate_to_balance_tree(){

  NodeInt Node2 = {.data = 2, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 1, .leftChild = NULL, . rightChild = &Node2};
  NodeInt Node3 = {.data = 3, .balance = -2, .leftChild = &Node1, . rightChild = NULL};


  NodeInt *root;

  root = (NodeInt *) doubleRightRotate((Node *) &Node3);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);

  TEST_ASSERT_EQUAL(0, Node2.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node3.balance);

}

/**
  *   (1)          (2)
  *     \          / \
  *     (3)  =>  (1) (3)
  *     /
  *   (2)
  */

void test_doubleLeftRotate_given_3_elements_should_rotate_to_balance_tree(){

  NodeInt Node2 = {.data = 2, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node3 = {.data = 3, .balance = -1, .leftChild = &Node2, . rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 2, .leftChild = NULL, . rightChild = &Node3};

  NodeInt *root;

  root = (NodeInt *) doubleLeftRotate((Node *) &Node1);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);

  // TEST_ASSERT_EQUAL(0, Node2.balance);
  // TEST_ASSERT_EQUAL(0, Node1.balance);
  // TEST_ASSERT_EQUAL(0, Node3.balance);
}
/**
  *        (50)              (10) 2
  *        /  \              /  \
  *     (10)  (100)  =>    (5)  (50) 1
  *     /  \               /    /  \
  *   (5)  (30)          (1) (30)  (100) 0
  *   /
  * (1)
  *
  */
void test_fakeTREE_right_single(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node30 = {.data = 30, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node5 = {.data = 5, .balance = 1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node10 = {.data = 10, .balance = 2, .leftChild = &Node5, . rightChild = &Node30};
  NodeInt Node50 = {.data = 50, .balance = 2, .leftChild = &Node10, . rightChild = &Node100};

  NodeInt *root;

  root = (NodeInt *) tree((Node *) &Node50);
  TEST_ASSERT_EQUAL_PTR(&Node10, root);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);

  TEST_ASSERT_EQUAL(2, Node10.balance);
  TEST_ASSERT_EQUAL(1, Node5.balance);
  TEST_ASSERT_EQUAL(1, Node50.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node30.balance);
  TEST_ASSERT_EQUAL(0, Node100.balance);

}

/**
  *       (3)
  *       /
  *     (2)
  *     /
  *   (1)
  */
void test_getHeight_left_given_3_elements_should_get_the_height_to_balance_tree(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node2 = {.data = 2, .balance = 1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node3 = {.data = 3, .balance = 2, .leftChild = &Node2, . rightChild = NULL};

  int height = getHeight((Node *)  &Node3);

  TEST_ASSERT_EQUAL(3, height);
}
/**
  *   (1)
  *     \
  *     (2)
  *      \
  *      (3)
  */
void test_getHeight_right_given_3_elements_should_get_the_height_to_balance_tree(){
	NodeInt Node3 = {.data = 3, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node2 = {.data = 2, .balance = 1, .leftChild = NULL, . rightChild = &Node3};
  NodeInt Node1 = {.data = 1, .balance = 2, .leftChild = NULL, . rightChild = &Node2};

  int height = getHeight((Node *)  &Node1);

  TEST_ASSERT_EQUAL(3, height);
}
/**
  *        (50)              (10) 2
  *        /  \              /  \
  *     (10)  (100)  =>    (5)  (50) 1
  *     /  \               /    /  \
  *   (5)  (30)          (1) (30)  (100) 0
  *   /
  * (1)
  *
  */
void test_getHeight_for_the_5_element_above(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node30 = {.data = 30, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node5 = {.data = 5, .balance = 1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node10 = {.data = 10, .balance = 2, .leftChild = &Node5, . rightChild = &Node30};
  NodeInt Node50 = {.data = 50, .balance = 2, .leftChild = &Node10, . rightChild = &Node100};

  int height = getHeight((Node *)  &Node50);

  TEST_ASSERT_EQUAL(4, height);
}
/**
  *           (5)
  *           /
  *         (4)
  *         /
  *       (3)
  *       /
  *     (2)
  *     /
  *   (1)
  */
void test_getHeight_for_the_height_of_5_element(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node2 = {.data = 2, .balance = 1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node3 = {.data = 3, .balance = 2, .leftChild = &Node2, . rightChild = NULL};
  NodeInt Node4 = {.data = 4, .balance = 3, .leftChild = &Node3, . rightChild = NULL};
  NodeInt Node5 = {.data = 5, .balance = 4, .leftChild = &Node4, . rightChild = NULL};

  int height = getHeight((Node *)  &Node5);

  TEST_ASSERT_EQUAL(5, height);

}
/**
  *        (50)                  (100) 0
  *        /  \                  /   \
  *     (10)  (100)            (50)  (150) 1
  *           /  \      =>    /   \     \
  *        (70)  (150)      (10) (70)   (200) 0
  *                \
  *               (200)
  */
void test_leftRotate_given_6_element_should_rotate_to_balance_the_tree_case1(){
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};
  NodeInt Node70  = {.data = 70,  .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node100 = {.data = 100, .balance = 1, .leftChild = &Node70, . rightChild = &Node150};
  NodeInt Node10  = {.data = 10,  .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50  = {.data = 50,  .balance = 2, .leftChild = &Node10, . rightChild = &Node100};
  NodeInt *root;

  root = (NodeInt *) leftRotate((Node *) &Node50);

  TEST_ASSERT_EQUAL_PTR(&Node100, root);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node150, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node10, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node70, root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node200, root->rightChild->rightChild);

  TEST_ASSERT_EQUAL(0, Node50.balance);
  TEST_ASSERT_EQUAL(0, Node10.balance);
  TEST_ASSERT_EQUAL(0, Node100.balance);
  TEST_ASSERT_EQUAL(0, Node70.balance);
  TEST_ASSERT_EQUAL(1, Node150.balance);
  TEST_ASSERT_EQUAL(0, Node200.balance);
 }
 /**
  *         (50)               0  (10)
  *         /  \                  /  \
  *       (10) (100)         -1 (5)  (50)
  *       / \           =>     /     /  \
  *     (5) (30)           0 (1)   (30) (100)
  *     /
  *   (1)
  *
  */
void test_rightRotate_given_6_element_should_rotate_to_balance_the_tree_case1(){
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node5 = {.data = 5, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
  NodeInt Node30  = {.data = 30,  .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node10  = {.data = 10,  .balance = -1, .leftChild = &Node5, . rightChild = &Node30};

  NodeInt Node50  = {.data = 50,  .balance = -2, .leftChild = &Node10, . rightChild = &Node100};
  NodeInt *root;

  root = (NodeInt *) rightRotate((Node *) &Node50);

  TEST_ASSERT_EQUAL_PTR(&Node10, root);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node30, root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild->rightChild);

  TEST_ASSERT_EQUAL(0, Node10.balance);
  TEST_ASSERT_EQUAL(0, Node50.balance);
  TEST_ASSERT_EQUAL(-1, Node5.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node30.balance);
  TEST_ASSERT_EQUAL(0, Node100.balance);

 }
 /**            -2
  *         (50)               0  (30)
  *         /  \                  /  \
  *     1(10) (100)         -1 (10)  (50)
  *       / \           =>     /     /  \
  *     (5) (30) 1        0 (5)   (40) (100)
  *           \
  *           (40)
  */
void test_doubleRightRotate_given_6_element_should_rotate_to_balance_the_tree_case1(){
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node5 = {.data = 5, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node30  = {.data = 30,  .balance = 1, .leftChild = NULL, . rightChild = &Node40};

  NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node10  = {.data = 10,  .balance = 1, .leftChild = &Node5, . rightChild = &Node30};

  NodeInt Node50  = {.data = 50,  .balance = -2, .leftChild = &Node10, . rightChild = &Node100};
  NodeInt *root;

  root = (NodeInt *) doubleRightRotate((Node *) &Node50);

  TEST_ASSERT_EQUAL_PTR(&Node30, root);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node10, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node40, root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild->rightChild);

  TEST_ASSERT_EQUAL(0, Node30.balance);
  TEST_ASSERT_EQUAL(0, Node50.balance);
  TEST_ASSERT_EQUAL(-1, Node10.balance);
  TEST_ASSERT_EQUAL(0, Node5.balance);
  TEST_ASSERT_EQUAL(0, Node40.balance);
  TEST_ASSERT_EQUAL(0, Node100.balance);

 }

 /**
  *         (50)                 (30)
  *         /  \                /   \
  *     (100) (10)            (50)  (10)
  *           /  \     =>     /  \    \
  *        (30)  (5)      (100) (40)  (5)
  *         /
  *      (40)
  */
void test_doubleLeftRotate_given_6_element_should_rotate_to_balance_the_tree_case1(){
  NodeInt Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node5 = {.data = 5, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node30  = {.data = 30,  .balance = -1, .leftChild = &Node40, . rightChild = NULL};

  NodeInt Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node10  = {.data = 10,  .balance = -1, .leftChild = &Node30, . rightChild = &Node5};

  NodeInt Node50  = {.data = 50,  .balance = 2, .leftChild = &Node100, . rightChild = &Node10};
  NodeInt *root;

  root = (NodeInt *) doubleLeftRotate((Node *) &Node50);

  TEST_ASSERT_EQUAL_PTR(&Node30, root);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node10, root->rightChild);

  TEST_ASSERT_EQUAL_PTR(&Node5, root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node40, root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->leftChild->leftChild);

  TEST_ASSERT_EQUAL(0, Node30.balance);
  TEST_ASSERT_EQUAL(0, Node50.balance);
  TEST_ASSERT_EQUAL(1, Node10.balance);
  TEST_ASSERT_EQUAL(0, Node5.balance);
  TEST_ASSERT_EQUAL(0, Node40.balance);
  TEST_ASSERT_EQUAL(0, Node100.balance);
}
/**
  *        (50)                  (100) 0
  *        /  \                  /   \
  *     (10)  (100)            (50)  (150) 1
  *           /  \      =>    /   \     \
  *        (70)  (150)      (10) (70)   (200) 0
  *                \
  *               (200)
  */
void test_Yrank_result(){
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};
  NodeInt Node70  = {.data = 70,  .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node100 = {.data = 100, .balance = 1, .leftChild = &Node70, . rightChild = &Node150};
  NodeInt Node10  = {.data = 10,  .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50  = {.data = 50,  .balance = 2, .leftChild = &Node10, . rightChild = &Node100};
  NodeInt *root;

  root = (NodeInt *) leftRotate((Node *) &Node50);

}

/** TEST CASE B....CASE A tested above
  *
  *		(50) +2						(100) 0
  *     /  \						/   \
  *  (1)   (100) +1			=> 	 (50)   (150) +1
  *        /   \				 /	\      \
  *     (75)   (150) +1        (1)  (75)   (200) 0
  *               \
  *               (200) 0
  */
void test_leftRotate_for_the_caseB(){
  NodeInt Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = NULL, . rightChild = &Node200};
  NodeInt Node75  = {.data = 75,  .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node100 = {.data = 100, .balance = 1, .leftChild = &Node75, . rightChild = &Node150};
  NodeInt Node1  = {.data = 10,  .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node50  = {.data = 50,  .balance = 2, .leftChild = &Node1, . rightChild = &Node100};

  NodeInt *root;

  int height = getHeight((Node *)  &Node50);
  TEST_ASSERT_EQUAL(4, height);

  root = (NodeInt *) leftRotate((Node *) &Node50);

  TEST_ASSERT_EQUAL_PTR(&Node100, root);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node150, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node75, root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node200, root->rightChild->rightChild);

  TEST_ASSERT_EQUAL(0, Node50.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node100.balance);
  TEST_ASSERT_EQUAL(0, Node75.balance);
  TEST_ASSERT_EQUAL(1, Node150.balance);
  TEST_ASSERT_EQUAL(0, Node200.balance);

  // height after rotate
  int height2 = getHeight((Node *)  &Node100);
  TEST_ASSERT_EQUAL(3, height2);

}
/**
  *		   (100) +1                      (150)-1
  *      /      \                       /     \
  *   (50)      (150) +1           -1 (100)   (200)-1
  *	  /	 \     /   \ 	    =>       /  \      /
  * (1) (75) (120) (200) -1        (50) (120)(180)
  *                /              /  \
  *              (180)          (1)  (75)
  */
void test_leftRotate_for_the_caseC(){
  NodeInt Node180 = {.data = 180, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node1  = {.data = 1,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node75  = {.data = 75,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node120 = {.data = 120,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node200 = {.data = 200,  .balance = -1, .leftChild = &Node180, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = +1, .leftChild = &Node120, . rightChild = &Node200};
  NodeInt Node50  = {.data = 50,  .balance = 0, .leftChild = &Node1, . rightChild = &Node75};

  NodeInt Node100 = {.data = 100, .balance = 1, .leftChild = &Node50, . rightChild = &Node150};

  int height = getHeight((Node *)  &Node100);
  TEST_ASSERT_EQUAL(4, height);

  NodeInt *root;
  root = (NodeInt *) leftRotate((Node *) &Node100);

  int height2 = getHeight((Node *)  &Node150);
  TEST_ASSERT_EQUAL(4, height2);

  TEST_ASSERT_EQUAL_PTR(&Node150, root);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node200, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node120, root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node75, root->leftChild->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node180, root->rightChild->leftChild);

  TEST_ASSERT_EQUAL(-1, Node150.balance);
  TEST_ASSERT_EQUAL(-1, Node100.balance);
  TEST_ASSERT_EQUAL(-1, Node200.balance);

  TEST_ASSERT_EQUAL(0, Node50.balance);
  TEST_ASSERT_EQUAL(0, Node120.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node75.balance);
  TEST_ASSERT_EQUAL(0, Node180.balance);


}
/**
  *		   (100) +1                      (150)-2
  *      /      \                       /     \
  *   (50)      (150) -1            0 (100)   (200) 0
  *	  /	 \   +1 /   \ 	    =>       /  \
  * (1) (75) (120) (200) +1        (50) (120) +1
  *             \            	  /  \     \
  *             (130)          (1)  (75)   (130)
  */
void test_leftRotate_for_the_caseD(){
  NodeInt Node130 = {.data = 130, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node1  = {.data = 1,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node75  = {.data = 75,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node120 = {.data = 120,  .balance = 1, .leftChild = NULL, . rightChild = &Node130};
  NodeInt Node200 = {.data = 200,  .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = -1, .leftChild = &Node120, . rightChild = &Node200};
  NodeInt Node50  = {.data = 50,  .balance = 0, .leftChild = &Node1, . rightChild = &Node75};

  NodeInt Node100 = {.data = 100, .balance = 1, .leftChild = &Node50, . rightChild = &Node150};

  int height = getHeight((Node *)  &Node100);
  TEST_ASSERT_EQUAL(4, height);

  NodeInt *root;
  root = (NodeInt *) leftRotate((Node *) &Node100);

  int height2 = getHeight((Node *)  &Node150);
  TEST_ASSERT_EQUAL(4, height2);

  TEST_ASSERT_EQUAL_PTR(&Node150, root);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node200, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node120, root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node75, root->leftChild->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node130, root->leftChild->rightChild->rightChild);

  TEST_ASSERT_EQUAL(1, Node120.balance);
  TEST_ASSERT_EQUAL(-2, Node150.balance);
  TEST_ASSERT_EQUAL(0, Node100.balance);

  TEST_ASSERT_EQUAL(0, Node50.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node75.balance);
  TEST_ASSERT_EQUAL(0, Node130.balance);
  TEST_ASSERT_EQUAL(0, Node200.balance);
}
/** X care value ...mirror image of leftrotate
  *		        (100) -1                (150) +1
  *            /     \                  /    \
  *   -1   (150)     (50) 0       1 (200)    (100) +1
  *	       /   \     /  \ 	    =>    \      /   \
  * +1 (200) (120) (75) (1) 0        (180) (120) (50)
  *      \                                       /   \
  *     (180)						          (75)   (1)
  */
void test_rightRotate_for_caseC(){
  NodeInt Node180 = {.data = 180, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node1  = {.data = 1,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node75  = {.data = 75,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node120 = {.data = 120,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node200 = {.data = 200,  .balance = 1, .leftChild = NULL, . rightChild = &Node180};

  NodeInt Node150 = {.data = 150, .balance = -1, .leftChild = &Node200, . rightChild = &Node120};
  NodeInt Node50  = {.data = 50,  .balance = 0, .leftChild = &Node75, . rightChild = &Node1};

  NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node150, . rightChild = &Node50};

  int height = getHeight((Node *)  &Node100);
  TEST_ASSERT_EQUAL(4, height);

  NodeInt *root;
  root = (NodeInt *) rightRotate((Node *) &Node100);

  int height2 = getHeight((Node *)  &Node150);
  TEST_ASSERT_EQUAL(4, height2);

  TEST_ASSERT_EQUAL_PTR(&Node150, root);
  TEST_ASSERT_EQUAL_PTR(&Node200, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node120, root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->rightChild->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node75, root->rightChild->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node180, root->leftChild->rightChild);

  TEST_ASSERT_EQUAL(1, Node100.balance);
  TEST_ASSERT_EQUAL(1, Node150.balance);
  TEST_ASSERT_EQUAL(1, Node200.balance);

  TEST_ASSERT_EQUAL(0, Node50.balance);
  TEST_ASSERT_EQUAL(0, Node120.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node75.balance);
  TEST_ASSERT_EQUAL(0, Node180.balance);
}

/** X care value ...mirror image of leftrotate
  *		     (100) -1              (150)+2
  *        /      \                /   \
  *  1 (150)      (50) 0       (200)   (100)0
  *	   /   \-1    /   \ 	=>         /   \
  * (200) (120) (75)  (1) 0      -1 (120)  (50)
  *      /                   	    /      /  \
  *   (130)                       (130)   (75) (1)
  */
void test_rightRotate_for_caseD(){
  NodeInt Node130 = {.data = 130, .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node1  = {.data = 1,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node75  = {.data = 75,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  NodeInt Node120 = {.data = 120,  .balance = -1, .leftChild = &Node130, . rightChild = NULL };
  NodeInt Node200 = {.data = 200,  .balance = 0, .leftChild = NULL, . rightChild = NULL};

  NodeInt Node150 = {.data = 150, .balance = 1, .leftChild = &Node200, . rightChild = &Node120};
  NodeInt Node50  = {.data = 50,  .balance = 0, .leftChild = &Node75, . rightChild = &Node1};

  NodeInt Node100 = {.data = 100, .balance = -1, .leftChild = &Node150, . rightChild = &Node50};

  NodeInt *root;
  root = (NodeInt *) rightRotate((Node *) &Node100);

  TEST_ASSERT_EQUAL_PTR(&Node150, root);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node200, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node120, root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->rightChild->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node75, root->rightChild->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node130, root->rightChild->leftChild->leftChild);

  TEST_ASSERT_EQUAL(-1, Node120.balance);
  TEST_ASSERT_EQUAL(1, Node150.balance);
  TEST_ASSERT_EQUAL(-1, Node100.balance);

  TEST_ASSERT_EQUAL(0, Node50.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node75.balance);
  TEST_ASSERT_EQUAL(0, Node130.balance);
  TEST_ASSERT_EQUAL(0, Node200.balance);
}