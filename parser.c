//
// Created by jrinder on 2/9/18.
//
#include "token.h"
#include <stdio.h>
#include <memory.h>
#include "parser.h"
#include "scanner.h"
#include "assmblr.h"

char token[LIMIT][MAX];
char lexem[LIMIT][MAX];
int arryC=0;


void startParser(){
    char currentChar;
    int intI=0;
    int intJ=0;
    int intA=0;
    int intB=0;
    int chrType;
    int lineNo=1;
    int totalI=0;

    //====================================OPEN THE .SCAN FILE==========================================================
    if ((filePntr = fopen("scnr.scan", "r"))==NULL){
        printf("Error unable to open .scan file.\n"); //if the file returns null this error is printed otherwise the
        //above statement sets the file pointer equal to the given file
    }
    //>>>>>>>>>>>>>>>>>>>>>>Before we can even begin parsing the TOKENS and LEXEME we have to build the chars into
    //>>>>>>>>>>>>>>>>>>>>>>words as we did in the scanner. Once we've built the words we can then begin parsing them
    //
     fseek(filePntr, 0, SEEK_END);
     if(isEmpty(filePntr)==1){
         printf("The .scan file is empty\n");
     }else {
         rewind(filePntr);
         reset:
         while((currentChar=fgetc(filePntr))!='.'){
             chrType = charType(currentChar);
             if(currentChar=='\n'){
                 currentChar=fgetc(filePntr);
                 fseek(filePntr, -1, SEEK_CUR);
                 goto reset;
             }
             if(currentChar!='\t'){
                 build2dArry(token, intI, intJ, currentChar, filePntr, chrType);
                 intI++; intJ=0;
             }else if(currentChar=='\t'){
                 skipTabs(currentChar);
                 currentChar=fgetc(filePntr);
                 chrType=charType(currentChar);
                 build2dArry(lexem, intA, intB, currentChar, filePntr, chrType);
                 intA++; intB=0;
             }
             totalI++;
             fseek(filePntr, -1, SEEK_CUR);
             if((testChar(currentChar,'\n')==0)){
                 lineNo++;
             }
         }
     }
    token[intA+1][0] = '.\0';
    //=================================End building chars into strings=================================================
    //===============================================Begin parser======================================================
    arryStrt = 0;
    tokn = token[arryStrt];
    lexm = lexem[arryStrt];

    beginParser();
    printf("The number of identifiers is : %d",identifSize);
}

void beginParser(){
    parseGlobal();
    parseDecDefs();
    parseProc();
    //getNextStrngArry(arryStrt);
    printf("The last token is %s",tokn);
}

void parseGlobal(){
    if(compLexTok(lexm,tokn,"GLOBAL")==1){
        return;
    }else{
        getNextStrngArry(arryStrt);
        parseConsts();
    }
}

void parseConsts(){

    if(compLexTok(lexm,tokn,"CONST")==1){
        return;
    }else{
        getNextStrngArry(arryStrt);
        parseConstLsts();
    }

}

void parseConstLsts(){
    int i = 1;
//LEFT OFF IN HERE TOO
    while(i = 1){
        i = 0;
        matchLexTok(lexm,tokn, "IDENTIF");
        identifSize++;
        identifer[arryC]=lexm;
        arryC++;
        getNextStrngArry(arryStrt);
        matchLexTok(lexm,tokn,":");
        parseConstnts("","");
        if(compLexTok(lexm,tokn,"IDENTIF")==1){
            i = 1;
        }
    }
}

void parseConstnts(char *tmpTokn1, char *tmpLexm1){ //this is where I left off...
    if(!strcmp(tokn,"CONST")){
        tmpTokn1 =tokn[arryStrt];
        if(tmpTokn1=="NUMERIC"){
            tmpTokn1="INT";
        }else if(tmpTokn1="DECIMAL"){
            tmpTokn1="REAL";
        }else{
            tmpTokn1="STRING";
        }
        tmpLexm1 = lexm[arryStrt];
    }
}

void parseDecDefs(){
    if(compLexTok(lexm,tokn,"DCL")==1){
        return;
    }else{
        getNextStrngArry(arryStrt);
        parseDecList();
    }
}

void parseDecList(){
    if(compLexTok(lexm,tokn, "IDENTIF")==1){
        return;
    }else{
        //this returns the number of unique identifiers we need to concern ourselves with
        if(!strcmp(tokn,"IDENTIF")){
            identifSize++;
            identifer[arryC]=lexm;
            arryC++;
        }
        getNextStrngArry(arryStrt);
        matchLexTok(lexm,tokn,":");
        matchLexTok(lexm,tokn,"INT");
        matchLexTok(lexm,tokn,";");
        parseDecList();
    }
}

