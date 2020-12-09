//
// Created by maxime on 13/10/2020.
//

#include "Player.h"
#include <iostream>
using namespace state;
using namespace std;


bool Player::cast(int cardID){}
bool Player::play(int cardID){}
bool Player::activateAbility(int source){}
void Player::passPriority(){}
bool Player::draw(int nb){}
bool Player::discard(int nb){}
std::list<int> Player::target(){}
bool Player::win(){}
bool Player::lose(){}

std::weak_ptr<Graveyard> Player::getGraveyard(){
    return graveyard;
}
std::weak_ptr<Library> Player::getLibrary(){
    return library;
}
std::weak_ptr<Hand> Player::getHand(){
    return hand;
}
Player::Player(){
    graveyard = make_shared<Graveyard>();
    library = make_shared<Library>();
    hand = make_shared<Hand>();
}
Player::~Player(){}

std::string Player::type(){
    return "player";
}

std::shared_ptr<GameElement> Player::create(){
    std::shared_ptr<Player> _gameElement = std::make_shared<Player>();

    GameElement::store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}
