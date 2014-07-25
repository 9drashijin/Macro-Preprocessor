#include "unity.h"
#include "StringObject.h"

void setUp(void){}
void tearDown(void){}

void test_stringNew_should_create_a_new_string(void){
  String *str = stringNew("define");
  
  TEST_ASSERT_EQUAL_STRING("define",str->text);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(6,str->length);

}

void test_stringDelete_should_delete_the_string(void){
  String *str = stringNew("define");
  
  stringDelete(str);
  
  TEST_ASSERT_EQUAL_STRING(" ",str->text);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(0,str->length);

}

////////TRIM LEFT////////
void test_stringLeftTrim_should_trim_the_string_to_the_left(void){
  String *str = stringNew("define ");
  stringLeftTrim(str);
  
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(7,str->length);
}

void test_stringLeftTrim_should_trim_the_string_to_the_left_case2(void){
	String *str = stringNew(" define ");
	stringLeftTrim(str);
  
	TEST_ASSERT_EQUAL(1,str->start);
	TEST_ASSERT_EQUAL(7,str->length);
}

void test_stringLeftTrim_should_trim_the_string_to_the_left_case3(void){
	String *str = stringNew("  not define ");
	stringLeftTrim(str);
  
	TEST_ASSERT_EQUAL(2,str->start);
	TEST_ASSERT_EQUAL(11,str->length);
}

void test_stringLeftTrim_should_trim_the_string_to_the_left_case4(void){
	String *str = stringNew("      not define");
	stringLeftTrim(str);
  
	TEST_ASSERT_EQUAL(6,str->start);
	TEST_ASSERT_EQUAL(10,str->length);
}

////////TRIM RIGHT////////
void test_stringRightTrim_should_trim_the_string_to_the_right(void){
  String *str = stringNew(" define");
  stringRightTrim(str);
  
  TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(7,str->length);
}

void test_stringTrimRight(void){
	String *str = stringNew("    define ");
	stringRightTrim(str);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(10,str->length);
}

void test_stringRightTrim_should_trim_the_string_to_the_left_case3(void){
	String *str = stringNew("  not define ");
	stringRightTrim(str);
  
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(12,str->length);
}

void test_stringRightTrim_should_trim_the_string_to_the_left_case4(void){
	String *str = stringNew("      not define   ");
	stringRightTrim(str);
  
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(16,str->length);
}

////////STRING COMPARE/////////
void test_stringCompare_should_compare_and_return_1_if_both_are_the_same(void){
	String *str = stringNew("define");
	String *str2 = stringNew("define");
  int compare;
  
	compare = stringCompare(str,str2);
	TEST_ASSERT_EQUAL(1,compare);
}

void test_stringCompare_should_compare_and_return_0_if_both_are_not_the_same(void){
	String *str = stringNew("define");
	String *str2 = stringNew("defineABC");
  int compare;
  
	compare = stringCompare(str,str2);
	TEST_ASSERT_EQUAL(0,compare);
}

void test_stringCompare_should_compare_and_return_0_if_both_length_are_same_while_the_text_are_not(void){
	String *str = stringNew("define");
	String *str2 = stringNew("defiii");
  int compare;
  
	compare = stringCompare(str,str2);
	TEST_ASSERT_EQUAL(0,compare);
}







