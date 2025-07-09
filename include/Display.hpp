#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>
#include <deque>

extern int CurrentRow;

std::string ReadString();

void DisplayMessage(std::string Message);
void DisplayMessage(double Message);

void AddToHistory(std::string Message, std::deque<std::string> *History);
void DisplayHistory(std::deque<std::string> History);

void InitDisplay();
void EndDisplay();

enum ColorPair {
    RED = 1,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN
};

void SetColor(enum ColorPair eColorPair);
void ResetColor(enum ColorPair eColorPair);

void ClearDisplay();

#endif