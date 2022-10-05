#include "headers.h"

void displayError(int errorType,std::string errorInfo){
    displayError(errorType,errorInfo,-1);
    return;
}
void displayError(int errorType,std::string errorInfo,int line) {
    std::cout << std::setw(25) << std::left << "Error (Line: "+std::to_string(line)+")";
    switch(errorType){
        case BLANK_RECORD: {

            break;
        }
        case DUPLICATE: {

            break;
        }
        case FILE_NOT_FOUND: {
            std::cout << "File '"+errorInfo+"' doesn't exist" << std::endl;
            break;
        }
        case ILLEGAL_OPCODE_DIRECTIVE:{
            std::cout << "Illegal Opcode/Directive '"+errorInfo+"'" << std::endl;
            break;
        }
        case ILLEGAL_SYMBOL: {
            std::cout << "Illegal Symbol '"+errorInfo+"'" << std::endl;
            break;
        }
        case MISSING_COMMAND_LINE_ARGUMENTS: {
            std::cout << "Missing Command Line Arguments" << std::endl;
            break;
        }
        case OUT_OF_MEMORY: {
            std::cout << "Out of Memory.. (PLACEHOLDER)" << std::endl;
            break;
        }
        case OUT_OF_RANGE_BYTE: {
            std::cout << "Byte '"+errorInfo+"' is out of Range (00-FF)" << std::endl;
            break;
        }
        case OUT_OF_RANGE_WORD:{
            std::cout << "PLACEHOLDER OUT OF RANGE WORD" << std::endl;

            break;
        }
        default: break;
    }
    exit(1);
}