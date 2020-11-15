//
// Created by maxime on 26/10/2020.
//

#include "Test.h"

#include <iostream>

using namespace client;
using namespace state;

std::vector<std::shared_ptr<Card>> create_cards_placeholder(){
    std::vector<std::shared_ptr<Card>> _cards;
    for(int i =0; i<6;i++){
        std::shared_ptr<Card> _card = std::make_shared<Card>();
        //art of a black lotus
        _card->image_uri = "https://c1.scryfall.com/file/scryfall-cards/large/front/b/a/bad6b494-d773-4f7d-ac39-85d82e1d3015.jpg    ";
        _card->name = "Place Holder";
        _cards.push_back(_card);
    }
    return _cards;
}

std::shared_ptr<Player> create_player_placeholder(){

    std::shared_ptr<Player> _player = std::make_shared<Player>();
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
    auto _game = game.lock();
    _game->GetExile().lock()->SetCards(create_cards_placeholder());
    _game->SetPlayers(_players);

    std::cout << _game->GetPlayers().size() << std::endl;
}


void Test::render(){
}
