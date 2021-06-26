#pragma once
#include <iostream>
#include <Windows.h>

class Board
{
private:
	const unsigned short BLACK = 0;
	const unsigned short WHITE = 255;
	const unsigned short LIGHT_BLUE = 187;
	const unsigned short BLUE = 17;
	const unsigned short RED = 204;
	const unsigned short GREEN = 170;
	const unsigned short DARK_GREEN = 34;
	const unsigned short PURPLE = 85;
	const unsigned short GRAY = 119;
	const unsigned short PINK = 221;
	const unsigned short YELLOW = 238;
	const unsigned short TEAL = 51;
	const unsigned short DEFAULT_COLOR = 15;

	int number_of_states = 2;
	int elements[100][100];
	int delay = 0;
	int ant_x = 50;
	int ant_y = 50;
	int rotation_rule[12]{ 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int ant_direction = 0;		//	0 - 3
	//	0 N
	//	1 E 
	//	2 S 
	//	3 W  
public:
	Board()
	{
		int i = 0;
		int j = 0;

		while (i < 100)
		{
			while (j < 100)
			{
				elements[i][j] = 0;
				j++;
			}
			j = 0;
			i++;
		}
	}

	void printWelcomeMessage()
	{
		setConsoleColour(DEFAULT_COLOR);
		std::cout << "Langton's ant (console version)" << std::endl;
		std::cout << "commands: rules, start, exit" << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}

	void writeBoard() 
	{
		setConsoleColour(DEFAULT_COLOR);
		system("cls");

		ant_x = 50;
		ant_y = 50;

		int i = 0;
		int j = 0;

		i = 0;
		j = 0;

		while (i < 100)
		{
			while (j < 100)
			{
				if (elements[i][j] == 1)
				{
					setConsoleColour(WHITE);
					std::cout << " ";
				}
				else
				{
					setConsoleColour(BLACK);
					std::cout << " ";
				}
				j++;
			}

			std::cout << std::endl;
			j = 0;
			i++;
		}
	}

	void setDelay()
	{
		int x = 0;

		std::cout << "how much added delay between ant steps? (in ms)" << std::endl;
		std::cin >> x;

		delay = x;
	}

	void run()
	{
		Sleep(delay);

		setCursorPosition(ant_x, ant_y);

		if (elements[ant_x][ant_y] == 0)//draw colour of board state
		{
			setConsoleColour(BLACK);
			std::cout << " ";
		}
		else if (elements[ant_x][ant_y] == 1)
		{
			setConsoleColour(WHITE);
			std::cout << " ";
		}
		else if (elements[ant_x][ant_y] == 2)
		{
			setConsoleColour(LIGHT_BLUE);
			std::cout << " ";
		}
		else if (elements[ant_x][ant_y] == 3)
		{
			setConsoleColour(GREEN);
			std::cout << " ";
		}
		else if (elements[ant_x][ant_y] == 4)
		{
			setConsoleColour(RED);
			std::cout << " ";
		}
		else if (elements[ant_x][ant_y] == 5)
		{
			setConsoleColour(PURPLE);
			std::cout << " ";
		}
		else if (elements[ant_x][ant_y] == 6)
		{
			setConsoleColour(BLUE);
			std::cout << " ";
		}
		else if (elements[ant_x][ant_y] == 7)
		{
			setConsoleColour(DARK_GREEN);
			std::cout << " ";
		}
		else if (elements[ant_x][ant_y] == 8)
		{
			setConsoleColour(PINK);
			std::cout << " ";
		}
		else if (elements[ant_x][ant_y] == 9)
		{
			setConsoleColour(YELLOW);
			std::cout << " ";
		}
		else if (elements[ant_x][ant_y] == 10)
		{
			setConsoleColour(TEAL);
			std::cout << " ";
		}
		else if (elements[ant_x][ant_y] == 11)
		{
			setConsoleColour(GRAY);
			std::cout << " ";
		}

		if (rotation_rule[elements[ant_x][ant_y]] == 1)//rotate ant
		{
			ant_direction -= 1;
			if (ant_direction == -1)
			{
				ant_direction = 3;
			}
		}
		else if (rotation_rule[elements[ant_x][ant_y]] == 2)
		{
			ant_direction += 1;
			if (ant_direction == 4)
			{
				ant_direction = 0;
			}
		}
		else if (rotation_rule[elements[ant_x][ant_y]] == 3)
		{
			ant_direction -= 1;
			if (ant_direction == -1)
			{
				ant_direction = 3;
			}
			ant_direction -= 1;
			if (ant_direction == -1)
			{
				ant_direction = 3;
			}
		}

		//change board state
		elements[ant_x][ant_y] += 1;
		if (elements[ant_x][ant_y] == number_of_states)
		{
			elements[ant_x][ant_y] = 0;
		}

		if (ant_direction == 0)//move ant
		{
			if (ant_y == 99)
			{
				ant_y = 0;
			}
			else ant_y += 1;
		}
		else if (ant_direction == 1)
		{
			if (ant_x == 99)
			{
				ant_x = 0;
			}
			else ant_x += 1;
		}
		else if (ant_direction == 2)
		{
			if (ant_y == 0)
			{
				ant_y = 99;
			}
			else ant_y -= 1;
		}
		else if (ant_direction == 3)
		{
			if (ant_x == 0)
			{
				ant_x = 99;
			}
			else ant_x -= 1;
		}
	}

	void setRules()
	{
		int input = 0;

		std::cout << "how many different board states? (2-12)" << std::endl;

		while ((input != 2) && (input != 3) && (input != 4) && (input != 5) && (input != 6) && (input !=7 ) && (input != 8) && (input!=9) && (input != 10) && (input != 11) && (input != 12))
		{
			std::cin >> input;
		}
		number_of_states = input;
		input = 0;

		int i = 0;
		while(i < number_of_states)
		{
			std::cout << "set rule nr. " << i << std::endl;
			std::cout << "1. rotate left 2. rotate right 3. rotate 180 4. move forward" << std::endl;
			std::cin >> input;			
			rotation_rule[i] = input;
			input = 0;
			i++;
		}
		std::cout << "done." << std::endl;
	}

private:
	void setCursorPosition(int x, int y)
	{
		static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout.flush();
		COORD coord = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition(hOut, coord);
	}

	void const setConsoleColour(unsigned short colour)
	{
		static HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout.flush();
		SetConsoleTextAttribute(hOut, colour);
	}
};