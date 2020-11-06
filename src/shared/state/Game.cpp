//
// Created by maxime on 13/10/2020.
//

//using namespace state;
#include "Game.h"

using namespace state;
using namespace std;

std::shared_ptr<Game> Game::instance = (nullptr);

std::weak_ptr<Game> Game::GetInstance(){
    if(!instance){
        instance = std::make_shared<Game>();
    }
    return instance;
}
void Game::NextTurn(std::weak_ptr<Player> player){}
std::weak_ptr<Battlefield> Game::GetBattlefield(){
    return battlefield;
}
std::weak_ptr<Exile> Game::GetExile(){
    return exile;
}
std::weak_ptr<Stack> Game::GetStack(){
    return stack;
}
std::weak_ptr<Command> Game::GetCommand(){
    return command;
}
std::vector<std::weak_ptr<Player>> Game::GetPlayers(){
    std::vector<std::weak_ptr<Player>> _players;
    for(size_t i=0;i<players.size();i++){
        _players.push_back(players[i]);
    }
    return _players;
}

void Game::SetPlayers ( std::vector<std::shared_ptr<Player>> players){
    this->players = players;
}

Game::Game (){
    this->battlefield = std::make_shared<Battlefield>();
    this->stack = std::make_shared<Stack>();
    this->exile = std::make_shared<Exile>();
    this->command = std::make_shared<Command>();
}
Game::~Game(){}

