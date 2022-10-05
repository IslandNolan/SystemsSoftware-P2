#include "headers.h"

enum directives {
	ERROR, BYTE, END, RESB, RESW, START, WORD
};
std::string directiveArray[7] = {"ERROR","BYTE","END","RESB","RESW","START","WORD"};

int getMemoryAmount(int directiveType, std::string str) {
    switch(directiveType){
        case BYTE: {
            if(str.find('X')!=std::string::npos) {
                str.erase(0,2);
                str.erase(str.size()-1,1);
                int dec = stoi(toDec(str));
                if(dec<0 || dec>255) { displayError(OUT_OF_RANGE_BYTE,str); }
                return 1;
            }
            else if(str.find('C')!=std::string::npos){
                str.erase(0,2);
                str.erase(str.size()-1,1);
                return str.size();
            }
            else return stoi(str);
        }
        case END:
        case START:
            return 0;
        case RESB:{
            return stoi(str);
        }
        case RESW:{
            return 3*stoi(str);
        }
        case WORD:{
            if(stoi(str)<-16777216 || std::stoi(str)>16777215) {
                displayError(OUT_OF_RANGE_WORD,str);
            } else return 3;
        }
    }


    return 0;
}

bool isDirective(std::string str) {
    return getDirectiveValue(str)!=-1;
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


