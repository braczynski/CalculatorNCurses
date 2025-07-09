#include <ncurses.h>
#include "DecodeMessage.hpp"
#include "RunOperator.hpp"
#include "Display.hpp"
#include "Menu.hpp"


int main() {

    InitDisplay();

    char EndCharacter;

    std::string operation;
    std::deque<std::string> history;
    enum OptionInMenuType Option;
    double result;

    do
    {
        Option = Menu();

        switch (Option) {
        
        case CALC:
            operation = ReadString();

            DisplayMessage(operation);

            result = ComputeResult(operation);

            DisplayMessage(result);

            AddToHistory((operation + " = " + std::to_string(result)), &history);
            DisplayHistory(history);
            
            break;
        case HELP:
            DisplayMessage("Avaible Operations:\n");
            DisplayMessage("1. Add - +\n");
            DisplayMessage("2. Subtract - -\n");
            DisplayMessage("3. Multiply - *\n");
            DisplayMessage("4. Divide - /\n");
            DisplayMessage("5. Power - ^\n");
            DisplayMessage("6. Root - s\n");
            DisplayMessage("Example 2 + 2\n");

            break;
        case QUIT:

            EndDisplay();
            return 0;
            break;
        }

        DisplayMessage("Press any key to go to menu or Q to quit");
            
        EndCharacter = getch();

        if(EndCharacter == 'Q') {
            Option = QUIT;
        } else {
            CurrentRow = 0;
        }

    } while (Option != QUIT);

    EndDisplay();
    return 0;
}

// wyczyscic kod