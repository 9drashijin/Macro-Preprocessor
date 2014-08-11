#include "unity.h"
#include "Definition.h"
#include "Text.h"
#include "StringObject.h"
#include "ErrorCode.h"
#include "CException.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "CharSet.h"
#include "AVL.h"
#include "Rotation.h"
#include "AVLString.h"
#include "CustomAssert.h"

void setUp(void){}
void tearDown(void){}

void printName(String *str){
  Definition *define;
  // define = str;
  
  printf("======name====== \n");
  printf("text %s \n",define->name->text);
  printf("start %d \n",define->name->start);
  printf("length %d \n\n",define->name->length);
}
void printContent(String *str){
  Definition *define;
  // define = str;
  
  printf("=====content===== \n");
  printf("text %s \n",define->content->text);
  printf("start %d \n",define->content->start);
  printf("length %d \n",define->content->length);
}

void test_addDefinition_should_add_the_string_to_the_name_and_the_content(void){
  Definition *define;
  Text *textName = textNew("ABC");
  Text *textContent = textNew("2+B*D-6");
  String *defineName = stringNew(textName);
  String *defineContent = stringNew(textContent);
 
  define = addDefinition(defineName,defineContent);
  
  // printName(define->name);
  // printContent(define->content);
  
	TEST_ASSERT_EQUAL_STRING("ABC",define->name->text->string);
	TEST_ASSERT_EQUAL(0,define->name->start);
	TEST_ASSERT_EQUAL(3,define->name->length);
  
  TEST_ASSERT_EQUAL_STRING("2+B*D-6",define->content->text->string);
	TEST_ASSERT_EQUAL(0,define->content->start);
	TEST_ASSERT_EQUAL(7,define->content->length);
}

void test_addDefinition_should_add_another_string_to_the_name_and_the_content(void){
  Definition *define;
  Text *textName = textNew("MIN");
  Text *textContent = textNew("C&&D|5");
  String *defineName = stringNew(textName);
  String *defineContent = stringNew(textContent);
 
  define = addDefinition(defineName,defineContent);
  
  // printName(define->name);
  // printContent(define->content);
  
	TEST_ASSERT_EQUAL_STRING("MIN",define->name->text->string);
	TEST_ASSERT_EQUAL(0,define->name->start);
	TEST_ASSERT_EQUAL(3,define->name->length);
  
  TEST_ASSERT_EQUAL_STRING("C&&D|5",define->content->text->string);
	TEST_ASSERT_EQUAL(0,define->content->start);
	TEST_ASSERT_EQUAL(6,define->content->length);
}

void test_isPreprocessor_should_not_throw_error(){
	CEXCEPTION_T e;
  Text *define = textNew("#define");
  int result;
	Try{
    result = isPreprocessors(define);
		TEST_ASSERT_EQUAL(1,result);
	}
	Catch(e){
		TEST_ASSERT_EQUAL(ERROR_NOT_DEFINE,e);
    TEST_FAIL_MESSAGE("ERROR_NOT_DEFINE");
	}
}

void test_isPreprocessor_should_throw_error(){
	CEXCEPTION_T e;
  Text *define = textNew("#zdefine");
  int result;
	Try{
    result = isPreprocessors(define);
		TEST_ASSERT_EQUAL(1,result);
		TEST_FAIL_MESSAGE("ERROR_NOT_DEFINE");
	}
	Catch(e){
		TEST_ASSERT_EQUAL(ERROR_NOT_DEFINE,e);
	}
}

void test_textClone_should_clone_the_text_to_a_new_place(){
  Text *define = textNew("#define");
  Text *clone;
  
  clone = textClone(define);
  
  TEST_ASSERT_EQUAL_STRING("#define",define->string);
  TEST_ASSERT_EQUAL_STRING("#define",clone->string);
  TEST_ASSERT_EQUAL(1,define->reference);
  TEST_ASSERT_EQUAL(1,clone->reference);
}

void test_textSubstitute_should_replace_the_text_with_the_MIN(){
  Text *text = textNew("2+3*MIN");
  Text *MIN = textNew("(2)");
  Text *txt;
  
  txt = textSubstitute(text,4,3,MIN);
  
  TEST_ASSERT_EQUAL_STRING("2+3*(2)",txt->string);
}

