//
// Created by maxime on 13/10/2020.
//

//using namespace state;
#include "Game.h"
using namespace state;
using namespace std;

std::weak_ptr<Game> Game::GetInstance(){}
void Game::NextTurn(std::weak_ptr<Player> player){}
std::weak_ptr<Battlefield> Game::GetBattlefield(){}
std::weak_ptr<Exile> Game::GetExile(){}
std::weak_ptr<Stack> Game::GetStack(){}
std::weak_ptr<Command> Game::GetCommand(){}
std::vector<std::weak_ptr<Player>> Game::GetPlayers(){}
Game::Game(){}
Game::~Game(){}