#include "Ability.h"
#include <iostream>
using namespace std;
using namespace state;

void Ability::resolve () {}
bool Ability::validTargets () {return true;}
void Ability::copy () {}

Ability::Ability () {}

Ability::~Ability () {}

std::string Ability::type(){
    return "Ability";   
}

std::shared_ptr<GameElement> Ability::create(){
    std::shared_ptr<Ability> _gameElement = std::make_shared<Ability>();

    GameElement::store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}
