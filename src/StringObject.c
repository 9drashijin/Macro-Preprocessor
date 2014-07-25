#include <stdio.h>
#include "StringObject.h"
#include <malloc.h>
#include <string.h>
#include "Text.h"

String *stringNew(char *textString){

	String *newString = malloc(sizeof(String));
  
	newString->text = textNew(textString);
	newString->start = 0;
	newString->length = strlen(newString->text->string);
	
	return newString;

}

String *stringDelete(String *textString){

  String *deletedString;
  deletedString->text = textDelete(textString->text);
  deletedString->start = 0;
  deletedString->length = 0;
  
  return deletedString;
 
}

String *stringClone(String *str){

  char *newString = malloc(sizeof(strlen(str->text->string+1)));
  String *rString = malloc(sizeof(String));
  
  strcpy(newString,str->text->string);
  rString->text = textNew(newString);
  rString->start = str->start;
  rString->length = str->length;
  
  return rString;
}

String *stringDuplicate(String *str){
  
  String *newString = malloc(sizeof(String));
  Text *temp = textNew(strdup(str->text->string));
  
	newString->text = temp;
	newString->start = str->start;
	newString->length = str->length;
	
	return newString;
}

void stringLeftTrim(String *string){
  
  int i = string->start;
  int j = strlen(string->text->string);
  
  for(;i<=j;i++){
    if(string->text->string[i] == ' ' || string->text->string[i] == '\t' ){
    string->start++;
    string->length--;
    }
    else break;
  }
}

void stringRightTrim(String *string){
  
  int i = string->start;
  int j = string->length;
  
  int txt = i + j - 1;
	
	for(;;txt--){
		if(j == 0)
			break;
		else if(isSpace(string->text->string[txt]))
				string->length--;
		else
			break;
	}
}

int stringCompare(String *string1, String *string2){
  int i;
  int length1,length2;
  char rString1, rString2;
  
  length1 = strlen(string1->text->string);
  length2 = strlen(string2->text->string);
  
  if(length1 == length2){
    for(i=0;i<length1;i++){
        if(string1->text->string[i] != string2->text->string[i])
          return 0;
    }
  return 1;
  }
  else return 0;
}