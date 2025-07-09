#include "DecodeMessage.hpp"
#include <cmath>

#define FirstNumber 0
#define NumberInMessage 1
#define SecondNumber 2

double ComputeResult(std::string Message){
    DecodeMessage(Message);

    double result;

    int PositionOperatorInMessage = 1;

    if(TokenNumber == 3) {
        PositionOperatorInMessage = 1;
        double Number1 = (double)sMessage[FirstNumber].uWord.number;
        double Number2 = (double)sMessage[SecondNumber].uWord.number;
        
        switch (sMessage[PositionOperatorInMessage].uWord.eOp) {
        
        case ADD:
            result = Number1 + Number2;
            break;

        case SUBTRACT:
            result = Number1 - Number2;
            break;
        case MULTIPLY:
            result = Number1 * Number2;
            break;
        case DIVIDE:
            result = Number1 / Number2;
            break;
        case POWER:
            result = std::pow(Number1, Number2);
            break;

        }
    } else if(TokenNumber == 2) {
        int PositionOperatorInMessage = 0;
        double Number = (double)sMessage[NumberInMessage].uWord.number;

        switch (sMessage[PositionOperatorInMessage].uWord.eOp) {
        
        case ROOT:
            result = std::sqrt(Number); 
            break;
        }

    }

    return result;

}