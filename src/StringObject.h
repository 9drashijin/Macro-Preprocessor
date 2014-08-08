#ifndef StringObject_H
#define StringObject_H

#include "Text.h"
#define isSpace(ch) ( ch == ' ' || ch == '\t' )

typedef struct String{
  unsigned int reference;
	Text *text;
	int start;
	int length;
}String;

String *stringNew(Text *text);
String *stringAssign(String *string);
String *stringDelete(String *textString);
String *stringDel(String *string);
String *stringClone(String *str);
String *stringDuplicate(String *str);
void stringLeftTrim(String *string);
void stringRightTrim(String *string);
void stringTrim(String *string);
int stringIsEqual(String *string1, String *string2);
String *stringRemoveWordNotContaining(String *str,char delimites[]);
String *stringRemoveWordContaining(String *str, char containSet[]);
String *findIdentifier(String *str);

#endif // StringObject_H
