#include "unity.h"
#include "StringObject.h"
#include "Text.h"

void setUp(void){}
void tearDown(void){}

void test_stringNew_should_create_a_new_string(void){
  Text *text = textNew("define");
  String *str = stringNew(text);
  
  TEST_ASSERT_EQUAL_STRING("define",str->text->string);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(6,str->length);

}
void test_stringNew_should_create_string_with_static_text(void){
	Text *text = t"define";
	String *str = stringNew(text);
  TEST_ASSERT_EQUAL_STRING(text->string,str->text->string);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(6,str->length);
}

void test_stringDelete_should_delete_the_string(void){
  Text *text = textNew("define");
  String *str = stringNew(text);
  
  stringDelete(str);

	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(0,str->length);
}

//TRIM LEFT////////
void test_stringLeftTrim_should_trim_the_string_to_the_left(void){
  Text *text = textNew("define");
  String *str = stringNew(text);
  stringLeftTrim(str);
  
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(6,str->length);
}

void test_stringLeftTrim_should_trim_the_string_to_the_left_case2(void){
  Text *text = textNew(" define ");
	String *str = stringNew(text);
	stringLeftTrim(str);
  
	TEST_ASSERT_EQUAL(1,str->start);
	TEST_ASSERT_EQUAL(7,str->length);
}

void test_stringLeftTrim_should_trim_the_string_to_the_left_case3(void){
  Text *text = textNew("  not define ");
	String *str = stringNew(text);
	stringLeftTrim(str);
  
	TEST_ASSERT_EQUAL(2,str->start);
	TEST_ASSERT_EQUAL(11,str->length);
}

void test_stringLeftTrim_should_trim_the_string_to_the_left_case4(void){
  Text *text = textNew("      not define");
	String *str = stringNew(text);
	stringLeftTrim(str);
  
	TEST_ASSERT_EQUAL(6,str->start);
	TEST_ASSERT_EQUAL(10,str->length);
}
void test_stringLeftTrim_should_trim_the_string_to_the_left_with_Static_text(void){
  Text *text = t"      not define";
	String *str = stringNew(text);
	stringLeftTrim(str);
  
	TEST_ASSERT_EQUAL(6,str->start);
	TEST_ASSERT_EQUAL(10,str->length);
}
//TRIM RIGHT////////
void test_stringRightTrim_should_trim_the_string_to_the_right(void){
  Text *text = textNew(" define");
  String *str = stringNew(text);
  stringRightTrim(str);
  
  TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(7,str->length);
}

void test_stringTrimRight(void){
  Text *text = textNew("    define ");
	String *str = stringNew(text);
	stringRightTrim(str);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(10,str->length);
}

void test_stringRightTrim_should_trim_the_string_to_the_left_case3(void){
  Text *text = textNew("  not define ");
	String *str = stringNew(text);
	stringRightTrim(str);
  
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(12,str->length);
}

void test_stringRightTrim_should_trim_the_string_to_the_left_case4(void){
  Text *text = textNew("      not define   ");
	String *str = stringNew(text);
	stringRightTrim(str);
  
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(16,str->length);
}
void test_stringRightTrim_should_trim_the_string_to_the_left_with_Static_text(void){
  Text *text = t"      not define   ";
	String *str = stringNew(text);
	stringRightTrim(str);
  
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(16,str->length);
}

//STRING COMPARE/////////
void test_stringCompare_should_compare_and_return_1_if_both_are_the_same(void){
  Text *text = textNew("define");
  Text *text1 = textNew("define");
	String *str = stringNew(text);
	String *str2 = stringNew(text1);
  int compare;
  
	compare = stringCompare(str,str2);
	TEST_ASSERT_EQUAL(1,compare);
}

void test_stringCompare_should_compare_and_return_0_if_both_are_not_the_same(void){
  Text *text = textNew("define");
  Text *text1 = textNew("defineABC");
	String *str = stringNew(text);
	String *str2 = stringNew(text1);
  int compare;
  
	compare = stringCompare(str,str2);
	TEST_ASSERT_EQUAL(0,compare);
}

void test_stringCompare_should_compare_and_return_0_if_both_length_are_same_while_the_text_are_not(void){
  Text *text = textNew("define");
  Text *text1 = textNew("defiii");
	String *str = stringNew(text);
	String *str2 = stringNew(text1);
  int compare;
  
	compare = stringCompare(str,str2);
	TEST_ASSERT_EQUAL(0,compare);
}

void test_stringClone_should_clone_the_source_to_the_destination_of_the_new_string(){
  Text *text = textNew("#define MIN 2*3");
  String *defination = stringNew(text);
  String *strCopy;
  strCopy = stringClone(defination);
  
  TEST_ASSERT_EQUAL_STRING("#define MIN 2*3",strCopy->text->string);
  TEST_ASSERT_EQUAL(0,strCopy->start);
  TEST_ASSERT_EQUAL(15,strCopy->length);
}

void test_stringDuplicate_should_duplicate_the_string_to_a_new_string(){
  Text *text = textNew("#define MAX 5*8");
  String *defination = stringNew(text);
  String *strDuplicate;
  strDuplicate = stringDuplicate(defination);
  
  TEST_ASSERT_EQUAL_STRING("#define MAX 5*8",strDuplicate->text->string);
  TEST_ASSERT_EQUAL(0,strDuplicate->start);
  TEST_ASSERT_EQUAL(15,strDuplicate->length);
}




