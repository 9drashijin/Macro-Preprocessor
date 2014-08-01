#ifndef StringObject_H
#define StringObject_H

#include "Text.h"
#define isSpace(ch) ( ch == ' ' || ch == '\t' )

typedef struct String{
	Text *text;
	int start;
	int length;
}String;

String *stringNew(Text *text);
String *stringDelete(String *textString);
String *stringClone(String *str);
String *stringDuplicate(String *str);
void stringLeftTrim(String *string);
void stringRightTrim(String *string);
int stringCompare(String *string1, String *string2);

#endif // StringObject_H
