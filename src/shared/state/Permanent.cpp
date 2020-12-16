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

Json::Value Permanent::serialize () {

    Json::Value json;

    json = PlayableGameElement::serialize();

    json["tapped"] = tapped;
    json["strength"] = strength;
    json["toughness"] = toughness;
    json["image_location"] = image_location;
    json["ownerID"] = ownerID;
    json["controllerID"] = controllerID;

    json["types"].resize(types.size());

    for (size_t i(0); i<this->types.size(); i++)
	{
		json["types"][(Json::ArrayIndex) i] = this->types[i];
	}

    return json;

}


void Permanent::deserialize (Json::Value json) {

    PlayableGameElement::deserialize(json);

    tapped = json["tapped"].asBool();
    strength = json["strength"].asInt();
    toughness = json["toughness"].asInt();
    image_location = json["copy"].asString();
    ownerID = json["ownerID"].asInt();
    controllerID = json["controllerID"].asInt();

    types.clear();
    for (Json::ArrayIndex i(0); i<json["types"].size(); i++)
	{
		types.push_back(json["types"][i].asString());
	}

}