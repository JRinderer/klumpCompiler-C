
//
// Created by jrinder on 4/16/18.
//

#ifndef SCANNER01_TABLES_H
#define SCANNER01_TABLES_H

#include <lzma.h>

#define SIZE 400
//===================================universally available functions=================================
//returns the key based on the size
int returnHash(int);
void fillDumyData();
//===================================Support for Variable table======================================
struct varibles{
    char *ident;
    char *type;
    int memLoc;
    int updte;
    int nameCnst;
    int cnstVal;
    int key;

};

struct varibles* varArry[SIZE];
struct varibles* dummyItem;
struct varibles* item;


struct varibles *searchTable(int, char *, int);

void insertVaribles(char *, char *, int, int, int, char *, int);

void displayTest();
int returnSize();
int mainTble();

/*
======================================================================================================
//////////////////////////////////////////////////////////////////////////////////////////////////////
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
=====================================Support for Type Table===========================================
*/

struct types{
    char *ident;
    int size;
    int atmStruct;
    char *baseType;
};

struct types* typesArry[SIZE];
struct types* dummyTypeItem;
struct types* itemType;

struct types *searchTableType(int, char *);

void insertTypes(char *, int, int, char*);

struct types *searchTypeTable(int, char *);

#endif //SCANNER01_TABLES_H

