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
/*
    std::list<ActivatedAbility> activatedAbilities;
    std::list<TriggeredAbility> triggeredAbilities;
    bool tapped     = false;
    int strength     = 0;
    int toughness     = 0;
    std::string image_location;
    int ownerID;
    int controllerID;
    std::vector<std::string> types;


*/
    Json::Value json;

    json["tapped"] = tapped;
    json["strength"] = strength;
    json["toughness"] = toughness;
    json["image_location"] = image_location;
    json["ownerID"] = ownerID;
    json["controllerID"] = controllerID;

    for (int i(0); i<this->types.size(); i++)
	{
		json["types"][i] = this->types[i];
	}

    return json;

}


void Permanent::deserialize (Json::Value json) {
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