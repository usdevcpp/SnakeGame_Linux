#pragma once



class ConsoleConfig
{
private:
	

public:
	ConsoleConfig() = default;
	ConsoleConfig(const ConsoleConfig&) = delete;
	ConsoleConfig& operator=(const ConsoleConfig&) = delete;

	void SetCursorToStart();
	void CursorVisibility(bool Visible);

	void SetConsolePos(int posX, int posY, int height, int width);

	void SleepCon(int l);
};