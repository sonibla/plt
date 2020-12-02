#include "GameElement.h"
#include <iostream>

using namespace std;
using namespace state;

int GameElement::lastID= 0;
std::map<int,std::weak_ptr<GameElement>> GameElement::idTable;

int GameElement::GetID (){
    return id;
}

//Change the id of a gameElement , mostly when a gameElement move from a zone to another
void GameElement::ChangeID (){
    idTable.erase(this->GetID());

    this->id = GameElement::NewID(std::make_shared<GameElement>(*this));
}

int GameElement::NewID (std::shared_ptr<GameElement> gameElement){
    GameElement::lastID++;

    idTable[ GameElement::lastID] = gameElement;
    return lastID;
}

GameElement::GameElement(){
    this->id = GameElement::NewID(std::make_shared<GameElement>(*this));

    std::cout << "created :" <<this->id << std::endl;
}

GameElement::~GameElement(){
    std::cout << "destroyed:" << this->id << std::endl;
    idTable.erase(this->id);
}