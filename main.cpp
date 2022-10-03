#include "headers.h"

#define COMMENT 35
#define INPUT_BUF_SIZE 60
#define SYMBOL_TABLE_SIZE 100

/**
 * Splits, and Prepares Segments for the SIC Instruction from a String object.
 *
 * @param statement String to process, expects 3 words.
 * @return a pointer to a typedef struct segment.
 */
segment* prepareSegments(std::string statement) {
    auto* temp = (segment*) malloc(sizeof(segment));
    std::stringstream iss(statement);
    std::string current;
    for(int i=0;i<3;i++){
        if((i==0 && statement[0]==' ')) { continue; }
        else {
            iss >> current;
            switch(i){
                case 0:
                    temp->first=current;
                    break;
                case 1:
                    temp->second=current;
                    break;
                case 2:
                    temp->third=current;
                    break;
                default: break;
            }
        }
    }
    std::cout << std::left << std::setw(SEGMENT_SIZE) << temp->first << std::left << std::setw(SEGMENT_SIZE) << temp->second << std::left << std::setw(SEGMENT_SIZE) << temp->third << std::endl;
    return temp;
}


void performPass1(struct symbol symbolTable[], std::string filename, address* addresses) {
    std::ifstream ifs(filename);
    if(!ifs.is_open()) { displayError(FILE_NOT_FOUND,filename,-1); exit(1); }
    std::string currentLine;
    int lineNumber=0;
    while(getline(ifs,currentLine)){
        lineNumber++;
        if(currentLine[0]=='#') { continue; }
        segment* current = prepareSegments(currentLine);

        //current should be validated at this point
    }
}

int main(int argc, char* argv[]) {

    if(argc<2) { displayError(MISSING_COMMAND_LINE_ARGUMENTS,std::string("Missing Args"),-1); exit(1); }

    address addresses = { 0x00, 0x00, 0x00 };

    //Initialize the symbol table using calloc.
    auto* symbolTable = (symbol*) calloc(sizeof(struct symbol),100);

    //Perform pass 1 with given params
    performPass1(symbolTable,argv[1],&addresses);


}
