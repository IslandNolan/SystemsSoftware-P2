# SystemsSoftware-P2 - Fall 2022

## Symbol Table - SIC Assembler Pass 1: 


### Project Description:
This project records and creates Symbols for Stage 1 of compiling a SIC File.
Symbols are created, and memory addresses are generated based on the file provided. After Addresses, and the contents of Directive/Opcodes
have been verified, the Symbol is created, and recorded in a Symbol Table (A Chained HashTable)

The Symbols can be inserted in two ways:
 - A Root Element, or-
 - A Chained Element

A root element is an element that is first in any particular table location. It does not rely on a link for its location.
A Chained Element relies on a separate element. The Chained Element is linked to a root element. An example of this is a LinkedList.

There are multiple internal changes done to this project. They are listed below:

- Text Formatting
- Removal of several unused #defines
- Inclusion of new methods/tweaks to exiting structures.
- Removal of several #includes, they are no longer needed.
- Removal of the initializeSymbolTable method. This is accomplished with calloc instead.
- Changes to several pre-defined methods including their return types, and parameters.

<br/>

## Experiences:

I had no trouble completing the project within the specified amount of time.


## Shortcomings:

This project has no shortcomings.

## Improvements:

I feel that the project is adequate in instruction, and provided material. No changes are required.

## Compile Instructions:

Required Dependencies:

- Cmake
- G++
- Glibc
- Ninja


To Compile:

- Navigate to the root of the project, and run:
- ```sudo cmake . && make```

The project expects at a minimum ONE argument, which is the file you wish to parse. Any other parameters after the first will be ignored.

**You may need to clear the Cmake Build Cache for the previous build in order for this to successfully compile.**

