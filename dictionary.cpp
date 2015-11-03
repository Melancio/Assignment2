/*
 * File:   dictionary.cpp
 * Author: Melance Gaudreault 4403946
 */
#include "dictionary.h"


BOOL InsertWord(DICT dict, WORD word){
/*
  adds word to dictionary , if word can't be added returns false else returns true
*/
	for ( int i = 0; i < MAX; i++){
		if ( dict[i] == word ){
			return true;
			break;
		}
		else if ( dict[i].empty()){
			dict[i] = word;
			return true;
			break;
		}
    }
	return false;

}

void DumpDictionary(DICT dict, int count[]) {
/*
  will sort the dictionary, and display the contents
*/
	int dictOrder[MAX];
	int tmp;
	for( int i = 0; i < MAX; i++) dictOrder[i] = i;
	for( int i = 0; i < MAX; i++){		//This will sort order of dictionary in dictOrder.
		for( int j = 0; j < MAX-1; j++){
			if (dict[j].empty()) break;
			if( dict[dictOrder[j]] > dict[dictOrder[j+1]]){
				int tmp = dictOrder[j+1];
				dictOrder[j+1] = dictOrder[j];
				dictOrder[j] = tmp;
			}
		}

	}
	cout << endl << "FREQUENCY    WORD" << endl << "----------------------" << endl;
	for ( int i = 0; i < MAX; i++ ){                //This displays the dictionary
		if (dict[dictOrder[i]].empty()) break;
		cout << "  " << count[dictOrder[i]];
		cout << "          ";
		cout << dict[dictOrder[i]];
		cout << endl;
	}
}

WORD GetNextWord(void){
/*
   will retrieve next word in input stream. Word is defined just as in assignment #1
   returns a WORD or empty string  if no more words in input stream
*/
    char ch;
    int newLine= 0;
    WORD tmp;
    while( cin.good() )
    {
        ch = cin.get();
        if ( isalpha(ch) )  /* function test is ch  is A-Z, a-z */
        {
            ch = tolower(ch);
            tmp.push_back (ch); /* make room for ch in the WORD */
            newLine = 1;
        }
        else
        if (newLine) return tmp;
    }

}

BOOL FullDictionary(DICT dict) {
/*
   if dictionary is full, return 1 else 0
 */
	if ( dict[MAX].empty() ) return 0;
	else return 1;
}

int LocateWord(DICT dict, WORD word) {
/*
   will determine if dictionary contains word. if found, returns position else returns value < 0
*/
	for ( int i = 0; i < MAX; i++){
		if ( dict[i] == word ){
			return i;
			break;
		}
	}
    return -1;
}

