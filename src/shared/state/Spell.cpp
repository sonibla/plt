#include "Spell.h"

#include <iostream>
using namespace std;
using namespace state;

Spell::Spell() {}
Spell::~Spell() {}

void Resolve () {}
bool ValidTargets () {}
void Copy () {}

std::shared_ptr<GameElement> Spell::create(){
    std::shared_ptr<Spell> _gameElement = std::make_shared<Spell>();

    GameElement::store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}

Json::Value Spell::serialize () {

    Json::Value json;

    //bool copy;

    json["copy"] = copy;

    return json;
}

void Spell::deserialize (Json::Value json) {
    copy = json["bool"].asBool();
}