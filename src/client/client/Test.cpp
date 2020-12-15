//
// Created by maxime on 26/10/2020.
//

#include "Test.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <json/json.h>

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

    std::shared_ptr<Player> _player = std::dynamic_pointer_cast<Player>(Player::create());
    std::weak_ptr<Graveyard> _graveyard = _player->getGraveyard();
    _graveyard.lock()->setCards(create_cards_placeholder());
    std::weak_ptr<Library> _library = _player->getLibrary();
    _library.lock()->setCards(create_cards_placeholder());
    std::weak_ptr<Hand> _hand = _player->getHand();
    _hand.lock()->setCards(create_cards_placeholder());
    return _player;
}

void Test::state(){
    std::vector<std::shared_ptr<Player>> _players;

    std::shared_ptr<Player> _player = create_player_placeholder();
    _players.push_back(_player);

    _player = create_player_placeholder();
    _players.push_back(_player);
    
    std::weak_ptr<Game> game = Game::getInstance();
    std::cout << 1 << std::endl;
    auto _game = game.lock();
    _game->getExile().lock()->setCards(create_cards_placeholder());
    _game->setPlayers(_players);


    std::shared_ptr<state::Battlefield> _battlefield = _game->getBattlefield().lock();
    _battlefield->setPermanents(create_permanents_placeholder(_player));

}


//Test Render


void Test::render(){ 

    std::shared_ptr<Game> game = Game::create();
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

// Test Engine

void Test::engine(){ 
    std::shared_ptr<Game> _game = Game::Create();
    this->state();


    auto _stack =  _game->GetStack().lock();

    auto _player = _game->GetPlayers()[0].lock();


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

    std::cout << "number of cards in player hand :" << _player->GetHand().lock()->cards.size() << "\n" <<std::endl;
    std::cout << "number of abilities in the stack :" << _stack->stackContent.size() << "\n" <<std::endl;

    int cardID = _player->GetHand().lock()->cards[0]->GetID();

    std::cout << "ID of the card that is going to be casted :" << cardID << "\n" << std::endl;
    std::cout << "casting the card... \n" << std::endl;
    _player->Cast(cardID);

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

}