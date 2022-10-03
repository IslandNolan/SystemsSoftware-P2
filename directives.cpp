#include "headers.h"

#define SINGLE_QUOTE 39

enum directives {
	ERROR, BYTE, END, RESB, RESW, START, WORD
};

int getMemoryAmount(int directiveType, char* string) {

}

int isDirective(std::string string) {

}

bool isStartDirective(int directiveType) {
    return START==directiveType;
}


