#include "Telemetry.h"

void Telemetry::BaseTelemetry(GameMap& map, Snake& snake)
{
	auto p_map{ &map };
	auto p_snake{ &snake };

	printw("-----------------------------------------------\n");
	printw("snake size:%lu\n",p_snake->GetSnake()->size() - 1);
	printw("food location: (%d,%d)\n",p_snake->GetFoodX(), p_snake->GetFoodY());
	printw("Head: (%d,%d)\n",p_map->GetMemX(), p_map->GetMemY());
	printw("-Snake's POV (front, right, head, left, back)-\n");
	printw("  %c\n%c %c %c\n  %c\n",p_map->GetCurrentChar_Upper(), p_map->GetCurrentChar_Left(), p_map->GetCurrentChar(), p_map->GetCurrentChar_Right(), p_map->GetCurrentChar_Lower());
	printw("-memory position-\n");
	printw("size: (%lu,%lu)\n", p_snake->GetMemXpos()->size(), p_snake->GetMemYpos()->size());
	printw("x=");
	print_vec(p_snake->GetMemXpos());
	printw("\n");
	printw("y=");
	print_vec(p_snake->GetMemYpos());
	printw("\n");
	printw("position state: ");
	if (p_snake->GetPosState() == 8) printw("up");
	if (p_snake->GetPosState() == 6) printw("right");
	if (p_snake->GetPosState() == 2) printw("down");
	if (p_snake->GetPosState() == 4) printw("left");
	printw("\n-----------------------------------------------");
}