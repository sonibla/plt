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


void Permanent::setController (std::shared_ptr<Player> controller){
    this->controller = controller;
}


void Permanent::setStrength (int strength){
    this->strength = strength;
}


void Permanent::setToughness (int toughness){
    this->toughness = toughness;
}







/*
std::string Permanent::type(){
    return "permanent";
}
*/


/*
std::shared_ptr<GameElement> Permanent::Create(){
    std::shared_ptr<Permanent> _gameElement = std::make_shared<Permanent>();

    GameElement::Store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}
*/