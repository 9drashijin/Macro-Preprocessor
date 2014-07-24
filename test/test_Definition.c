#include "unity.h"
#include "Definition.h"
#include "StringObject.h"
#include "Text.h"
#include "ErrorCode.h"
#include "CException.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>

void setUp(void){}
void tearDown(void){}

void printName(String *str){
  Definition *define;
  // define = str;
  
  printf("======name====== \n");
  printf("text %s \n",define->name.text);
  printf("start %d \n",define->name.start);
  printf("length %d \n\n",define->name.length);
}
void printContent(String *str){
  Definition *define;
  // define = str;
  
  printf("=====content===== \n");
  printf("text %s \n",define->content.text);
  printf("start %d \n",define->content.start);
  printf("length %d \n",define->content.length);
}

void test_addDefinition_should_add_the_string_to_the_name_and_the_content(void){
  Definition *define;
  String *defineName = stringNew("ABC");
  String *defineContent = stringNew("2+B*D-6");
 
  define = addDefinition(defineName,defineContent);
  
  // printName(define);
  // printContent(define);
  
	TEST_ASSERT_EQUAL_STRING("ABC",define->name.text);
	TEST_ASSERT_EQUAL(0,define->name.start);
	TEST_ASSERT_EQUAL(3,define->name.length);
  
  TEST_ASSERT_EQUAL_STRING("2+B*D-6",define->content.text);
	TEST_ASSERT_EQUAL(0,define->content.start);
	TEST_ASSERT_EQUAL(7,define->content.length);
}

void test_addDefinition_should_add_another_string_to_the_name_and_the_content(void){
  Definition *define;
  String *defineName = stringNew("MIN");
  String *defineContent = stringNew("C&&D|5");
 
  define = addDefinition(defineName,defineContent);
  
  // printName(define);
  // printContent(define);
  
	TEST_ASSERT_EQUAL_STRING("MIN",define->name.text);
	TEST_ASSERT_EQUAL(0,define->name.start);
	TEST_ASSERT_EQUAL(3,define->name.length);
  
  TEST_ASSERT_EQUAL_STRING("C&&D|5",define->content.text);
	TEST_ASSERT_EQUAL(0,define->content.start);
	TEST_ASSERT_EQUAL(6,define->content.length);
}

void test_isPreprocessor_should_not_throw_error(){
	CEXCEPTION_T e;
	Try{
		TEST_ASSERT_EQUAL(1,isPreprocessor('#'));
	}
	Catch(e){
		TEST_ASSERT_EQUAL(ERROR_NOT_DEFINE,e);
	}
}
void test_isPreprocessor_should_throw_error(){
	CEXCEPTION_T e;
	Try{
		TEST_ASSERT_EQUAL(1,isPreprocessor('@'));
		TEST_FAIL_MESSAGE("ERROR_NOT_DEFINE");
	}
	Catch(e){
		TEST_ASSERT_EQUAL(ERROR_NOT_DEFINE,e);
	}
}

void test_strDuplicate(){
  Definition *define;
  String *defination = stringNew("#define MIN 5-7");
  stringDuplicate(defination);
  

}





