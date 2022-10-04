#include "headers.h"

#define SINGLE_QUOTE 39

enum directives {
	ERROR, BYTE, END, RESB, RESW, START, WORD
};
std::string directiveArray[7] = {"ERROR","BYTE","END","RESB","RESW","START","WORD"};

int getMemoryAmount(int directiveType, std::string str) {
    return 0;
}

bool isDirective(std::string string) {
    return getDirectiveValue(string)!=-1;
}

int getDirectiveValue(std::string str){
    for(int i=0;i<7;i++){
        if(directiveArray[i] == str){
            return i;
        }
    }
    return -1;
}

bool isStartDirective(std::string str) {
    return (getDirectiveValue(str)==5);
}


