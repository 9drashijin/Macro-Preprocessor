#include <stdio.h>
#include "StringObject.h"
#include <malloc.h>
#include <string.h>
#include "Text.h"
#include "CharSet.h"

String *stringNew(Text *text){

	String *newString = malloc(sizeof(String));
	
	newString->text = textAssign(text);
  newString->reference = 1;
	newString->start = 0;
	newString->length = strlen(text->string);
	
	return newString;
}

String *stringAssign(String *string){
	string->reference++;
	return string;
}

String *stringDelete(String *textString){

  String *deletedString;
  deletedString->text = textDelete(textString->text);
  deletedString->start = 0;
  deletedString->length = 0;
  
  return deletedString;
}

String *stringDel(String *string){

	string->reference--;
	if(string->reference == 0){
		free(string);
		textDelete(string->text);
		return NULL;
	}
	return string;
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

void stringTrim(String *string){
	stringLeftTrim(string);
	stringRightTrim(string);
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

String *stringRemoveWordNotContaining(String *str,char delimiter[]){
	int i,j,count;
  int delimiterLength;
  int strLength;
	String *strReturn = stringNew(str->text);
	
	delimiterLength = strlen(delimiter);
	strLength = strlen(str->text->string);
	strReturn->start = str->start;
	strReturn->length = 0;
	
	for(j=str->start ; j<strLength ; j++){
		for(i=0,count=0 ; i<delimiterLength ; i++){
			if(str->text->string[j] == delimiter[i]){
				break;
			}
			else{
				count++;
			}
		}
		if(count >= delimiterLength){
			str->start++;
			str->length--;
			strReturn->length++;
		}
		else
			break;
	}
	return strReturn;
}

String *stringRemoveWordContaining(String *str, char containSet[]){
	int i,j,count;
  int containLength;
  int strLength;
	String *strReturn = stringNew(str->text);
	containLength = strlen(containSet);
	strLength = strlen(str->text->string);
	strReturn->start = str->start;
	strReturn->length = 0;
	
	for(j=str->start ; j<strLength ; j++){
		for(i=0,count=0 ; i<containLength ; i++){
			if(str->text->string[j] == containSet[i]){
				str->start++;
				str->length--;
				strReturn->length++;
				break;
			}
			else{
				count++;
			}
		}
		if(count>=containLength)
			break;
	}
	return strReturn;
}

String *findIdentifier(String *str){
  String *str2;
  String *iden;
  String *temp;

  str2  = stringClone(str);
  
  temp = stringRemoveWordNotContaining(str2,alphabetSet);
  stringDel(str2);
  iden = stringRemoveWordContaining(temp,alphaNumericSet);
  
  return iden;
}
