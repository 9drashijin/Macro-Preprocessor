#include <stdio.h>
#include "StringObject.h"
#include <malloc.h>
#include <string.h>

String *stringNew(char *textString){

	String *newString = malloc(sizeof(String));
	// char *text = malloc(sizeof(strlen+1));
  // strcpy(textString,newString);
  
	newString->text = textString;
	newString->start = 0;
	newString->length = strlen(newString->text);
	
	return newString;

}

String *stringDelete(String *textString){

  String *deletedString;
  deletedString = (String *)textString;
  deletedString->text = " ";
  deletedString->start = 0;
  deletedString->length = 0;
  
  return deletedString;
}

void stringLeftTrim(String *string){
  
  int i = string->start;
  int j = strlen(string->text);
  
  for(;i<=j;i++){
    if(string->text[i] == ' ' || string->text[i] == '\t' ){
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
		else if(isSpace(string->text[txt]))
				string->length--;
		else
			break;
	}
}

int stringCompare(String *string1, String *string2){
  int i;
  int length1,length2;
  char rString1, rString2;
  
  length1 = strlen(string1->text);
  length2 = strlen(string2->text);
  
  if(length1 == length2){
    for(i=0;i<length1;i++){
        if(string1->text[i] != string2->text[i])
          return 0;
    }
  return 1;
  }
  else return 0;
}