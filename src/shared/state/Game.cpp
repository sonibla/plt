//
// Created by maxime on 13/10/2020.
//

//using namespace state;
#include "Game.h"

using namespace state;
using namespace std;

std::weak_ptr<Game> Game::instance;

std::weak_ptr<Game> Game::getInstance(){
    return instance;
}

void Game::nextTurn(std::weak_ptr<Player> player){}
std::weak_ptr<Battlefield> Game::getBattlefield(){
    return battlefield;
}
std::weak_ptr<Exile> Game::getExile(){
    return exile;
}
std::weak_ptr<Stack> Game::getStack(){
    return stack;
}
std::vector<std::weak_ptr<Player>> Game::getPlayers(){
    std::vector<std::weak_ptr<Player>> _players;
    for(size_t i=0;i<players.size();i++){
        _players.push_back(players[i]);
    }
    return _players;
}

void Game::setPlayers ( std::vector<std::shared_ptr<Player>> players){
    this->players = players;
}

std::shared_ptr<Game> Game::create(){
    std::shared_ptr<Game> game = make_shared<Game>();
    game->instance = game->weak_from_this();
    return game;
}

Game::Game (){
    this->battlefield = std::make_shared<Battlefield>();
    this->stack = std::make_shared<Stack>();
    this->exile = std::make_shared<Exile>();
}
Game::~Game(){}

Json::Value Game::serialize() {
	Json::Value json;

	json["battlefield"] = this->battlefield->serialize();
	json["stack"] = this->stack->serialize();
	json["exile"] = this->exile->serialize();
	json["turn"] = this->turn->serialize();
	for (int i(0); i<this->players.size(); i++)
	{
		json["players"][i] = this->players[i]->serialize();
	}

	return json;
}

void Game::deserialize(Json::Value json) {

}

