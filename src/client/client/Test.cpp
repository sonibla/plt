//
// Created by maxime on 26/10/2020.
//

#include "Test.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace client;
using namespace state;
using namespace render;

std::vector<std::shared_ptr<Card>> create_cards_placeholder(){
    std::vector<std::shared_ptr<Card>> _cards;
    for(int i =0; i<6;i++){
        std::shared_ptr<Card> _card = std::dynamic_pointer_cast<Card>(Card::create());
        //art of a black lotus
        _card->image_location = "../res/textures/card"+std::to_string(i)+".png";
        _card->name = "Place Holder";
        _cards.push_back(_card);
    }
    return _cards;
}

std::vector<std::shared_ptr<Permanent>> create_permanents_placeholder(std::weak_ptr<state::Player> player){
    std::vector<std::shared_ptr<Permanent>> _permanents;
    for(int i =0; i<6;i++){
        std::shared_ptr<Permanent> _permanent = std::dynamic_pointer_cast<Permanent>(Token::create());
        //art of a black lotus
        _permanent->image_location = "../res/textures/card"+std::to_string(i)+".png";
        _permanent->tapped = false;
        _permanent->controllerID = player.lock()->getID();
        _permanents.push_back(_permanent);
    }
    return _permanents;
}

std::shared_ptr<Player> create_player_placeholder(){

    std::shared_ptr<Player> _player = std::dynamic_pointer_cast<Player>(Player::Create());
    std::weak_ptr<Graveyard> _graveyard = _player->GetGraveyard();
    _graveyard.lock()->SetCards(create_cards_placeholder());
    std::weak_ptr<Library> _library = _player->GetLibrary();
    _library.lock()->SetCards(create_cards_placeholder());
    std::weak_ptr<Hand> _hand = _player->GetHand();
    _hand.lock()->SetCards(create_cards_placeholder());
    return _player;
}

void Test::state(){
    std::vector<std::shared_ptr<Player>> _players;

    std::shared_ptr<Player> _player = create_player_placeholder();
    _players.push_back(_player);

    _player = create_player_placeholder();
    _players.push_back(_player);
    
    std::weak_ptr<Game> game = Game::GetInstance();
    std::cout << 1 << std::endl;
    auto _game = game.lock();
    _game->GetExile().lock()->SetCards(create_cards_placeholder());
    _game->SetPlayers(_players);


    std::shared_ptr<state::Battlefield> _battlefield = _game->GetBattlefield().lock();
    _battlefield->setPermanents(create_permanents_placeholder(_player));

}


//Test Render


void Test::render(){ 

    std::shared_ptr<Game> game = Game::Create();
    this->state();
    render::RenderingManager* _renderingManager = new render::RenderingManager();

    for(auto it=GameElement::idTable.begin(); it!=GameElement::idTable.end() ; it++){
        std::string s;
        if(it->second.expired())
        {
            s = "expired";
        }
        else{
            s = it->second.lock()->type();
        }
        std::cout << it->first<< " : "<< s << std::endl;
    }

    while (_renderingManager->window.isOpen())
    {
        // Process events
        sf::Event event;
        while (_renderingManager->window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                _renderingManager->window.close();
        }
        _renderingManager->update(nullptr,state::EventID::UPDATE);
    }

}
