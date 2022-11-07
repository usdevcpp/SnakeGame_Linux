#include "Snake.h"

Vec<char>* Snake::GetSnake()
{
    Vec<char>* p{ &m_snake };
    return p;
}

void Snake::InitializeSnake()
{
    for (int i{ 0 };i < m_initialSize;++i)
    {
        if (i < m_initialSize - 1)
        {
            Snake::GetSnake()->push_back(m_snake_look);
        }
        if (i == m_initialSize - 1)
        {
            Snake::GetSnake()->push_back(' ');
        }
    }
}

void Snake::SetSnakeOnMap(GameMap& map, Snake& snake)//GameMap& map, int x, int y, Snake& snake)
{
    auto p_map{ &map };
    auto p_snake{ &snake };
    auto snake_size{ static_cast<int>(p_snake->m_snake.size()) };

    for (int i{ 0 };i < snake_size;++i)
    {
        if (i == 0)
        {
            p_map->SetCharInMap(p_map->GetMemX(), p_map->GetMemY(), p_snake->m_snake[i]);
            m_memXpos.push_back(p_map->GetMemX());
            m_memYpos.push_back(p_map->GetMemY());
        }
        if (i!=0 && i < snake_size)
        {
            p_map->SetCharInMap(p_map->GetMemX() + i, p_map->GetMemY(), p_snake->m_snake[i]);
            m_memXpos.push_back(p_map->GetMemX() + i);
            m_memYpos.push_back(p_map->GetMemY());
        }
    }

    //Snake::MSG_SetPressToStart(map);
}

char Snake::GetSnakeLook()
{
    return m_snake_look;
}

void Snake::SetPosState(int posState)
{
    m_posState = posState;
}

int Snake::GetPosState()
{
    return m_posState;
}

void Snake::MoveSnake(GameMap& map, Snake& snake, int mov_pos)
{
    auto p_map{ &map };
    auto p_snake{ &snake };
    auto snake_size{ static_cast<int>(p_snake->m_snake.size()) };
    auto map_currectChar{ p_map->GetCurrentChar() };
    auto map_memX_temp{ p_map->GetMemX()};
    auto map_memY_temp{ p_map->GetMemY()};

    if (mov_pos == 8 && m_posState !=2)
    {
        p_snake->GenerateFood(map, Snake::SnakeEat(map, 8));
        p_snake->SnakeGrowth(snake, map, Snake::SnakeEat(map, 8));
        p_snake->CheckCollision(map, snake, 8);

        map.SetMemY(-1);
        
        UpdateMemPos(map, 8);
        for (int i{ 0 };i < static_cast<int>(p_snake->m_snake.size());++i)
        {
            p_map->SetCharInMap(p_snake->GetMemXpos()->at(i), p_snake->GetMemYpos()->at(i), m_snake[i]);
        }
        
        SetPosState(8);
    }
    if (mov_pos == 6 && m_posState != 4)
    {
        p_snake->GenerateFood(map, Snake::SnakeEat(map, 6));
        p_snake->SnakeGrowth(snake, map, Snake::SnakeEat(map, 6));
        p_snake->CheckCollision(map, snake, 6);

        map.SetMemX(+1);
        
        UpdateMemPos(map, 6);
        for (int i{ 0 };i < snake_size;++i)
        {
            p_map->SetCharInMap(p_snake->GetMemXpos()->at(i), p_snake->GetMemYpos()->at(i), m_snake[i]);
        }

        SetPosState(6);
    }
    if (mov_pos == 2 && m_posState != 8)
    {
        p_snake->GenerateFood(map, Snake::SnakeEat(map, 2));
        p_snake->SnakeGrowth(snake, map, Snake::SnakeEat(map, 2));
        p_snake->CheckCollision(map, snake, 2);

        map.SetMemY(+1);
        
        UpdateMemPos(map, 2);
        for (int i{ 0 };i < snake_size;++i)
        {
            p_map->SetCharInMap(p_snake->GetMemXpos()->at(i), p_snake->GetMemYpos()->at(i), m_snake[i]);
        }

        SetPosState(2);
    }
    if (mov_pos == 4 && m_posState != 6)
    {
        p_snake->GenerateFood(map, Snake::SnakeEat(map, 4));
        p_snake->SnakeGrowth(snake, map, Snake::SnakeEat(map, 4));
        p_snake->CheckCollision(map, snake, 4);

        map.SetMemX(-1);
        
        UpdateMemPos(map, 4);
        for (int i{ 0 };i < snake_size;++i)
        {
            p_map->SetCharInMap(p_snake->GetMemXpos()->at(i), p_snake->GetMemYpos()->at(i), m_snake[i]);
        }
        
        SetPosState(4);
    }
}

