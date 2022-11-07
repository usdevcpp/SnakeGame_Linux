#include "Telemetry.h"

void Telemetry::BaseTelemetry(GameMap& map, Snake& snake)
{

	auto p_map{ &map };
	auto p_snake{ &snake };

	std::ostream& operator<<(std::ostream & os, const std::vector<int>&v);

	std::cout << "snake size:" << p_snake->GetSnake()->size() - 1 << "     \n";
	std::cout << "food location: " << "(" << p_snake->GetFoodX() << "," << p_snake->GetFoodY() << ")" << "     \n";
	std::cout << "Head: " << "(" << p_map->GetMemX() << "," << p_map->GetMemY() << ")" << "     "; // << "currect char:" << GameMap::GetCurrentChar();

	std::cout << "\n" << "-------------------------------------------------------" << "\n";

	std::cout << "-Snake's POV (front, right, head, left, back)-" << "\n";
	std::cout << "  " << p_map->GetCurrentChar_Upper() << "\n" <<
		p_map->GetCurrentChar_Left() << " " << p_map->GetCurrentChar() << " " << p_map->GetCurrentChar_Right() << "\n" <<
		"  " << p_map->GetCurrentChar_Lower();

	std::cout << "\n" << "-------------------------------------------------------" << "\n";
	std::cout << "-memory position-" << "\n";
	std::cout << "size: " << "(" << p_snake->GetMemXpos()->size() << "," << p_snake->GetMemYpos()->size() << ")" << "     \n";
	std::cout << "x= " << p_snake->GetMemXpos()[0] << " ";
	std::cout << "\ny= " << p_snake->GetMemYpos()[0] << " \n";
	std::cout << "position state: ";
	if (p_snake->GetPosState() == 8) std::cout << "up   ";
	if (p_snake->GetPosState() == 6) std::cout << "right";
	if (p_snake->GetPosState() == 2) std::cout << "down ";
	if (p_snake->GetPosState() == 4) std::cout << "left ";
	std::cout << "\n";
	std::cout << "-------------------------------------------------------" << "\n";

}
