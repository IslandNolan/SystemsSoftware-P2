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
std::string toDec(std::string hexVal){
    int value;
    std::stringstream ss;
    ss << std::hex << hexVal;
    ss >> value;
    return std::to_string(value);
}
std::string toHex(std::string decVal){
    std::stringstream ss;
    ss << "0x" << std::hex << stoi(decVal);
    return ss.str();
}

void displaySymbolTable(struct symbol symbolTable[]) {
    //Do this later
}

void insertSymbol(struct symbol symbolTable[], char symbolName[], int symbolAddress) {
    //Later
}