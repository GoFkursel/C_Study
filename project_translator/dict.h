#ifndef DICT_H
#define DICT_H

#include "dict.c"

typedef struct  DICT
{
    char* word;
    char* trans;
}dict;

dict* list;

int GetWord();
int SearchWord(char* word,char* trans);
void DestroySpace();

#endif