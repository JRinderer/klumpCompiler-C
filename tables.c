
#include <stdio.h>
#include <stdlib.h>

#include "tables.h"

struct varibles* varArry[SIZE];
struct varibles* dummyItem;
struct varibles* item;


//============================This function can be used universally by all table funcitons=================
int returnHash(int key){
    return (key % SIZE);
}
//=========================================================================================================
//============================These functions are all related to the symbol table==========================
//To keep this funciton and not duplicate global and local I need to determine if the variable found is a
//global or local variable. a 0 indicates global. a 1 indicates local
struct varibles *searchTable(int key, char *item, int tble){
    int index = 0;//returnHash(key);
    while(varArry[index]!= NULL){
        if(varArry[index]-> ident==item && varArry[index]->memLoc==tble){
            printf("The symbol type is %d", varArry[index]->memLoc);
            return varArry[index]->memLoc;
        }
        printf("The index is %s",varArry[index]->ident);
        ++index;
        index %= SIZE;
    }

    return (NULL);
}

void displayTest(){
    int i = 0;

    while(varArry[i]!=NULL){
        printf("you've added a variable called %s, with a type of %s and this varible is %d, and is %d, and is %d, and %d, with a key of %d\n",varArry[i]->ident,varArry[i]->type,varArry[i]->memLoc,varArry[i]->updte,varArry[i]->nameCnst,varArry[i]->cnstVal,varArry[i]->key);
        i++;
    }

    //for(i = 0; i<SIZE;i++){
    //  if(varArry[i]!=NULL){
    //    printf("you've added a variable called %s, with a type of %s and this varible is %d, and is %d, and is %d, and %d, with a key of %d\n",varArry[i]->ident,varArry[i]->type,varArry[i]->memLoc,varArry[i]->updte,varArry[i]->nameCnst,varArry[i]->cnstVal,varArry[i]->key);
    //}
    //}

}

void insertVaribles(char *ident, char *type, int memLoc, int updteble, int nmeConst, char *constVal, int key){
    struct varibles *item = (struct varibles*) malloc(sizeof(struct varibles));
    item->ident = ident;
    item->key = key;
    item->type = type;
    item->memLoc=memLoc;
    item->updte=updteble;
    item->nameCnst=nmeConst;
    item->cnstVal=constVal;


    int index = returnHash(key);

    while(varArry[index]!=NULL && varArry[index]->key!=-1){
        ++index;
        index %= SIZE;
    }
    varArry[index] = item;
    printf("The index is %s",varArry[index]->ident);
}

int returnSize(){
    int i = 0;

    while(varArry[i]!=NULL){
        i++;
    }
    return i;
}
//==========================This function populates the tables with dummy data===================================
void fillDumyData() {//Populate initial values instead of dummy data
    //Populate the variables table
    dummyItem = (struct varibles *) malloc(sizeof(struct varibles));
    dummyItem->ident = "L_INIT";
    dummyItem->type = "REAL";
    dummyItem->key = 0;
    dummyItem->memLoc = -1;
    dummyItem->updte = -1;
    dummyItem->nameCnst = -1;
    dummyItem->cnstVal = -1;
    //Populate the TypeTable
    dummyTypeItem = (struct types *) malloc(sizeof(struct types));
    dummyTypeItem->ident = "BOOL";
    dummyTypeItem->size = -1;
    dummyTypeItem->baseType = "";
    dummyTypeItem->atmStruct = -1;
}

int mainTble() {

    char *strHolder;

    int arrySize = returnSize();

    insertVaribles("TestVar", "CSTRING", 0, 0, 0, 0, arrySize);
    arrySize = returnSize();
    insertVaribles("TestVarInt", "INT", 1, 1, 0, 0, arrySize);

    strHolder = searchTable(1, "TestVar3",0);

    if (strHolder != NULL) {
        printf("The value %s already exists\n", strHolder);
    } else {
        arrySize = returnSize();
        insertVaribles("TestVar3", "INT", 1, 1, 0, 0, arrySize);
    }
    displayTest();

    return 0;
}
//================================================================================================================
//****************************************************************************************************************
//===============================These functions releate to the typeTable
