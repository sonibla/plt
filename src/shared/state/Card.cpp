//
// Created by maxime on 18/10/2020.
//
#include "Card.h"
#include <iostream>

using namespace std;
using namespace state;

Card::Card() {}
Card::~Card() {}

std::string Card::type(){
    return "card";
}

std::shared_ptr<GameElement> Card::Create(){
    std::shared_ptr<Card> _gameElement = std::make_shared<Card>();

    GameElement::Store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}