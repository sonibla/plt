#include "Permanent.h"
#include "Zone.h"
#include <memory>
#include <iostream>
using namespace state;

/*
Retourne la carte 
*/
void Permanent::Tap () {
    this->tapped = true;
}

void Permanent::Untap (){
    this->tapped = false;
}



bool Permanent::IsDead () {
    if(this->toughness<=0){ 
        return true;
    }else{
        return false;
    }

}

Permanent::Permanent(){

}


Permanent::~Permanent(){

}


void Permanent::SetControllerID (int controllerID){
    this->controllerID = controllerID;
}


void Permanent::SetStrength (int strength){
    this->strength = strength;
}


void Permanent::SetToughness (int toughness){
    this->toughness = toughness;
}

std::shared_ptr<GameElement> Permanent::Create(){
    std::shared_ptr<Permanent> _gameElement = std::make_shared<Permanent>();


    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}

std::string Permanent::type (){
    return "permanent";
}
