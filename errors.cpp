#include "headers.h"

void displayError(int errorType,std::string errorInfo){
    displayError(errorType,errorInfo,-1);
    exit(1);
}
void displayError(int errorType,std::string errorInfo,int line) {
    std::cout << std::setw(25) << std::left << "\n\nError (Line: "+std::to_string(line)+")";
    switch(errorType){
        case BLANK_RECORD: {
            std::cout << "Blank Record" << std::endl;
            break;
        }
        case DUPLICATE: {
            std::cout << "Duplicate Entry '"+errorInfo+"'" << std::endl;
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
            std::cout << "Address '"+errorInfo+"' exceeds maximum memory address (0x8000)" << std::endl;
            break;
        }
        case OUT_OF_RANGE_BYTE: {
            std::cout << "Byte '"+errorInfo+"' is out of Range (00 - FF)" << std::endl;
            break;
        }
        case OUT_OF_RANGE_WORD:{
            std::cout << "Word '"+errorInfo+"' is out of Range (-16,777,216 - 16,777,215)" << std::endl;
            break;
        }
        default: break;
    }
}