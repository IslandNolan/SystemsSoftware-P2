#include "headers.h"

#define SYMBOL_TABLE_SIZE 100

using namespace std;

/**
 * @author Nolan Boner - N01440422
 * Splits, and Prepares Segments for the SIC Instruction from a standard String object.
 * Note: Ignores any tokens after the 3rd.
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
    return temp;
}

/**
 * Perform the SIC Assembly Pass 1 on the specified file using the declared objects.
 * @param symbolTable Reference to table to use.
 * @param filename File to parse
 * @param addresses Current Addresses for the instruction
 */
void performPass1(struct symbol symbolTable[], std::string filename, address* addresses) {
    cout << "\nSymbol Table Log\n----------------" << std::endl;
    std::ifstream ifs(filename);
    if(!ifs.is_open()) { displayError(FILE_NOT_FOUND,filename); exit(1); }
    std::string currentLine;
    int lineNumber=0;
    while(getline(ifs,currentLine)) {
        lineNumber++;
        if (currentLine[0] == '#') { continue; }
        if (currentLine[0] < 32) {
            displayError(BLANK_RECORD,"",lineNumber);
            exit(1);
        }
        segment *current = prepareSegments(currentLine);

        if(isDirective(current->first) || isOpcode(current->first)) {
            displayError(ILLEGAL_SYMBOL,current->first,lineNumber);
            exit(1);
        }
        else if(isDirective(current->second)) {
            if(isStartDirective(current->second)){
                addresses->start = "0x"+current->third;
                addresses->current = "0x"+current->third;
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
            exit(1);
        }
        int newValue = (stoi(toDec(addresses->current)) + stoi(toDec(addresses->increment)));
        if(newValue> stoi(toDec("0x8000"))) { displayError(OUT_OF_MEMORY, toHex(to_string(newValue)),lineNumber); exit(1); }

        if(!current->first.empty()) {
            checkDuplicates(symbolTable,current);
            insertSymbol(symbolTable,current->first,addresses->current);
        }
        addresses->current = toHex(to_string(newValue));
    }
    std::cout << std::endl;
    displaySymbolTable(symbolTable);

    ifs.close();


    std::cout << "\n\nAssembly Summary - "+filename+"\n----------------\n"
              << setw(20) << "Starting Address: " << addresses->start << endl
              << setw(20) << " Ending Address:  "<< addresses->current << endl
              << setw(20) << " Size (bytes):  " << (stoi(toDec(addresses->current))-stoi(toDec(addresses->start))) << endl;

}

int main(int argc, char* argv[]) {

    if(argc<2) { displayError(MISSING_COMMAND_LINE_ARGUMENTS,std::string("Missing Args"),-1); exit(1); }
    address addresses = { "", "", "" };

    auto* symbolTable = (symbol*) calloc(sizeof(struct symbol),100);

    performPass1(symbolTable,argv[1],&addresses);
}
