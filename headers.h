#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#define NAME_SIZE 7

enum errors {
	BLANK_RECORD, DUPLICATE, FILE_NOT_FOUND, ILLEGAL_OPCODE_DIRECTIVE, ILLEGAL_SYMBOL,
	MISSING_COMMAND_LINE_ARGUMENTS, OUT_OF_MEMORY, OUT_OF_RANGE_BYTE, OUT_OF_RANGE_WORD
};

typedef struct address
{
	int start;
	int current;
	int increment;
} address;

typedef struct segment {
	std::string first;
	std::string second;
	std::string third;
} segment;

typedef struct symbol {
	std::string name;
	int address=0x00;
    struct symbol* next=nullptr;
} symbol;

// directives.c functions
int getMemoryAmount(int directiveType, std::string string);
bool isDirective(std::string str);
int getDirectiveValue(std::string str);
bool isStartDirective(std::string str);

// errors.c functions
void displayError(int errorType, std::string errorInfo,int lineNumber);
void displayError(int errorType, std::string errorInfo);

// opcodes.c functions
int getOpcodeValue(std::string opcode);
bool isOpcode(std::string string);

// symbols.c functions
int computeHash(std::string str);
void checkDuplicates(struct symbol symbolTable[],struct segment* current);
void displaySymbolTable(struct symbol symbolTable[]);
void insertSymbol(struct symbol symbolTable[], const std::string& symbolName, int symbolAddress);
