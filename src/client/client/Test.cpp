//
// Created by maxime on 26/10/2020.
//

#include "Test.h"

#include <iostream>

using namespace client;
using namespace state;



void Test::state(){
    std::vector<std::shared_ptr<Player>> _players;
    _players.push_back(std::make_shared<Player>());
    _players.push_back(std::make_shared<Player>());
    

    std::weak_ptr<Game> game = Game::GetInstance();
    auto _game = game.lock();
    _game->SetPlayers(_players);

    std::cout << _game->GetPlayers().size() << std::endl;
}
