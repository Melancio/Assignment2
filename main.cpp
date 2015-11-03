/*
 * File:   main.cpp
 * Author: Melance Gaudreault 4403946
 */

#include "dictionary.h"


DICT dictionary;  //your dictionary dict
WORD word;        //
int count[MAX];   //tracks word frequencies


int main (void) {
    int pos;

    while (1) {
       word = GetNextWord();
       if ( word.empty() )  {
           DumpDictionary(dictionary,count);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >=  0 )
           count[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}
