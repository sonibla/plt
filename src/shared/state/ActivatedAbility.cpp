#include "ActivatedAbility.h"
#include <iostream>

using namespace std;
using namespace state;

ActivatedAbility::ActivatedAbility() {}
ActivatedAbility::~ActivatedAbility() {}


std::shared_ptr<GameElement> ActivatedAbility::Create(){
    std::shared_ptr<ActivatedAbility> _gameElement = std::make_shared<ActivatedAbility>();

    GameElement::store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}