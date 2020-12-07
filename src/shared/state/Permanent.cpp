#include "Permanent.h"
#include "Zone.h"
#include <memory>
#include <iostream>
using namespace state;

void Tap () {}

bool IsDead () {}

void Untap () {}

void SetControllerID(int controllerID) {}

void SetStrength(int strength) {}

void SetToughness(int toughness) {}

Permanent::Permanent(){
}

 Permanent::~Permanent(){
}

std::shared_ptr<GameElement> Permanent::Create(){
    std::shared_ptr<Permanent> _gameElement = std::make_shared<Permanent>();

    GameElement::Store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}
