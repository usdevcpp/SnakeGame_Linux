#include<curses.h>

#include"GameMap.h"
#include"GameMap.cpp"
#include"Snake.h"
#include"Snake.cpp"
#include"Telemetry.h"
#include"Telemetry.cpp"
#include"Controls.h"

int kbhit();

int main()
{
	bool f_telemetry{ true }; //flag for active/deactive telemetry data
	bool f_gameLoop{ true }; //flag for run the game
	bool f_gameSetupLoop{ true }; //flag for run the game
	bool f_waitToStart{ true }; //flag for - press any button to start the game
	bool f_stopSnake{ false }; //flag for - stop the snake from moving

	int c{0};

	while (f_gameSetupLoop)
	{
		GameMap map{ '#' };
		Snake snake{ '*', 5 };
		Telemetry t;
		map.Map(); //initialize the game map
		map.SnakeMap(); //initialize the game map for basic snake map

		snake.InitializeSnake();
		snake.SetSnakeOnMap(map, snake);

		snake.MSG_SetPressToStart(map);
		
		initscr();
    	cbreak();
    	noecho();
   	 	clear();
 		curs_set(0);
		keypad(stdscr, true);
		nodelay(stdscr, TRUE);
		
		while (f_gameLoop)
		{
			snake.GenerateFood(map, 0);

			if(kbhit())
			{
				snake.MSG_RemovePressToStart(map);
				switch (getch())
				{
					case (KEY_W):
					case (KEY_UP):
					{
						snake.MoveSnake(map, snake, 8);
						if (snake.borderCollision() || snake.selfCollision())
						{
							f_gameLoop = false;
							f_waitToStart = true;
							break;
						}
						continue;
					}
					case (KEY_D):
					case (KEY_RIGHT):
					{
						snake.MoveSnake(map, snake, 6);
						if (snake.borderCollision() || snake.selfCollision())
						{
							f_gameLoop = false;
							f_waitToStart = true;
							break;
						}
						continue;
					}
					case (KEY_S):
					case (KEY_DOWN):
					{
						snake.MoveSnake(map, snake, 2);
						if (snake.borderCollision() || snake.selfCollision())
						{
							f_gameLoop = false;
							f_waitToStart = true;
							break;
						}
						continue;
					}
					case (KEY_A):
					case (KEY_LEFT):
					{
						snake.MoveSnake(map, snake, 4);
						if (snake.borderCollision() || snake.selfCollision())
						{
							f_gameLoop = false;
							f_waitToStart = true;
							break;
						}
						continue;
					}
					case (KEY_T):
					{
						clear();
						refresh();
						if (f_telemetry)
						{
							f_telemetry = false;
						}
						else
						{
							f_telemetry = true;
						}
						continue;
					}
					case (KEY_P):
					{
						if (f_stopSnake)
						{
							f_stopSnake = false;
						}
						else
						{
							f_stopSnake = true;
						}

						continue;
					}
					case (KEY_R):
					{
						f_gameLoop = false;

						continue;
					}
					case (KEY_Q):
					{
						f_gameSetupLoop = false;
						f_gameLoop = false;
						endwin();

						continue;
					}
					default:
					{
						continue;
					}
				}
			}

			if (f_telemetry)
			{
				t.BaseTelemetry(map,snake);
			}

			if(!f_stopSnake)
			{
				snake.MoveSnake(map, snake, snake.GetPosState());
			}

			delay_output(100);
			map.PrintMap();

			while (f_waitToStart)
			{
				if (kbhit())
				{
					f_waitToStart = false;
					break;
				}
			}
		}

		f_gameLoop = true;
		clear();
		refresh();
	}
	return 0;
}

int kbhit()
{
    int ch = getch();

    if (ch != ERR) 
	{
        ungetch(ch);
        return 1;
    } 
	else 
	{
        return 0;
    }
}
