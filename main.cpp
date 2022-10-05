#include "headers.h"

#define SYMBOL_TABLE_SIZE 100

using namespace std;

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
    std::cout << std::left << std::setw(SEGMENT_SIZE) << temp->first << std::left << std::setw(SEGMENT_SIZE) << temp->second << std::left << std::setw(SEGMENT_SIZE) << temp->third;
    return temp;
}


void performPass1(struct symbol symbolTable[], std::string filename, address* addresses) {
    std::ifstream ifs(filename);
    if(!ifs.is_open()) { displayError(FILE_NOT_FOUND,filename); exit(1); }
    std::string currentLine;
    int lineNumber=0;
    while(getline(ifs,currentLine)) {
        lineNumber++;
        if (currentLine[0] == '#') { continue; }
        if (currentLine[0] < 32) {
            displayError(BLANK_RECORD,"",lineNumber);
            continue;
        }
        segment *current = prepareSegments(currentLine);

        if(isDirective(current->first) || isOpcode(current->first)) {
            displayError(ILLEGAL_SYMBOL,current->first,lineNumber);
        }
        else if(isDirective(current->second)) {
            if(isStartDirective(current->second)){
                addresses->start = "0x"+current->third;
                addresses->current = "0x"+current->third;
                cout << endl;
                continue;
            }
            else {
                int numBytes = getMemoryAmount(getDirectiveValue(current->second),current->third);
                addresses->increment = toHex(to_string(numBytes));
            }
        }
        else if(isOpcode(current->second)) {
            addresses->increment = toHex(to_string(3));
        }
        else{
            displayError(ILLEGAL_OPCODE_DIRECTIVE,current->second,lineNumber);
        }
        int newValue = (stoi(toDec(addresses->current)) + stoi(toDec(addresses->increment)));
        addresses->current = toHex(to_string(newValue));
        //cout << "{" << addresses->start+" "<< addresses->current+" "<<addresses->increment+"}" << std::endl;


        //If all these pass, then make sure the first segment is not blank.
        //If it is not blank, then insert the symbol into the table.
        //Increment current address value by the thing stored in increment


    }

    //IMPORTANT: MAKE SURE TO CLOSE THE FILE AFTER READING - IMPORTANT FOR P3
    ifs.close();


    //Print Statistics
    std::cout << "\n\nAssembly Summary - "+filename+"\n----------------\n"
              << setw(20) << "Starting Address: " << addresses->start << endl
              << setw(20) << "Ending Address:  "<< addresses->current << endl
              << setw(20) << "Size (bytes):  " << (stoi(toDec(addresses->current))-stoi(toDec(addresses->start))) << endl;

}

int main(int argc, char* argv[]) {

    if(argc<2) { displayError(MISSING_COMMAND_LINE_ARGUMENTS,std::string("Missing Args"),-1); exit(1); }

    //Used for important addresses. Start of program, current, and what to increment by
    address addresses = { "", "", "" };

    //Initialize the symbol table using calloc.
    auto* symbolTable = (symbol*) calloc(sizeof(struct symbol),100);

    //Perform pass 1 with given params
    performPass1(symbolTable,argv[1],&addresses);


}
