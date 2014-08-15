#include "unity.h"
#include "AVLString.h"
#include "AVL.h"
#include "Rotation.h"
#include "CustomAssert.h"
#include "malloc.h"

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

///////////////////////////////////////////
//             AVL Find                  //
///////////////////////////////////////////
/**
  *   "Alice"  1
  *       \
  *     "Emilia"
  *
  */
void test_avlFindString2_for_the_AVLString_with_the_NodeString_AvL(){
  NodeString Alice = {.string = "Alice", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeString Emilia = {.string = "Emilia", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	NodeString *root = NULL;
	NodeString *rootFind = NULL;

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

  rootFind = (NodeString *)avlFindString2(root, &Emilia);

  TEST_ASSERT_EQUAL(&Emilia,rootFind);

}
// currently using avlFind2
/**
  *   "Alice"  1
  *       \
  *     "Emilia"
  *
  */
void test_avlFind2_for_the_definition_by_testing_with_the_DefinitionTable_avl(){
  DefinitionTable Alice = {.data = "Alice", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	DefinitionTable Emilia = {.data = "Emilia", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	DefinitionTable *root = NULL;
	DefinitionTable *rootFind = NULL;

  root = (DefinitionTable *) avlAddString(root,&Alice);
	root = (DefinitionTable *) avlAddString(root,&Emilia);

  TEST_ASSERT_EQUAL_PTR(&Alice, root);
	TEST_ASSERT_EQUAL_PTR(&Emilia, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Emilia.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Emilia.rightChild);

	TEST_ASSERT_EQUAL(1, Alice.balance);
	TEST_ASSERT_EQUAL(0, Emilia.balance);

	TEST_ASSERT_EQUAL_AVL_Node(NULL,&Emilia,1,&Alice);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Emilia);

  rootFind = (DefinitionTable *)avlFindDef2(root, &Emilia);

  TEST_ASSERT_EQUAL(&Emilia,rootFind);
}

/////////////////////////////////////////
// AVL add and find for DefinitionTable//
/////////////////////////////////////////

/**
  *         "MIN" (1)
  *        /    \
  * (0) "MAX"  "SUPER" (1)
  *               \
  *              "ULTRA" (0)
  */
void test_avlFind_for_the_definition_with_more_node_in_the_DefinitionTable_avlTree(){
  DefinitionTable MIN = {.data = "#define MIN 5-7", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	DefinitionTable MAX = {.data = "#define MAX 2+3x4(MIN", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	DefinitionTable SUPER = {.data = "#define SUPER 2(MAX)", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	DefinitionTable ULTRA = {.data = "#define ULTRA SUPER/3", .balance = 0, .leftChild = NULL, . rightChild = NULL};
	DefinitionTable *root = NULL;
	DefinitionTable *rootFind = NULL;

  root = (DefinitionTable *) avlAddString(root,&MIN);
	root = (DefinitionTable *) avlAddString(root,&MAX);
	root = (DefinitionTable *) avlAddString(root,&SUPER);
	root = (DefinitionTable *) avlAddString(root,&ULTRA);

  // printf("MIN %p\n",&MIN);
	// printf("MAX %p\n",&MAX);
	// printf("SUPER %p\n",&SUPER);
	// printf("ULTRA %p\n",&ULTRA);

  TEST_ASSERT_EQUAL_PTR(&MIN, root);
	TEST_ASSERT_EQUAL_PTR(&MAX, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&SUPER, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&ULTRA, SUPER.rightChild);

	TEST_ASSERT_EQUAL(1, MIN.balance);
	TEST_ASSERT_EQUAL(0, MAX.balance);
	TEST_ASSERT_EQUAL(1, SUPER.balance);
	TEST_ASSERT_EQUAL(0, ULTRA.balance);

	TEST_ASSERT_EQUAL_AVL_Node(&MAX,&SUPER,1,&MIN);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&ULTRA,1,&SUPER);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&MAX);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&ULTRA);

  rootFind = (DefinitionTable *)avlFindDef2(root, &ULTRA);
  TEST_ASSERT_EQUAL(&ULTRA,rootFind);

  rootFind = (DefinitionTable *)avlFindDef2(root, &SUPER);
  TEST_ASSERT_EQUAL(&SUPER,rootFind);

  rootFind = (DefinitionTable *)avlFindDef2(root, &MAX);
  TEST_ASSERT_EQUAL(&MAX,rootFind);

  rootFind = (DefinitionTable *)avlFindDef2(root, &MIN);
  TEST_ASSERT_EQUAL(&MIN,rootFind);
}








