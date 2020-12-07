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


void Permanent::setControllerID (int controllerID){
    this->controllerID = controllerID;
}


void Permanent::setStrength (int strength){
    this->strength = strength;
}


void Permanent::setToughness (int toughness){
    this->toughness = toughness;
}



