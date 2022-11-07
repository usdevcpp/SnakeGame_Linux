

#include "TerminalConfig.h"


void TerminalConfig::SetCursorToStart()
{
    move(0, 0);
}

void TerminalConfig::CursorVisibility(bool Visible)
{
	curs_set(Visible);
}

void TerminalConfig::SetConsolePos(int posX, int posY, int height, int width)
{
	
}

void TerminalConfig::SleepCon(int l)
{
	
}
