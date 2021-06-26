#include <iostream>
#include <Windows.h>

#include "Board.h"

std::string get_input()
{
   std::string input = "";

    while ((input != "start") && (input != "exit") && (input!= "rules"))
    {
        std::cin >> input;
    }
    return input;
}

int main()
{
    int i = 0;
    std::string input = "";

    Board* board = new Board();
    board->printWelcomeMessage();

    do
    {
        input = get_input();
        if (input == "start")
        {
            board->setDelay();
            board->writeBoard();
            while (i<50000)
            {
                board->run();
                i++;
            }
        }
        else if (input == "rules")
        {
            board->setRules();
        }
        else if (input == "exit")
        {
            exit(0);
        }
    } while ((input != "exit") && (input != "start"));

    getchar();
    getchar();
    return 0;
}