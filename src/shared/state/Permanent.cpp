#include "Permanent.h"
#include "Zone.h"
#include <memory>
#include <iostream>
using namespace state;

void tap () {}

bool isDead () {}

void untap () {}

void setControllerID(int controllerID) {}

void setStrength(int strength) {}

void setToughness(int toughness) {}

Permanent::Permanent(){
}

 Permanent::~Permanent(){
}

std::shared_ptr<GameElement> Permanent::create(){
    std::shared_ptr<Permanent> _gameElement = std::make_shared<Permanent>();

    GameElement::store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}
