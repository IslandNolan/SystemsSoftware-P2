#include "headers.h"

#define MOD_SIZE 10
#define SYMBOL_TABLE_SEGMENTS 10
#define SYMBOL_TABLE_SIZE 100

int computeHash(std::string symbolName) {
    int sum=0;
    for(char c : symbolName){
        sum+=c;
    }
    return sum%SYMBOL_TABLE_SIZE;
}

void displaySymbolTable(struct symbol symbolTable[]) {
    //Do this later
}

void insertSymbol(struct symbol symbolTable[], char symbolName[], int symbolAddress) {
    //Later
}