void parseProc(){
    matchLexTok(lexm,tokn,"BEGIN");
    printBeginAsm();
    parseStatmntsLst();
    matchLexTok(lexm,tokn, "END");
    printEndAsm();
}

void parseStatmntsLst(){
    if(compLexTok(lexm,tokn,"END")==0){
        return;
    }else{
        parseIndvStatmnt();
        parseStatmntsLst();
    }
}

void parseIndvStatmnt(){
    if(compLexTok(lexm,tokn,"WRITELN")==0){
        parseWrtLne();
    }else if(compLexTok(lexm,tokn,"IDENTIF")==0){
        parseAssngmnt();
    }else{
        printf("Error in IndvStatement\n");
    }
}

void parseWrtLne(){
    int strngLen;
    char strLeng[40];
    char *tmpLexm;
    tmpLexm=lexem[arryStrt];
    matchLexTok(lexm,tokn,"WRITELN");
    matchLexTok(lexm,tokn,"(");
    parseExprsn();
    //matchLexTok(lexm,tokn,"IDENTIF");
    matchLexTok(lexm,tokn,")");
    strngLen=strlen(tmpLexm);
    sprintf(strLeng,"%d",strLeng);
    printWritLn(strLeng,tmpLexm);
    matchLexTok(lexm,tokn,";");
}

void parseAssngmnt(){
    //char is getting moved forward because this is called again this temp must be unique
    char *tmpLexm;
    tmpLexm=lexem[arryStrt];
    matchLexTok(lexm,tokn,"IDENTIF");
    matchLexTok(lexm,tokn,":=");
    parseExprsn();
    printAssngment(tmpLexm);
    matchLexTok(lexm,tokn,";");
}

void parseExprsn(){
    parseTerms();
    parseAddExprsn();
}

void parseAddExprsn(){
    char *tmpLexm;
    tmpLexm=lexem[arryStrt];
    if(strcmp(tokn,"+") && (strcmp(tokn,"-"))){
        return;
    }else{
        getNextStrngArry(arryStrt);
        parseTerms();
        printAdditionLines(tmpLexm);
        parseAddExprsn();
    }
}

void parseTerms(){
    parseFactor();
    parseAddTerms();
}

void parseAddTerms(){
    char *tmpLexm;
    tmpLexm=lexem[arryStrt];
    if(strcmp(tokn,"*") && (strcmp(tokn,"/"))){
        return;
    }else{
        getNextStrngArry(arryStrt);
        parseTerms();
        printMultiLines(tmpLexm);
        parseAddTerms();
    }
}
//ERROR IS OCCURING IN HERE============================================================================================
void parseFactor(){
    char *tmpLexm;
    tmpLexm=lexem[arryStrt];
    if(compLexTok(lexm,tokn,"IDENTIF")==0){
        printIdentifs(tmpLexm);
        getNextStrngArry(arryStrt);
    }else if(compLexTok(lexm,tokn,"NUMERIC")==0){
        printNums(tmpLexm);
        getNextStrngArry(arryStrt);
    }else{
        matchLexTok(lexm,tokn,"(");
        parseExprsn();
        matchLexTok(lexm,tokn,")");
    }
}
//=====================================================================================================================
//=====================================Function to ignore tabs=========================================================
void skipTabs(char c){
    do{
        c=fgetc(filePntr);
    }while (c=='\t');
    fseek(filePntr,-1,SEEK_CUR);
}
//=====================================================================================================================
//====================================Function to test if file is empty================================================
int isEmpty(FILE *fp){
    if(ftell(fp)==0){
        return 1; //1 is error
    }else{
        return 0; //0 is correct
    }
}
//=====================================================================================================================
//=====================================================================================================================
//=====================================Function compares the TOKEN and LEXEME==========================================
//--------This function checks to token against a passed pointer to an array. Since I create a .txt file initially I--
//--------have already handled the lexeme. The *lex variable is passed but currently unused as it doesn't seem--------
//--------necessary. This function will increment the array to the next string in the list.---------------------------
void matchLexTok(char *lex, char *tok, char *valComp){
    if(!strcmp(tok,valComp)){
        getNextStrngArry(arryStrt);
    }else{
        printf("Error in MustMatch %s & %s\n",tokn, lexm);
    }
}
//=====================================================================================================================
//=====================================Function checks to see if TOKEN and LEXEME match================================
//--------This function seems un-ncessary. Consider how I can modify the matchLexTok. This returns a 1 for false, and--
//--------0 for true.
int compLexTok(char *lex, char *tok, char *valComp){
    if(!strcmp(tok,valComp)){
        return (0);
    }else{
        return (1);
    }
}
//=====================================================================================================================
//=====================================Function gets the next string===================================================
void getNextStrngArry(int curntArr){
    tokn = token[curntArr+1];
    lexm = lexem[curntArr + 1];
    arryStrt = curntArr + 1;
}