#include "CardPermanent.h"
#include <iostream>
using namespace std;
using namespace state;

CardPermanent::CardPermanent() {}
CardPermanent::~CardPermanent() {}

std::shared_ptr<GameElement> CardPermanent::create(){
    std::shared_ptr<CardPermanent> _gameElement = std::make_shared<CardPermanent>();

    GameElement::store(_gameElement);
    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}

Json::Value CardPermanent::serialize () {

    Json::Value json;

    json["cardID"] = cardID;

    return json;
}

void CardPermanent::deserialize (Json::Value json) {
    cardID = json["cardID"].asInt();
}