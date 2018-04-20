/*
//
// Created by jrinder on 4/16/18.
//

#ifndef SCANNER01_TABLES_H
#define SCANNER01_TABLES_H

#include <lzma.h>

#define SIZE 400
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

//returns the key based on the size
int returnHash(int);

struct varibles *searchTable(int, char *);

void insertVaribles(char *, char *, int, int, int, int, int);

void displayTest();
int returnSize();
*/
/*
======================================================================================================
//////////////////////////////////////////////////////////////////////////////////////////////////////
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
=====================================Support for Type Table===========================================
*//*

struct types{
    char *ident;
    int size;
    int atmStruct;
    char *baseType;
};

struct types* typesArry[SIZE];
struct types* dummyTyppeItem[SIZE];
struct types* itemType[SIZE];

struct types *searchTableType(int, char *);

void insertTypes(char *, int, int, char*);

#endif //SCANNER01_TABLES_H
*/
