#include <ncurses.h>
#include "Display.hpp"

int rowMax, columnMax;
int CurrentRow = 0;

std::string ReadString() {

    char buffer[100];
    std::string Message;

    echo();
    getstr(buffer);
    noecho();

    clear();

    return Message = buffer;
}

void DisplayMessage(std::string Message) {

    mvprintw(CurrentRow, (columnMax/2) - (Message.size()/2), "%s" ,Message.c_str());

    if(CurrentRow < rowMax){
        CurrentRow++;
    }
}

void DisplayMessage(double Message) {

    std::string strMessage = std::to_string(Message);
    mvprintw(CurrentRow, (columnMax/2) - (strMessage.size()/2), "%s" ,strMessage.c_str());

    if(CurrentRow < rowMax){
        CurrentRow++;
    }
}

void AddToHistory(std::string Message, std::deque<std::string> *History) {

    if (History->size() < (rowMax - 4))
    {
        History->push_front(Message);
    } else {
        History->pop_back();
        History->push_front(Message);
    }

}

void DisplayHistory(std::deque<std::string> History) {

    for (int MessageCounter = 0; MessageCounter < History.size(); MessageCounter++)
    {
        DisplayMessage(History[MessageCounter]);
    }
    
}

void InitColors() {

    if (has_colors() == TRUE) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6, COLOR_CYAN, COLOR_BLACK);
    } else {
        printw("Your terminal does not support colors.");
    }
}

void InitDisplay() {

    initscr();
    keypad(stdscr, TRUE);
    InitColors();

    getmaxyx(stdscr, rowMax, columnMax);
}

void EndDisplay() {

    endwin();
}

void SetColor(enum ColorPair eColorPair) 
{   
    switch (eColorPair)
    {
    case RED:
        attron(COLOR_PAIR(1));
        break;
    case GREEN:
        attron(COLOR_PAIR(2));
        break;
    case YELLOW:
        attron(COLOR_PAIR(3));
        break;
    case BLUE:
        attron(COLOR_PAIR(4));
        break;
    case MAGENTA:
        attron(COLOR_PAIR(5));
        break;
    case CYAN:
        attron(COLOR_PAIR(6));
        break;
    
    default:
        break;
    }
}

void ResetColor(enum ColorPair eColorPair) {
        switch (eColorPair)
    {
    case RED:
        attroff(COLOR_PAIR(1));
        break;
    case GREEN:
        attroff(COLOR_PAIR(2));
        break;
    case YELLOW:
        attroff(COLOR_PAIR(3));
        break;
    case BLUE:
        attroff(COLOR_PAIR(4));
        break;
    case MAGENTA:
        attroff(COLOR_PAIR(5));
        break;
    case CYAN:
        attroff(COLOR_PAIR(6));
        break;
    
    default:
        break;
    }
}

void ClearDisplay() {
    CurrentRow = 0;

    clear();
}