std::vector<int>* Snake::GetMemXpos()
{
    auto p{ &m_memXpos };
    return p;
}

std::vector<int>* Snake::GetMemYpos()
{
    auto p{ &m_memYpos };
    return p;
}

void Snake::UpdateMemPos(GameMap& map, int mov_pos)
{
    auto p_map{ &map };
    auto memX{ p_map->GetMemX() };
    auto memY{ p_map->GetMemY() };
    
    for (int i{ static_cast<int>(m_memXpos.size() - 1) }; i > 0; --i)
    {
        m_memXpos[i] = m_memXpos[i - 1];
    }
    m_memXpos[0] = memX;

    for (int i{ static_cast<int>(m_memYpos.size() - 1) }; i > 0; --i)
    {
        m_memYpos[i] = m_memYpos[i - 1];
    }
    m_memYpos[0] = memY;
}

void Snake::CheckCollision(GameMap& map, Snake& snake, int mov_pos)
{
    auto p_map{ &map };
    auto p_snake{ &snake };

    auto upper_char{ p_map->GetCurrentChar_Upper() }; //from "snake head" perspective
    auto lower_char{ p_map->GetCurrentChar_Lower() }; //from "snake head" perspective
    auto right_char{ p_map->GetCurrentChar_Right() }; //from "snake head" perspective
    auto left_char{ p_map->GetCurrentChar_Left() }; //from "snake head" perspective 

    auto borderLook{ p_map->GetMapChar()};
    auto snakeLook{ p_snake->GetSnakeLook() };

    if (mov_pos == 8)
    {
        if (upper_char == borderLook)
        {
            m_borderCollision = true;
            Snake::MSG_SetGameOver(map); //border collision
            Snake::MSG_SetScore(map, snake);
            Snake::MSG_SetPressToStart(map);
        }

        if (upper_char == snakeLook)
        {
            m_selfCollision = true;
            Snake::MSG_SetGameOver(map); //self collision
            Snake::MSG_SetScore(map, snake);
            Snake::MSG_SetPressToStart(map);
        }
    }

    if (mov_pos == 6)
    {
        if (right_char == borderLook)
        {
            m_borderCollision = true;
            Snake::MSG_SetGameOver(map); //border collision
            Snake::MSG_SetScore(map, snake);
            Snake::MSG_SetPressToStart(map);
        }

        if (right_char == snakeLook)
        {
            m_selfCollision = true;
            Snake::MSG_SetGameOver(map); //self collision
            Snake::MSG_SetScore(map, snake);
            Snake::MSG_SetPressToStart(map);
        }
    }

    if (mov_pos == 2)
    {
        if (lower_char == borderLook)
        {
            m_borderCollision = true;
            Snake::MSG_SetGameOver(map); //border collision
            Snake::MSG_SetScore(map, snake);
            Snake::MSG_SetPressToStart(map);
        }

        if (lower_char == snakeLook)
        {
            m_selfCollision = true;
            Snake::MSG_SetGameOver(map); //self collision
            Snake::MSG_SetScore(map, snake);
            Snake::MSG_SetPressToStart(map);
        }
    }

    if (mov_pos == 4)
    {
        if (left_char == borderLook)
        {
            m_borderCollision = true;
            Snake::MSG_SetGameOver(map); //border collision
            Snake::MSG_SetScore(map, snake);
            Snake::MSG_SetPressToStart(map);
        }

        if (left_char == snakeLook)
        {
            m_selfCollision = true;
            Snake::MSG_SetGameOver(map); //self collision
            Snake::MSG_SetScore(map, snake);
            Snake::MSG_SetPressToStart(map);
        }
    }
}

void Snake::GenerateFood(GameMap& map, bool runAgain)
{
    if (m_f_runOnce_GenerateFood || runAgain)
    {
        auto p_map{ &map };
        bool generateAgain{ true };


     //GenerateAgain: //it is cleaner to use goto statement here
        while (generateAgain)
        {
            std::uniform_int_distribution<> foodX{ p_map->GetBorderUpper() + 1, p_map->GetBorderLower() - 2 };
            std::uniform_int_distribution<> foodY{ p_map->GetBorderLeft() + 1, p_map->GetBorderRight() - 2 };

            m_foodX = static_cast<int>(foodX(m_mtX));
            m_foodY = static_cast<int>(foodX(m_mtY));

            if (p_map->CheckIfEmpty(m_foodX, m_foodY))
            {
                p_map->SetCharInMap(m_foodX, m_foodY, m_foodLook);
                break;
            }
        }
    }
    m_f_runOnce_GenerateFood = 0;
}

