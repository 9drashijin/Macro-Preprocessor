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

void test_stringAssign_should_increase_the_text_reference(void){
	Text *text = textNew("define");
	String *str = stringNew(text);
	String *str1 = stringAssign(str); //2 pointer to str
	String *str2 = stringAssign(str); //3 pointer to str 
	TEST_ASSERT_EQUAL(3,str->reference);
	TEST_ASSERT_EQUAL(2,str->text->reference);
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

void test_stringDel_should_delete_the_string_with_text_reference(void){
	String *result;
  Text *text = textNew("define");
	String *str = stringNew(text);
  String *str1 = stringAssign(str);
	String *str2 = stringAssign(str);
  
  result = stringDel(str);
	TEST_ASSERT_EQUAL(2,result->reference);
	TEST_ASSERT_EQUAL(2,str->text->reference);
  TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(6,str->length);
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
void test_stringIsEqual_should_compare_and_return_1_if_both_are_the_same(void){
  Text *text = textNew("define");
  Text *text1 = textNew("define");
	String *str = stringNew(text);
	String *str2 = stringNew(text1);
  int compare;
  
	compare = stringIsEqual(str,str2);
	TEST_ASSERT_EQUAL(0,compare);
}

void test_stringIsEqual_should_compare_and_return_0_if_both_are_not_the_same(void){
  Text *text = textNew("define");
  Text *text1 = textNew("defineABC");
	String *str = stringNew(text);
	String *str2 = stringNew(text1);
  int compare;
  
	compare = stringIsEqual(str,str2);
	TEST_ASSERT_EQUAL(-1,compare);
}

void test_stringIsEqual_should_compare_and_return_0_if_both_length_are_same_while_the_text_are_not(void){
  Text *text = textNew("define");
  Text *text1 = textNew("defiii");
	String *str = stringNew(text);
	String *str2 = stringNew(text1);
  int compare;
  
	compare = stringIsEqual(str,str2);
	TEST_ASSERT_EQUAL(1,compare);
}

// STRING CLONE /////////
void test_stringClone_should_clone_the_source_to_the_destination_of_the_new_string(void){
  Text *text = textNew("#define");
  String *defination = stringNew(text);
  String *strCopy;
  strCopy = stringClone(defination);
  
  TEST_ASSERT_EQUAL_STRING("#define",strCopy->text->string);
  TEST_ASSERT_EQUAL(0,strCopy->start);
  TEST_ASSERT_EQUAL(7,strCopy->length);
}

// STRING DUPLICATE /////////
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
/////////////////////
// Find Identifier //
/////////////////////
void test_findIdentifier_should_find_the_identifier_and_return_the_start_and_length(void){
	Text *text = textNew("1+2*MAX-6/8");
	String *str = stringNew(text);
  
  String *iden = findIdentifier(str);
  
	TEST_ASSERT_EQUAL_STRING("1+2*MAX-6/8",str->text->string);
  TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(11,str->length);
  
  TEST_ASSERT_EQUAL_STRING("1+2*MAX-6/8",iden->text->string);
  TEST_ASSERT_EQUAL(4,iden->start);
	TEST_ASSERT_EQUAL(3,iden->length);
}

void test_findIdentifier_should_find_the_identifier_and_return_the_start_and_length_case2_front(void){
	Text *text = textNew("MAX+5*8");
	String *str = stringNew(text);
  
  String *iden = findIdentifier(str);
  
	TEST_ASSERT_EQUAL_STRING("MAX+5*8",str->text->string);
  TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(7,str->length);
  
  TEST_ASSERT_EQUAL_STRING("MAX+5*8",iden->text->string);
  TEST_ASSERT_EQUAL(0,iden->start);
	TEST_ASSERT_EQUAL(3,iden->length);
}
void test_findIdentifier_should_find_the_identifier_and_return_the_start_and_length_case3_behind(void){
	Text *text = textNew("5*8+MEGA");
	String *str = stringNew(text);
  
  String *iden = findIdentifier(str);
  
	TEST_ASSERT_EQUAL_STRING("5*8+MEGA",str->text->string);
  TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(8,str->length);
  
  TEST_ASSERT_EQUAL_STRING("5*8+MEGA",iden->text->string);
  TEST_ASSERT_EQUAL(4,iden->start);
	TEST_ASSERT_EQUAL(4,iden->length);
}