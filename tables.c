/*
#include <stdio.h>
#include <stdlib.h>

#include "tables.h"

struct varibles* varArry[SIZE];
struct varibles* dummyItem;
struct varibles* item;


int returnHash(int key){
    return (key % SIZE);
}

struct varibles *searchTable(int key, char *item){
    int index = 0;//returnHash(key);
    while(varArry[index]!= NULL){
        if(varArry[index]-> ident==item){
            return varArry[index]->ident;
        }
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

void insertVaribles(char *ident, char *type, int memLoc, int updteble, int nmeConst, int constVal, int key){
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
}

int returnSize(){
    int i = 0;

    while(varArry[i]!=NULL){
        i++;
    }
    return i;
}

int main() {
    dummyItem = (struct varibles*) malloc(sizeof(struct varibles));
    dummyItem->ident = "test";
    dummyItem->type = "test";
    dummyItem->key = -1;
    dummyItem->memLoc = -1;
    dummyItem->updte = -1;
    dummyItem->nameCnst = -1;
    dummyItem->cnstVal = -1;
    char *strHolder;

    int arrySize = returnSize();

    insertVaribles("TestVar","CSTRING",0,0,0,0,arrySize);
    arrySize = returnSize();
    insertVaribles("TestVarInt","INT",1,1,0,0,arrySize);

    strHolder = searchTable(1,"TestVar3");

    if(strHolder!=NULL) {
        printf("The value %s already exists\n",strHolder);
    }else{
        arrySize = returnSize();
        insertVaribles("TestVar3","INT",1,1,0,0,arrySize);
    }
    displayTest();

    return 0;
}*/
