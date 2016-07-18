#ifndef CTYPE_H
#define CTYPE_H


#define _tolower(x) tolower(x)
#define _toupper(x) toupper(x)


int isascii(int c);
int islower(int c);
int isupper(int c);

int toascii(int c);
int tolower(int c);
int toupper(int c);

#endif
