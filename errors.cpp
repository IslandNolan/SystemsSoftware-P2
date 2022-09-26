#include "headers.h"

void displayError(int errorType,std::string errorInfo,int line) {
    std::cout << std::setw(10) << std::left << "Error (Line: "+std::to_string(line)+")";
    switch(errorType){
        case BLANK_RECORD: break;
        case DUPLICATE: break;
        case FILE_NOT_FOUND: break;
        case ILLEGAL_OPCODE_DIRECTIVE: break;
        case ILLEGAL_SYMBOL: break;
        case MISSING_COMMAND_LINE_ARGUMENTS: break;
        case OUT_OF_MEMORY: break;
        case OUT_OF_RANGE_BYTE: break;
        case OUT_OF_RANGE_WORD: break;
        default: break;
    }
}