bool Snake::SnakeEat(GameMap& map, int mov_pos)
{
    auto p_map{ &map };

    auto upper_char{ p_map->GetCurrentChar_Upper() }; //from "snake head" perspective
    auto lower_char{ p_map->GetCurrentChar_Lower() }; //from "snake head" perspective
    auto right_char{ p_map->GetCurrentChar_Right() }; //from "snake head" perspective
    auto left_char { p_map->GetCurrentChar_Left() }; //from "snake head" perspective 
    
    switch (mov_pos)
    {
    case 8:
    {
        if (upper_char == m_foodLook)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case 6:
    {
        if (right_char == m_foodLook)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case 2:
    {
        if (lower_char == m_foodLook)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case 4:
    {
        if (left_char == m_foodLook)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    default:
        return false;
    }
}

void Snake::SnakeGrowth(Snake& snake, GameMap& map, bool SnakeEat)
{
    auto p_map{ &map };
    auto p_snake{ &snake };

    if (SnakeEat)
    {
        p_snake->GetSnake()->at(p_snake->GetSnake()->size() - 1) = m_snake_look; //set m_snake_look to the end element of the snake vector
        p_snake->GetSnake()->insert(p_snake->GetSnake()->end(), ' '); //add additional element to the end of the snake vector, and set it to a "nothing" char
        p_snake->GetMemXpos()->insert(p_snake->GetMemXpos()->end(), p_snake->GetMemXpos()->at(p_snake->GetMemXpos()->size() - 1)); //add additional element to the end of the memory position (X), and set it to the previous element - Snake::UpdateMemPos will update the right location
        p_snake->GetMemYpos()->insert(p_snake->GetMemYpos()->end(), p_snake->GetMemYpos()->at(p_snake->GetMemYpos()->size() - 1)); //add additional element to the end of the memory position (Y), and set it to the previous element - Snake::UpdateMemPos will update the right location
    }
}

int Snake::GetFoodX()
{
    return m_foodX;
}

int Snake::GetFoodY()
{
    return m_foodY;
}

bool Snake::borderCollision()
{
    return m_borderCollision;
}

bool Snake::selfCollision()
{
    return m_selfCollision;
}

void Snake::MSG_SetGameOver(GameMap& map)
{
    auto p_map{ &map };

    for (int i{ 0 };i < m_msg_gameOver.size();++i)
    {
        p_map->SetCharInMap((GameMap::GetBorderLower() - GameMap::GetBorderUpper()) / 3 + i, (GameMap::GetBorderRight() - GameMap::GetBorderLeft()) / 2, m_msg_gameOver[i]);
    }
}

void Snake::MSG_SetPressToStart(GameMap& map)
{
    auto p_map{ &map };
    int new_line{ 0 };
    int x_counter{ 0 };

    for (int i{ 0 };i < m_msg_pressToStart.size();++i)
    {
        if (m_msg_pressToStart[i] != ' ')
        {
            p_map->SetCharInMap(GameMap::GetBorderUpper() + 1 + x_counter, GameMap::GetBorderLeft() + 1 + new_line, m_msg_pressToStart[i]);
            ++x_counter;
        }
        else
        {
            ++new_line;
            x_counter = 0;
        }
        
    }
}


void Snake::MSG_RemovePressToStart(GameMap& map)
{
    auto p_map{ &map };
    int new_line{ 0 };
    int x_counter{ 0 };

    for (int i{ 0 };i < m_msg_pressToStart.size();++i)
    {
        if (m_msg_pressToStart[i] != ' ')
        {
            p_map->SetCharInMap(GameMap::GetBorderUpper() + 1 + x_counter, GameMap::GetBorderLeft() + 1 + new_line, ' ');
            p_map->SetCharInMap(m_foodX, m_foodY, m_foodLook);

            ++x_counter;
        }
        else
        {
            ++new_line;
            x_counter = 0;
        }

    }
}

void Snake::MSG_SetScore(GameMap& map, Snake& snake)
{
    auto p_map{ &map };
    auto p_snake{ &snake };
    std::string score{ std::to_string(p_snake->GetSnake()->size() - m_initialSize) };

    for (int i{ 0 };i < m_msg_score.size();++i)
    {
        if (i < m_msg_score.size() - 1)
        {
            p_map->SetCharInMap(GameMap::GetBorderUpper() + 1 + i, (GameMap::GetBorderRight() - GameMap::GetBorderLeft()) / 2 + 2, m_msg_score[i]);
        }
        if (i == m_msg_score.size() - 1)
        {
            for (int j{ 0 };j < score.size();++j)
            {
                p_map->SetCharInMap(GameMap::GetBorderUpper() + 1 + i + j, (GameMap::GetBorderRight() - GameMap::GetBorderLeft()) / 2 + 2, score[j]);
            }
        }
    }
}
