#include <cstdlib>
#include <cstring>
#include "DecodeMessage.hpp"

enum MessageState {Delimiter, Token} eMessageState;

int TokenNumber = 0;

enum op eOP = None;

struct OperationList sOperationList[OPERATION_NUMBER] {
    {'+', ADD},
    {'-', SUBTRACT},
    {'*', MULTIPLY},
    {'/', DIVIDE},
    {'^', POWER},
    {'s', ROOT}
};

struct Message sMessage[TOKENMAX];

int DescrypeMessage(std::string Message) {
    eMessageState = Delimiter;
    TokenNumber = 0;

    for(int CharacterCounter = 0;;CharacterCounter++) {
        switch(eMessageState){

        case Delimiter:

            if(CharacterCounter >= Message.length()) {
                return TokenNumber;
            } else if(Message[CharacterCounter] != DELIMITER) {
                sMessage[TokenNumber].uWord.FirstCharacter = &Message[CharacterCounter];
                TokenNumber++;
                eMessageState = Token;
            }
            break;

        case Token:
            
            if(CharacterCounter >= Message.length()) {
                return TokenNumber;
            } else if(Message[CharacterCounter] == DELIMITER) {
                eMessageState = Delimiter;
            }
            break;
        }
    }

}

bool IsNumber(char *pcString) {
    if((*pcString) >= '0' && (*pcString) <= '9') {
        return true;
    }

    return false;
}

enum op DescribeOperation(char *pcString){
    for(int OperationCounter = 0; OperationCounter < OPERATION_NUMBER; OperationCounter++) {
        if(!(strcmp(pcString, &sOperationList[OperationCounter].op))){
            return sOperationList[OperationCounter].eOP;
        }
    }
    return None;
};

void MessageType() {
    for(int MessageCounter = 0; MessageCounter < TokenNumber; MessageCounter++) {
        if(IsNumber(sMessage[MessageCounter].uWord.FirstCharacter)) {
            sMessage[MessageCounter].eWordType = Number;
            sMessage[MessageCounter].uWord.number = std::atoi(sMessage[MessageCounter].uWord.FirstCharacter);
        } else {
            sMessage[MessageCounter].eWordType = Operator;
            sMessage[MessageCounter].uWord.eOp = DescribeOperation(sMessage[MessageCounter].uWord.FirstCharacter);
        }
    }
}

void ReplaceCharacter(char *pcString,char OldCharacter, char NewCharacter){
    int length = std::strlen(pcString);

    for(int CharacterCounter = 0; CharacterCounter < length; CharacterCounter++) {
        if(pcString[CharacterCounter] == OldCharacter) {
            pcString[CharacterCounter] = NewCharacter;
        }

    }
}

void DscMessage(){
    for(int MessageCounter = 0; MessageCounter < TokenNumber; MessageCounter++) {
        ReplaceCharacter(sMessage[MessageCounter].uWord.FirstCharacter,' ', '\0');    
    }
}

void DecodeMessage(std::string Message){
    DescrypeMessage(Message);
    DscMessage();
    MessageType();
}