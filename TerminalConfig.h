#pragma once

#include<curses.h>
#include<stdlib.h>

class TerminalConfig
{
private:

    WINDOW* win;

	int m_x{};
    int m_y{};

	const bool m_curShow{ true };

public:
	TerminalConfig() = default;
	TerminalConfig(const TerminalConfig&) = delete;
	TerminalConfig& operator=(const TerminalConfig&) = delete;

	void SetCursorToStart();
	void CursorVisibility(bool Visible);

	void SetConsolePos(int posX, int posY, int height, int width);

	void SleepCon(int l);
};