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
  Text *MIN = textNew("(10**11)");
  Text *txt;
  
  txt = textSubstitute(text,4,3,MIN);
  
  TEST_ASSERT_EQUAL_STRING("2+3*(10**11)",txt->string);
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
  free(returnedText);
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
  free(returnedText);
}