#include "Text.h"
#include <stdio.h>
#include <malloc.h>
#include "String.h"
#include "CharSet.h"
/**
* Function  : Create a new Text (textNew)
* Input     : String to create
* Output    : text 
*/
Text *textNew(char *str){
	Text *text = (Text *)malloc((strlen(str)+1)*4);// 4 byte for the reference, 1 for the last '\0'
	// Text *text = (Text *)malloc(strlen(str)+1+4); 
	strcpy(text->string,str);
	text->reference = 1;
	return text;
}
/**
* Function  : Assign the text with the reference (textAssign)
* Input     : Text
* Output    : Text 
*/
Text *textAssign(Text *text){
	if(text->reference < 0x80000000)
		text->reference++;
	return text;
}
/**
* Function  : Delete the Text (textDelete)
* Input     : Text
* Output    : Text 
*/
Text *textDelete(Text *text){
	if(text->reference < 0x80000000 && text->reference > 0){
		text->reference--;
		if(text->reference == 0){
			free(text);
			return NULL;
		}		
	}
	return text;
}
/**
* Function  : Find the length of the Text(textLength)
* Input     : Text
* Output    : Text length
*/
int textLength(Text *text){
  return strlen(text->string);
}
/**
* Function  : Create a new Empty Text (textNew)
* Input     : String to create
* Output    : text 
*/
Text *textEmptyNew(int length){
  Text *text = malloc(sizeof(int)*(length)+4+2);  // 4 byte for the reference, 1 for the last '\0'
  
  text->reference = 1;
  return text;
}