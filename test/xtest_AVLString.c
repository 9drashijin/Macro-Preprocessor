#include "unity.h"
#include "AVLString.h"
#include "AVL.h"
#include "Rotation.h"
#include "CustomAssert.h"

void setUp(void){}
void tearDown(void){}

/**
  *   "Alice"  
  *       \   
  *     "Emilia" 
  *      
  */
void test_avlAddInt_for_2_element(){
	NodeString Alice = {.string = "Alice", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeString Emilia = {.string = "Emilia", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeString *root = NULL;
  
    root = (NodeString *) avlAddString(root,&Alice);
	root = (NodeString *) avlAddString(root,&Emilia);
	
	TEST_ASSERT_EQUAL_PTR(&Alice, root);
	TEST_ASSERT_EQUAL_PTR(&Emilia, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Emilia.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Emilia.rightChild);
	
	TEST_ASSERT_EQUAL(1, Alice.balance);
	TEST_ASSERT_EQUAL(0, Emilia.balance);
	
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&Emilia,1,&Alice);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Emilia);

}

/**
  *   "Sefia"              "Kikuri" 
  *       \                 /    \
  *     "Kikuri"    => "Aisha"  "Sefia"
  *        \
  *      "Aisha"
  */
void test_avlAddString_for_3_element(){
	NodeString Sefia = {.string = "Sefia", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeString Kikuri = {.string = "Kikuri", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeString Aisha = {.string = "Aisha", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	
	NodeString *root = NULL;
  
    root = (NodeString *) avlAddString(root,&Sefia);
	root = (NodeString *) avlAddString(root,&Kikuri);
	root = (NodeString *) avlAddString(root,&Aisha);
	
	// printf("Sefia %p\n",&Sefia);
	// printf("Kikuri %p\n",&Kikuri);
	// printf("Aisha %p\n",&Aisha);
	
	TEST_ASSERT_EQUAL_PTR(&Kikuri, root);
	TEST_ASSERT_EQUAL_PTR(&Aisha, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Sefia, root->rightChild);
	
	TEST_ASSERT_NOT_NULL(Kikuri.leftChild);
	TEST_ASSERT_NOT_NULL(Kikuri.rightChild);
	
	TEST_ASSERT_EQUAL_PTR(NULL, Aisha.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Aisha.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Sefia.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Sefia.rightChild);
	
	TEST_ASSERT_EQUAL(0, Sefia.balance);
	TEST_ASSERT_EQUAL(0, Kikuri.balance);
	TEST_ASSERT_EQUAL(0, Aisha.balance);
	
	TEST_ASSERT_EQUAL_AVL_Node(&Aisha,&Sefia,0,&Kikuri);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Aisha);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Sefia);
}
/**       "Lugina"
  *        /    \
  *  "Karl"   "Tilith"
  *             /
  *        "Seria"
  *  
  */
void test_avlAddInt_for_4th_element(){
	NodeString Tilith = {.string = "Tilith", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeString Lugina = {.string = "Lugina", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeString Karl = {.string = "Karl", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeString Seria = {.string = "Seria", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	
	NodeString *root = NULL;
  
    root = (NodeString *) avlAddString(root,&Tilith);
	root = (NodeString *) avlAddString(root,&Lugina);
	root = (NodeString *) avlAddString(root,&Karl);
	root = (NodeString *) avlAddString(root,&Seria);
	
	// printf("Tilith %p\n",&Tilith);
	// printf("Lugina %p\n",&Lugina);
	// printf("Karl %p\n",&Karl);
	// printf("Seria %p\n",&Seria);
	
	TEST_ASSERT_EQUAL_PTR(&Lugina, root);
	TEST_ASSERT_EQUAL_PTR(&Karl, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Tilith, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Seria, root->rightChild->leftChild);
	
	TEST_ASSERT_EQUAL_PTR(NULL, Karl.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Karl.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Seria.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Seria.rightChild);
	
	TEST_ASSERT_EQUAL(-1, Tilith.balance);
	TEST_ASSERT_EQUAL(1, Lugina.balance);
	TEST_ASSERT_EQUAL(0, Karl.balance);
	TEST_ASSERT_EQUAL(0, Seria.balance);
	
	TEST_ASSERT_EQUAL_AVL_Node(&Karl,&Tilith,1,&Lugina);
	TEST_ASSERT_EQUAL_AVL_Node(&Seria,NULL,-1,&Tilith);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Karl);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Seria);
}