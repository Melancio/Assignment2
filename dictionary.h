/*
 * File:   dictionary.h
 * Author: Melance Gaudreault 4403946
 */
#ifndef	DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h> 	//header
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

#define MAX 100		//header

using namespace std;
using std::string;

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);




#endif
