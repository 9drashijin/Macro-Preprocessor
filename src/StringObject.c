#include <stdio.h>
#include "StringObject.h"
#include <malloc.h>
#include <string.h>
#include "Text.h"
#include "CharSet.h"
/**
* Function  : Create a New String Object (stringNew)
* Input     : Text to create the String Object
* Return    : The new String with its start, length and reference
*/
String *stringNew(Text *text){

	String *newString = malloc(sizeof(String));

	newString->text = textAssign(text);
  newString->reference = 1;
	newString->start = 0;
	newString->length = strlen(text->string);

	return newString;
}
/**
* Function  : Assign the String with reference increment (stringAssign)
* Input     : The string of the String Object;
* Return    : The reference after increment
*/
String *stringAssign(String *string){
	string->reference++;
	return string;
}
/**
* Function  : Delete and clear the String Object (stringDelete)
* Input     : The string of the String Object;
* Return    : The deleted String Object
*/
String *stringDelete(String *textString){

  String *deletedString;
  deletedString->text = textDelete(textString->text);
  deletedString->start = 0;
  deletedString->length = 0;

  return deletedString;
}
/**
* Function  : decrement the reference and free the String Object (stringDel)
* Input     : The string of the String Object;
* Return    : The deleted String Object
*/
String *stringDel(String *string){

	string->reference--;
	if(string->reference == 0){
		free(string);
		textDelete(string->text);
		return NULL;
	}
	return string;
}
/**
* Function  : Clone the String Object to the another String Object (stringClone)
* Input     : The string of the String Object;
* Return    : The Cloned new String Object
*/
String *stringClone(String *str){

  // char *newString = malloc(sizeof(strlen(str->text->string+1)));
  char *newString = malloc(sizeof(String));
  String *rString = malloc(sizeof(String));

  strcpy(newString,str->text->string);
  rString->text = textNew(newString);
  rString->start = str->start;
  rString->length = str->length;

  return rString;
}
/**
* Function  : Duplicate the String Object to the another String Object (stringDuplicate)
* Input     : The string of the String Object;
* Return    : The duplicated new String Object
*/
String *stringDuplicate(String *str){

  String *newString = malloc(sizeof(String));
  Text *temp = textNew(strdup(str->text->string));

	newString->text = temp;
	newString->start = str->start;
	newString->length = str->length;

	return newString;
}
/**
* Function  : trim the string to the left by increment its start and decrement its length (stringLeftTrim)
* Input     : The string of the String Object;
* Return    : The trimmed String Object to the Left
*/
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
/**
* Function  : trim the string to the left by decrement its length (stringRightTrim)
* Input     : The string of the String Object;
* Return    : The trimmed String Object to the Right
*/
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
/**
* Function  : trim the string to the left and right (stringTrim)
* Input     : The string of the String Object;
* Return    : The trimmed String Object
*/
void stringTrim(String *string){
	stringLeftTrim(string);
	stringRightTrim(string);
}
/**
* Function  : Compare the String and return for the similarity(stringCompare)
* Input     : Two different String Object to be compare
* Return    : if same return 1, else return 0 if not the same
*/
int stringIsEqual(String *string1, String *string2){
  int i;
  int length1,length2;
  char rString1, rString2;

  length1 = strlen(string1->text->string);
  length2 = strlen(string2->text->string);

  if(strcmp(string1->text->string, string2->text->string) == 0)return 0;
	else if(strcmp(string1->text->string, string2->text->string) > 0) return 1;
	else if(strcmp(string1->text->string, string2->text->string) < 0) return -1;

  // if(length1 == length2){
    // for(i=0;i<length1;i++){
        // if(string1->text->string[i] != string2->text->string[i])
          // return 1;
    // }
  // return 0;
  // }
  // else return 1;
}
/**
* Function  : remove the word in the string that not contain in the delimiter(stringRemoveWordNotContaining)
* Input     : String to be removed the word, and the set of character that should not be remove
* Return    : The String that removed from the String Object
*/
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
/**
* Function  : remove the word in the string that contain in the delimiter(stringRemoveWordContaining)
* Input     : String to be removed the word, and the set of character that should be remove
* Return    : The String that removed from the String Object
*/
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
/**
* Function  : Find the identifier in the String Object and return the identifier(findIdentifier)
* Input     : The string of the String Object;
* Return    : The identifier that Found in the String
*/
String *findIdentifier(String *str){
  String *str2;
  String *iden;
  String *temp;

  str2  = stringClone(str);
  temp = stringRemoveWordNotContaining(str2,alphabetSet); //alphabetSet
  stringDel(temp);
  iden = stringRemoveWordContaining(str2,alphaNumericSet); //alphaNumericSet

  return iden;
}
