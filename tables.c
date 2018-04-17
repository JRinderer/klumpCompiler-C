//
// Created by jrinder on 4/16/18.

#include "tables.h"

int insertVarbleTble(char *ident, char *type, int local, int constVar, char *constVal){
    int exst=0;
    int count=0;
    exst = searchVarbleTble(ident);
    if (exst = 0){
        varible[count] = ident;
        count++;
        return (1);
    }else{
        return (0);
    }

}

int searchVarbleTble(char * ident){

}



//

