#ifndef StringObject_H
#define StringObject_H

#define isSpace(ch) ( ch == ' ' || ch == '\t' )

typedef struct String{
	char *text;
	int start;
	int length;
}String;

String *stringNew(char *textString);
String *stringDelete(String *textString);
String *stringClone(String *str);
String *stringDuplicate(String *str);
void stringLeftTrim(String *string);
void stringRightTrim(String *string);
int stringCompare(String *string1, String *string2);

#endif // StringObject_H
