#include "TriggeredAbility.h"
#include <iostream>
using namespace std;
using namespace state;

TriggeredAbility::TriggeredAbility() {}
TriggeredAbility::~TriggeredAbility() {}

std::shared_ptr<GameElement> TriggeredAbility::Create(){
    std::shared_ptr<TriggeredAbility> _gameElement = std::make_shared<TriggeredAbility>();

    GameElement::store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}