void test_textSubstitute_should_replace_the_text_with_the_MIN_for_2nd_test(){
  Text *text = textNew("10+B");
  Text *MIN = textNew("(5*6)");
  Text *txt;
  
  txt = textSubstitute(text,3,1,MIN);
  
  TEST_ASSERT_EQUAL_STRING("10+(5*6)",txt->string);
}

void test_textSubstitute_should_replace_the_text_with_the_MIN_for_3nd_test(){
  Text *text = textNew("Hello A");
  Text *A = textNew("World");
  Text *txt;
  
  txt = textSubstitute(text,6,1,A);
  
  TEST_ASSERT_EQUAL_STRING("Hello World",txt->string);
}
void test_strCpy(){
  char text[100];
  char A[] = "World";
  
  strCpy(text,A,0,5);
  
  TEST_ASSERT_EQUAL_STRING("World",text);
}
void test_textSubstitute_should_replace_the_middle_text_with_the_subText(){
  Text *text = textNew("1+2*MAX-6/8");
  Text *subText = textNew("(3-4)");
  Text *returnedText;
  
  returnedText = textSubstitute(text,4,3,subText);
  
  // printf("returnedText : %s \n", returnedText->string);
  
  TEST_ASSERT_EQUAL_STRING("1+2*(3-4)-6/8",returnedText->string);
}
void test_textSubstitute_should_replace_the_front_text_with_the_subText(){
  Text *text = textNew("zxcA World");
  Text *subText = textNew("Hello");
  Text *returnedText;
  
  returnedText = textSubstitute(text,3,1,subText);
  // printf("returnedText : %s \n", returnedText->string);
  TEST_ASSERT_EQUAL_STRING("zxcHello World",returnedText->string);
}
void test_textSubstitute_should_replace_the_behind_text_with_the_subText(){
  Text *text = textNew("123+SUPER");
  Text *subText = textNew("(10*11)");
  Text *returnedText;
  
  returnedText = textSubstitute(text,4,5,subText);
  
  TEST_ASSERT_EQUAL_STRING("123+(10*11)",returnedText->string);
}
void test_textSubstitute_should_replace_the_text_with_the_Static_subText(){
  Text *text = t"1+2*MAX-6/8";
  Text *subText = t"(3-4)";
  Text *returnedText;
  
  returnedText = textSubstitute(text,4,3,subText);
  
  // printf("returnedText : %s \n", returnedText->string);
  
  TEST_ASSERT_EQUAL_STRING("1+2*(3-4)-6/8",returnedText->string);
}

void test_textSubstitute_should_replace_the_text_with_the_2_subText(){
  Text *text = t"1+2*MAX-6/8";
  Text *subText = t"(42-MIN)";
  Text *subText2 = t"12";
  Text *returnedText;
  
  returnedText = textSubstitute(subText,4,3,subText2);
  returnedText = textSubstitute(text,4,3,returnedText);
  
  // printf("returnedText : %s \n", returnedText->string);
  
  TEST_ASSERT_EQUAL_STRING("1+2*(42-12)-6/8",returnedText->string);
  // free(returnedText);
}
void test_textSubstitute_should_replace_the_text_with_multiple_subText(){
  Text *text = t"1+2*MAX-6/8";
  Text *subText = t"(42-MIN)";
  Text *subText2 = t"(1+HIGH)";
  Text *subText3 = t"13";
  Text *returnedText;
  
  // returnedText = textSubstitute(subText2,3,4,subText3);
  // returnedText = textSubstitute(subText,4,3,returnedText);
  // returnedText = textSubstitute(text,4,3,returnedText);
  
  // printf("returnedText : %s \n", returnedText->string);
  
  // TEST_ASSERT_EQUAL_STRING("1+2*(42-(1+13))-6/8",returnedText->string);
  // free(returnedText);
}


/////////////////////
// Definition Find //
/////////////////////

/**
  *        MIN 
  *       /   \
  *   MAX     SUPER
  */
