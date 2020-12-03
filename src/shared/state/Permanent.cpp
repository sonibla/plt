#include "Permanent.h"
#include "Zone.h"
#include <memory>
#include <iostream>
using namespace state;

bool Tap () {}

bool IsDead () {}

Permanent::Permanent(){
}

 Permanent::~Permanent(){
}

std::string Permanent::type(){
    return "permanent";
}


std::shared_ptr<GameElement> Permanent::Create(){
    std::shared_ptr<Permanent> _gameElement = std::make_shared<Permanent>();

    GameElement::Store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}