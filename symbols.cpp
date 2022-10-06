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
void printSymbol(struct symbol s, std::string index){
    if(s.name.empty()) { return; }
    std::cout << std::left << std::setw(7) << index << std::left << std::setw(10) << s.name << std::right << std::setw(6) << s.address << std::endl;
}
void displaySymbolLink(struct symbol s, int index){
    //Re-used code from p1
    printSymbol(s,std::to_string(index));
    struct symbol* pt = s.next;
    while(pt!=nullptr){
        printSymbol(*pt, "|");
        pt = pt->next;
    }
}
void displaySymbolTable(struct symbol symbolTable[]) {
    std::cout << "Symbol Table Contents\n"
                 "---------------------" << std::endl;
    std::cout << "Index  Name      Address\n"
                 "-----  ------    -------" << std::endl;


    for(int i=0;i<SYMBOL_TABLE_SIZE;i++) {
        displaySymbolLink(symbolTable[i],i);
    }
}

void insertSymbol(struct symbol symbolTable[], const std::string& symbolName, const std::string& symbolAddress) {
    int instructionHash = computeHash(symbolName);
    auto* newSymbol = (symbol*) malloc(sizeof(struct segment));
    newSymbol->name = symbolName;
    newSymbol->address = symbolAddress;
    if(symbolTable[instructionHash].name.empty()){
        symbolTable[instructionHash] = *newSymbol;
    }
    else {
        struct symbol* next = symbolTable[instructionHash].next;
        while(next!=nullptr){
            next = next->next;
        }
        symbolTable[instructionHash].next = newSymbol;
    }
    std::cout << std::left << std::setw(30) << "Inserted Symbol '"+symbolName+"'" << "Index: " << computeHash(symbolName) << std::endl;
}