void test_definitionFind_should_find_the_definition_in_the_Definition_table(){
  DefinitionTable MAX = {.data = "MAX", .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable SUPER = {.data = "SUPER", .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable MIN = {.data = "MIN", .balance = 0, .leftChild = &MAX, .rightChild = &SUPER};
  DefinitionTable *root = &MIN;
  DefinitionTable *rootFind = NULL;
  
  rootFind = (DefinitionTable *)definitionFind(root, &MIN);
  TEST_ASSERT_EQUAL(&MIN,rootFind);
}
/**
  *        MIN 
  *       /   \
  *   MAX     SUPER
  *             \
  *             ULTRA
  */
void test_definitionFind_should_find_the_definition_in_the_Definition_table_case2(){
  DefinitionTable ULTRA = {.data = "ULTRA", .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable MAX = {.data = "MAX", .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable SUPER = {.data = "SUPER", .balance = 0, .leftChild = NULL, .rightChild = &ULTRA};
  DefinitionTable MIN = {.data = "MIN", .balance = 0, .leftChild = &MAX, .rightChild = &SUPER};
  DefinitionTable *root = &MIN;
  DefinitionTable *rootFind = NULL;
  
  rootFind = (DefinitionTable *)definitionFind(root, &MAX);
  TEST_ASSERT_EQUAL(&MAX,rootFind);
  
  rootFind = (DefinitionTable *)definitionFind(root, &SUPER);
  TEST_ASSERT_EQUAL(&SUPER,rootFind);
  
  rootFind = (DefinitionTable *)definitionFind(root, &ULTRA);
  TEST_ASSERT_EQUAL(&ULTRA,rootFind);
}
////////////////////
// Definition Add //
////////////////////
/**
  *    name content
  *     MIN 2+8*6
  *     /      \
  *   NULL     NULL
  */
void test_definitonAdd_by_adding_the_Definiton_to_the_definition_table(){
  Definition *define;
  Text *textName = textNew("MIN");
  Text *textContent = textNew("2+8*6");
  String *defineName = stringNew(textName);
  String *defineContent = stringNew(textContent);
  
  define = addDefinition(defineName,defineContent);
  
  DefinitionTable MIN = {.data = define, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	DefinitionTable *root = NULL;
  DefinitionTable *rootFind = NULL;
  
  root = (DefinitionTable *) definitionAdd(root,&MIN);
	
  // printf("data: %s\n",defineName->text->string);
  // printf("data: %s\n",define->name->text->string);
  // printf("data: %s\n",((Definition *)(MIN.data))->name->text->string);
  // printf("content: %s\n",((Definition *)(MIN.data))->content->text->string);
  
	TEST_ASSERT_EQUAL_PTR(&MIN, root);
	TEST_ASSERT_EQUAL_PTR(NULL, MIN.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, MIN.rightChild);
  
  TEST_ASSERT_EQUAL(0, MIN.balance);
  
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&MIN);
}
/**
  *    name content
  *     MIN 2+8*6 (1)
  *     /      \
  *   NULL     MAX 5-7
  */
void test_definitonAdd_by_adding_the_Definiton_to_the_definition_table_for_2_definition(){
  Definition *define, *define2;
  Text *textName = textNew("MIN");
  Text *textContent = textNew("2+8*6");
  String *defineName = stringNew(textName);
  String *defineContent = stringNew(textContent);
  
  Text *textName2 = textNew("MAX");
  Text *textContent2 = textNew("5-7");
  String *defineName2 = stringNew(textName2);
  String *defineContent2 = stringNew(textContent2);
  
  define = addDefinition(defineName,defineContent);
  define2 = addDefinition(defineName2,defineContent2);
  
  DefinitionTable MIN = {.data = define, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable MAX = {.data = define2, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  
	DefinitionTable *root = NULL;
  DefinitionTable *rootFind = NULL;
  
  root = (DefinitionTable *) definitionAdd(root,&MIN);
  root = (DefinitionTable *) definitionAdd(root,&MAX);
	
	TEST_ASSERT_EQUAL_PTR(&MIN, root);
	TEST_ASSERT_EQUAL_PTR(NULL, MIN.leftChild);
	TEST_ASSERT_EQUAL_PTR(&MAX, MIN.rightChild);
  
  TEST_ASSERT_EQUAL(1, MIN.balance);
  
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&MAX,1,&MIN);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&MAX);
}
/**
  *       name content
  *         MIN 2+8*6
  *         /      \
  *    MAX 5-7    SUPER 88*2
  */
void test_definitonAdd_by_adding_the_Definiton_to_the_definition_table_for_3_definition_and_should_rightRotate_the_table(){
  Definition *define, *define2, *define3;
  Text *textName = textNew("MIN");
  Text *textContent = textNew("2+8*6");
  String *defineName = stringNew(textName);
  String *defineContent = stringNew(textContent);
  
  Text *textName2 = textNew("MAX");
  Text *textContent2 = textNew("5-7");
  String *defineName2 = stringNew(textName2);
  String *defineContent2 = stringNew(textContent2);
  
  Text *textName3 = textNew("SUPER");
  Text *textContent3 = textNew("88*2");
  String *defineName3 = stringNew(textName3);
  String *defineContent3 = stringNew(textContent3);
  
  define = addDefinition(defineName,defineContent);
  define2 = addDefinition(defineName2,defineContent2);
  define3 = addDefinition(defineName3,defineContent3);
  
  DefinitionTable MIN = {.data = define->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable MAX = {.data = define2->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable SUPER = {.data = define3->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  
	DefinitionTable *root = NULL;
  DefinitionTable *rootFind = NULL;
  
  root = (DefinitionTable *) definitionAdd(root,&MIN);
  root = (DefinitionTable *) definitionAdd(root,&MAX);
  root = (DefinitionTable *) definitionAdd(root,&SUPER);
	
  // printf("MIN %p\n",&MIN);
	// printf("MAX %p\n",&MAX);
	// printf("SUPER %p\n",&SUPER);
  
  TEST_ASSERT_EQUAL_PTR(&MIN, root);
	TEST_ASSERT_EQUAL_PTR(&MAX, MIN.leftChild);
	TEST_ASSERT_EQUAL_PTR(&SUPER, MIN.rightChild);
  
  TEST_ASSERT_EQUAL(0, MAX.balance);
  TEST_ASSERT_EQUAL(0, MIN.balance);
  TEST_ASSERT_EQUAL(0, SUPER.balance);
  
  TEST_ASSERT_EQUAL_AVL_Node(&MAX,&SUPER,0,&MIN);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&MAX);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&SUPER);
}
/**
  *        name content
  *         MIN 2+8*6-4
  *           /     \
  * MAX 5-7/45*3    SUPER 88*2+65
  *                    \
  *                   ULTRA 531/45
  */
void test_definitonAdd_by_adding_the_Definiton_to_the_definition_table_for_4_definition_and_should_add_ULTRA_under_right_of_SUPER(){
  Definition *define, *define2, *define3, *define4;
  Text *textName = textNew("MIN");
  Text *textContent = textNew("2+8*6-4");
  String *defineName = stringNew(textName);
  String *defineContent = stringNew(textContent);
  
  Text *textName2 = textNew("MAX");
  Text *textContent2 = textNew("5-7/45*3");
  String *defineName2 = stringNew(textName2);
  String *defineContent2 = stringNew(textContent2);
  
  Text *textName3 = textNew("SUPER");
  Text *textContent3 = textNew("88*2+65");
  String *defineName3 = stringNew(textName3);
  String *defineContent3 = stringNew(textContent3);
  
  Text *textName4 = textNew("ULTRA");
  Text *textContent4 = textNew("531/45");
  String *defineName4 = stringNew(textName4);
  String *defineContent4 = stringNew(textContent4);
  
  define = addDefinition(defineName,defineContent);
  define2 = addDefinition(defineName2,defineContent2);
  define3 = addDefinition(defineName3,defineContent3);
  define4 = addDefinition(defineName4,defineContent4);
  
  DefinitionTable MIN = {.data = define->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable MAX = {.data = define2->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable SUPER = {.data = define3->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable ULTRA = {.data = define4->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  
	DefinitionTable *root = NULL;
  DefinitionTable *rootFind = NULL;
  
  root = (DefinitionTable *) definitionAdd(root,&MIN);
  root = (DefinitionTable *) definitionAdd(root,&MAX);
  root = (DefinitionTable *) definitionAdd(root,&SUPER);
  root = (DefinitionTable *) definitionAdd(root,&ULTRA);
	
  // printf("MIN %p\n",&MIN);
	// printf("MAX %p\n",&MAX);
	// printf("SUPER %p\n",&SUPER);
	// printf("ULTRA %p\n",&ULTRA);
	
  // printf("%d\n", strcmp("MIN","MAX"));
  // printf("%d\n", strcmp("MAX","MIN"));
  // printf("%d\n", strcmp("SUPER","MIN"));
  // printf("%d\n", strcmp("MIN","SUPER"));
  
  // printf("%d\n", strcmp("SUPER","MAX"));
  // printf("%d\n", strcmp("MAX","SUPER"));
  // printf("%d\n", strcmp("ULTRA","SUPER"));
  // printf("%d\n", strcmp("SUPER","ULTRA"));
   
  TEST_ASSERT_EQUAL_PTR(&MIN, root);
	TEST_ASSERT_EQUAL_PTR(&MAX, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&SUPER, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&ULTRA, SUPER.rightChild);
  
  TEST_ASSERT_EQUAL_AVL_Node(&MAX,&SUPER,1,&MIN);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,&ULTRA,1,&SUPER);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&MAX);
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&ULTRA);
  
  rootFind = (DefinitionTable *)definitionFind(root, &MIN);
  TEST_ASSERT_EQUAL(&MIN,rootFind);
}
/**
  *         "MIN"
  *        /    \
  *    "MAX"  "ULTIMATE"
  *     /       /    \
  * "HYPER" "SUPER"  "ULTRA"
  */
void test_definitonAdd_by_adding_the_Definiton_to_the_definition_table_for_6_definition(){
  Definition *define, *define2, *define3, *define4, *define5, *define6;
  Text *textName = textNew("MIN");
  Text *textContent = textNew("2+8*6-4");
  String *defineName = stringNew(textName);
  String *defineContent = stringNew(textContent);
  
  Text *textName2 = textNew("MAX");
  Text *textContent2 = textNew("5-7/45*3");
  String *defineName2 = stringNew(textName2);
  String *defineContent2 = stringNew(textContent2);
  
  Text *textName3 = textNew("SUPER");
  Text *textContent3 = textNew("88*2+65");
  String *defineName3 = stringNew(textName3);
  String *defineContent3 = stringNew(textContent3);
  
  Text *textName4 = textNew("ULTRA");
  Text *textContent4 = textNew("531/45");
  String *defineName4 = stringNew(textName4);
  String *defineContent4 = stringNew(textContent4);
  
  Text *textName5 = textNew("HYPER");
  Text *textContent5 = textNew("1345%3");
  String *defineName5 = stringNew(textName5);
  String *defineContent5 = stringNew(textContent5);
  
  Text *textName6 = textNew("ULTIMATE");
  Text *textContent6 = textNew("7456*2");
  String *defineName6 = stringNew(textName6);
  String *defineContent6 = stringNew(textContent6);
  
  define = addDefinition(defineName,defineContent);
  define2 = addDefinition(defineName2,defineContent2);
  define3 = addDefinition(defineName3,defineContent3);
  define4 = addDefinition(defineName4,defineContent4);
  define5 = addDefinition(defineName5,defineContent5);
  define6 = addDefinition(defineName6,defineContent6);
  
  DefinitionTable MIN = {.data = define->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable MAX = {.data = define2->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable SUPER = {.data = define3->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable ULTRA = {.data = define4->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable HYPER = {.data = define5->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  DefinitionTable ULTIMATE = {.data = define6->name, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  
	DefinitionTable *root = NULL;
  DefinitionTable *rootFind = NULL;
  
  root = (DefinitionTable *) definitionAdd(root,&MIN);
  root = (DefinitionTable *) definitionAdd(root,&MAX);
  root = (DefinitionTable *) definitionAdd(root,&SUPER);
  root = (DefinitionTable *) definitionAdd(root,&ULTRA);
  root = (DefinitionTable *) definitionAdd(root,&HYPER);
  root = (DefinitionTable *) definitionAdd(root,&ULTIMATE);
	
  // printf("MIN %p\n",&MIN);
	// printf("MAX %p\n",&MAX);
	// printf("SUPER %p\n",&SUPER);
	// printf("ULTRA %p\n",&ULTRA);
	// printf("HYPER %p\n",&HYPER);
	// printf("ULTIMATE %p\n",&ULTIMATE);
  
  TEST_ASSERT_EQUAL_PTR(&MIN, root);
	TEST_ASSERT_EQUAL_PTR(&MAX, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&ULTIMATE, root->rightChild);
  
	TEST_ASSERT_EQUAL_PTR(&HYPER, MAX.leftChild);
	TEST_ASSERT_EQUAL_PTR(&SUPER, ULTIMATE.leftChild);
	TEST_ASSERT_EQUAL_PTR(&ULTRA, ULTIMATE.rightChild);

}