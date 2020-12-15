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

std::shared_ptr<GameElement> Card::create(){
    std::shared_ptr<Card> _gameElement = std::make_shared<Card>();

    GameElement::store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}

Json::Value Card::serialize ()  {
    Json::Value json;
    std::string name;
    int manaCost;
    std::string image_location;

    json["name"] = name;
    json["manaCost"] = manaCost;
    json["image_location"] = image_location;


    return json;
}

void Card::deserialize (Json::Value json)  {
    name = json["name"].toStyledString(); //convertion JSON to string
    manaCost = json["manaCost"].asInt(); //convertion JSON to int
    image_location = json["image_location"].toStyledString(); 
}