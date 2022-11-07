#include<curses.h>
#include<iostream>



void SetCursorToStart()
{
    //WINDOW *my_win;
    //int y, x;
    move (0,0);

    //setsyx(y,x);
}

int main()
{
    int i{0};
    
    initscr();
    cbreak();
    clear();
    curs_set(0);

    move(10,10);
    addch('g');

    /*
    while (i<5)
    {
        

        SetCursorToStart();
        print();
        ++i;
    }
    */

   getch();
   endwin();
    return 0;
}