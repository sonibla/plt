#include "Spell.h"

#include <iostream>
using namespace std;
using namespace state;

Spell::Spell() {}
Spell::~Spell() {}

void Resolve () {}
bool ValidTargets () {}
void Copy () {}

std::shared_ptr<GameElement> Spell::Create(){
    std::shared_ptr<Spell> _gameElement = std::make_shared<Spell>();

    GameElement::store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}