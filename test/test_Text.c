#include "unity.h"
#include "Text.h"

void setUp(void){}
void tearDown(void){}

/////New Text/////
void test_textNew_should_create_a_new_dynamic_text(void){
	Text *text = textNew("define");
  
  TEST_ASSERT_EQUAL_STRING("define",text->string);
	TEST_ASSERT_EQUAL(1,text->reference);
}
void test_textNew_should_create_a_new_static_text(void){
	Text *text = t"defineX";
  TEST_ASSERT_EQUAL_STRING("defineX",text->string);
	TEST_ASSERT_EQUAL(0x80000000,text->reference); // "\x00\x00\x00\x80"
}
void test_textNew_should_create_another_new_dynamic_text(void){
	Text *text = textNew("#define X 4796");
  
  TEST_ASSERT_EQUAL_STRING("#define X 4796",text->string);
	TEST_ASSERT_EQUAL(1,text->reference);
}
void test_textNew_should_create_aanother_new_static_text(void){
	Text *text = t"#define Anew Text";
  TEST_ASSERT_EQUAL_STRING("#define Anew Text",text->string);
	TEST_ASSERT_EQUAL(0x80000000,text->reference); // "\x00\x00\x00\x80"
}

/////New ASSIGN/////
void test_textAssign_give_a_new_text_should_increament_the_reference(void){

	Text *text = textNew("define");
	Text *text2 = textAssign(text);

  TEST_ASSERT_EQUAL_STRING("define",text->string);
  TEST_ASSERT_EQUAL_STRING("define",text2->string);
  TEST_ASSERT_EQUAL_STRING(text->string,text2->string);
	TEST_ASSERT_EQUAL(2,text->reference);
}

void test_textAssign_give_a_new_text_should_not_increament_the_reference(void){

	Text *text = t"defineStatic";
	Text *text2 = textAssign(text);
	
	TEST_ASSERT_EQUAL_STRING("defineStatic",text->string);
  TEST_ASSERT_EQUAL_STRING("defineStatic",text2->string);
  TEST_ASSERT_EQUAL_STRING(text->string,text2->string);
	TEST_ASSERT_EQUAL(0x80000000,text->reference);
}

/////TEXT DELETE/////
void test_textDelete_should_delete_dynamic_text(void){
	Text *text = textNew("define");

	TEST_ASSERT_EQUAL(NULL,textDelete(text));
}

void test_textDelete_should_not_delete_static_text(void){
	Text *text = t"defineX";
  
  TEST_ASSERT_EQUAL_STRING("defineX",text->string);
  TEST_ASSERT_EQUAL_STRING("defineX",textDelete(text)->string);
	TEST_ASSERT_EQUAL_STRING(text,textDelete(text));
	TEST_ASSERT_EQUAL(0x80000000,textDelete(text)->reference);
}

void test_textDelete_should_not_delete_the_text_when_the_reference_is_not_0(void){
  Text *result;
	Text *text = textNew("define");
	Text *text1 = textAssign(text);
	result = textDelete(text);
  
  TEST_ASSERT_EQUAL_STRING("define",text->string);
	TEST_ASSERT_EQUAL_STRING("define",result->string);
	TEST_ASSERT_EQUAL(text,result);
	TEST_ASSERT_EQUAL(text1,result);
	TEST_ASSERT_EQUAL(1,result->reference);
}

void test_textDelete_should_not_delete_the_text_and_reduce_the_reference(void){
	Text *text = t"defineX";
	Text *text1 = textAssign(text);
  
  TEST_ASSERT_EQUAL_STRING("defineX",text->string);
	TEST_ASSERT_EQUAL_STRING("defineX",textAssign(text)->string);
	TEST_ASSERT_EQUAL(text,textDelete(text));
	TEST_ASSERT_EQUAL(text1,textDelete(text));
	TEST_ASSERT_EQUAL(0x80000000,textDelete(text)->reference);
}

void test_textLength_should_return_the_length_of_the_text(){
  Text *text = textNew("LengthOfText");
  int length;
  
  length = textLength(text);
  
  TEST_ASSERT_EQUAL(12,length);
}
void test_textEmptyNew_should_return_the_length_of_the_text(){
  Text *txt = textNew("LengthOfText");
  Text *text = textEmptyNew(12);
  int length;
  
  length = textLength(text);
  // TEST_ASSERT_EQUAL_STRING("",text->string);
  TEST_ASSERT_EQUAL(1,text->reference);
}