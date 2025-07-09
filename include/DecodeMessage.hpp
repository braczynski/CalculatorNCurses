#ifndef DECODEMESSAGE_HPP
#define DECODEMESSAGE_HPP

#include <string>

#define DELIMITER ' '
#define TOKENMAX 3
#define OPERATION_NUMBER 6

extern int TokenNumber;

enum op {ADD, SUBTRACT, MULTIPLY, DIVIDE, POWER, ROOT, None}; 
extern enum op eOP;

struct OperationList {
    char op;
    enum op eOP;
};

extern struct OperationList sOperationList[OPERATION_NUMBER];

union Word {
    char *FirstCharacter;
    enum op eOp;
    int number;
};

enum WordType {Operator, Number};

struct Message {
    enum WordType eWordType;
    union Word uWord;
};


extern struct Message sMessage[TOKENMAX];

void DecodeMessage(std::string Message);

#endif