#include <ncurses.h>
#include <cstring>
#include "Menu.hpp"
#include "Display.hpp"

#define STARTCOLUMNINTERMINAL 0
#define OPTIONINMENU 3

struct MenuTypeList {
    char OptionCharacter;
    enum OptionInMenuType eOptionInMenuType;
};

struct MenuTypeList sMenuTypeList[OPTIONINMENU] {
    {1, CALC},
    {2, HELP},
    {3, QUIT}
};

enum OptionInMenuType DescribeOption(char pcString){
    for(int OptionCounter = 0; OptionCounter < OPTIONINMENU; OptionCounter++) {
        if(pcString == sMenuTypeList[OptionCounter].OptionCharacter){
            return sMenuTypeList[OptionCounter].eOptionInMenuType;
        }
    }
    return NONE;
};

enum OptionInMenuType Menu(){

    char PositionInMenu = 1;
    int MenuCharacter;

    do {
        ClearDisplay();
        curs_set(0);

        SetColor(CYAN);
        DisplayMessage("Calculator");
        ResetColor(CYAN);

        switch(PositionInMenu) {
            case 1:
                SetColor(RED);
                DisplayMessage("Start Calculator");
                ResetColor(RED);
                DisplayMessage("Enter to Help");
                DisplayMessage("Quit");
                break;
            case 2:
                DisplayMessage("Start Calculator");
                SetColor(RED);
                DisplayMessage("Enter to Help");
                ResetColor(RED);
                DisplayMessage("Quit");
                break;
            case 3:
                DisplayMessage("Start Calculator");
                DisplayMessage("Enter to Help");
                SetColor(RED);
                DisplayMessage("Quit");
                ResetColor(RED);
                break;
        }

        noecho();
        MenuCharacter = getch();

        switch (MenuCharacter) {
            case KEY_UP:
                PositionInMenu--;
                break;
            case KEY_DOWN:
                PositionInMenu++;
                break;
        }

        if(PositionInMenu < 1) {
            PositionInMenu = OPTIONINMENU;
        } else if (PositionInMenu > OPTIONINMENU) {
            PositionInMenu = 1;
        }
    }
    while (MenuCharacter != '\n' && MenuCharacter != KEY_ENTER);
    
    ClearDisplay();
    curs_set(1);

    return DescribeOption(PositionInMenu);
}
