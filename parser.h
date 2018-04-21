//
// Created by jrinder on 2/9/18.
//

//#include <bits/types/FILE.h>

#ifndef SCANNER01_PARSER_H
#define SCANNER01_PARSER_H

void startParser();
void skipTabs(char c);
int isEmpty(FILE *);
FILE *filePntr; //made this a variable within parser.h due to issue passing file Pointers from function and returning
//the pointer
int wordNum;
char *lexm, *tokn;
void getNextStrngArry(int);
void matchLexTok(char *, char *,char *);
int compLexTok(char *, char *, char *);
void beginParser();
void parseDecDefs();
void parseProc();
void parseTypDef();
void parseStatmntsLst();
void parseIndvStatmnt();
void parseWrtLne();
void parseAssngmnt();
void parseExprsn();
void parseTerms();
void parseTerms();
void parseAddTerms();
void parseFactor();
void parseAddExprsn();
void parseDecList();
char endChar;
int arryStrt;
int identifSize;
char *identifer[LIMIT];
void parseGlobal();
void parseConsts();
void parseConstLsts();
void parseConstnts(char *, char *);


#endif //SCANNER01_PARSER_H
