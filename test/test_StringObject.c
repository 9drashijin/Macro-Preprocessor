#include "unity.h"
#include "StringObject.h"
#include "Text.h"
#include "CharSet.h"

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

// TRIM LEFT////////
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
// TRIM RIGHT////////
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
// STRING TRIM /////////
void test_stringTrim_should_trim_both_sides(void){
	Text *text = textNew("    QinYi Ler    ");
	String *str = stringNew(text);
	stringTrim(str);
	TEST_ASSERT_EQUAL(4,str->start);
	TEST_ASSERT_EQUAL(9,str->length);
}

void test_stringTrim_should_trim_both_sides_second_test(void){
	Text *text = textNew(" \t \t   QinYi Ler   \t \t  ");
	String *str = stringNew(text);
	stringTrim(str);
	TEST_ASSERT_EQUAL(7,str->start);
	TEST_ASSERT_EQUAL(9,str->length);
}

// STRING COMPARE/////////
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

void test_stringClone_should_clone_the_source_to_the_destination_of_the_new_string(void){
  Text *text = textNew("#define");
  String *defination = stringNew(text);
  String *strCopy;
  strCopy = stringClone(defination);
  
  TEST_ASSERT_EQUAL_STRING("#define",strCopy->text->string);
  TEST_ASSERT_EQUAL(0,strCopy->start);
  TEST_ASSERT_EQUAL(7,strCopy->length);
}

void test_stringDuplicate_should_duplicate_the_string_to_a_new_string(void){
  Text *text = textNew("#define MAX 5*8");
  String *defination = stringNew(text);
  String *strDuplicate;
  strDuplicate = stringDuplicate(defination);
  
  TEST_ASSERT_EQUAL_STRING("#define MAX 5*8",strDuplicate->text->string);
  TEST_ASSERT_EQUAL(0,strDuplicate->start);
  TEST_ASSERT_EQUAL(15,strDuplicate->length);
}

// STRING REMOVE WORD NOT CONTAINING ///////
void test_stringRemoveWordNotContaining_should_remove_the_word(void){
	Text *text = textNew("should remove XYZ");
	String *str = stringNew(text);
	String *remove = stringRemoveWordNotContaining(str,"XYZ");
	
	TEST_ASSERT_EQUAL(14,str->start);
	TEST_ASSERT_EQUAL(3,str->length);
	TEST_ASSERT_EQUAL(0,remove->start);
	TEST_ASSERT_EQUAL(14,remove->length);
	TEST_ASSERT_EQUAL(3,text->reference);
}

void test_stringRemoveWordNotContaining_should_not_remove_the_word_if_start_from_front(void){
	Text *text = textNew("XYZ should not remove");
	String *str = stringNew(text);
	String *remove = stringRemoveWordNotContaining(str,"XYZ");
	
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(21,str->length);
	TEST_ASSERT_EQUAL(0,remove->start);
	TEST_ASSERT_EQUAL(0,remove->length);
	TEST_ASSERT_EQUAL(3,text->reference);
}

void test_stringRemoveWordNotContaining_should_remove_the_word_with_static_text(void){
	Text *text = t"removeTHIS";
	String *str = stringNew(text);
	String *remove = stringRemoveWordNotContaining(str,"T");
	
	TEST_ASSERT_EQUAL(6,str->start);
	TEST_ASSERT_EQUAL(4,str->length);
	TEST_ASSERT_EQUAL(0,remove->start);
	TEST_ASSERT_EQUAL(6,remove->length);
	TEST_ASSERT_EQUAL(0x80000000,text->reference);
}

// STRING REMOVE WORD CONTAINING ///////
void test_stringRemoveWordContaining_should_remove_the_word(void){
	Text *text = textNew("THIS<<Remove that");
	String *str = stringNew(text);
	String *remove = stringRemoveWordContaining(str,"THIS");
	
	TEST_ASSERT_EQUAL(4,str->start);
	TEST_ASSERT_EQUAL(13,str->length);
	TEST_ASSERT_EQUAL(0,remove->start);
	TEST_ASSERT_EQUAL(4,remove->length);
	TEST_ASSERT_EQUAL(3,text->reference);
}

void test_stringRemoveWordContaining_should_remove_the_word_with_random_text(void){
	Text *text = textNew("THIS<<Remove that");
	String *str = stringNew(text);
	String *remove = stringRemoveWordContaining(str,"SIHT");
	
	TEST_ASSERT_EQUAL(4,str->start);
	TEST_ASSERT_EQUAL(13,str->length);
	TEST_ASSERT_EQUAL(0,remove->start);
	TEST_ASSERT_EQUAL(4,remove->length);
	TEST_ASSERT_EQUAL(3,text->reference);
}

void test_stringRemoveWordContaining_should_not_remove_the_word_if_from_start_text(void){
	Text *text = textNew(">>THIS<<Remove that");
	String *str = stringNew(text);
	String *remove = stringRemoveWordContaining(str,"SIHT");
	
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(19,str->length);
	TEST_ASSERT_EQUAL(0,remove->start);
	TEST_ASSERT_EQUAL(0,remove->length);
	TEST_ASSERT_EQUAL(3,text->reference);
}

void test_stringRemoveWordContaining_should_remove_the_word_with_static_text(void){
	Text *text = t"THIS<<Remove that";
	String *str = stringNew(text);
	String *remove = stringRemoveWordContaining(str,"THIS");
	
	TEST_ASSERT_EQUAL(4,str->start);
	TEST_ASSERT_EQUAL(13,str->length);
	TEST_ASSERT_EQUAL(0,remove->start);
	TEST_ASSERT_EQUAL(4,remove->length);
	TEST_ASSERT_EQUAL(0x80000000,text->reference);
}