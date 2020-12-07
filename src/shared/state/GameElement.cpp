#include "GameElement.h"
#include <iostream>

using namespace std;
using namespace state;

int GameElement::lastID= 0;
std::map<int,std::weak_ptr<GameElement>> GameElement::idTable;

int GameElement::GetID (){
    return id;
}

std::weak_ptr<GameElement> GameElement::GetPtr (int id){
    std::weak_ptr<GameElement> gameElement;
    auto search = GameElement::idTable.find(id);
    if(search != GameElement::idTable.end()){
        gameElement= search->second;
    }
    return gameElement;
}

//Change the id of a gameElement , mostly when a gameElement move from a zone to another
void GameElement::ChangeID (){
    idTable.erase(this->id);

    this->id = GameElement::NewID();

    GameElement::Store(this->shared_from_this());
}

int GameElement::NewID (){
    GameElement::lastID++;
    return lastID;
}
void GameElement::Store(std::shared_ptr<GameElement> gameElement){

    GameElement::idTable[gameElement->id] = gameElement->weak_from_this();
}
std::string GameElement::type(){ 
    return "gameElement";
}

std::shared_ptr<GameElement> GameElement::Create(){
    std::shared_ptr<GameElement> _gameElement = std::make_shared<GameElement>();

    GameElement::Store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}

GameElement::GameElement(){
    this->id = GameElement::NewID();
}

GameElement::~GameElement(){

    if(this->id != -1){
        std::cout << "destroying :" << this->id << std::endl;
        auto search = GameElement::idTable.find(id);
        if(search != GameElement::idTable.end()){
            std::cout << "could not find element " << this->id << " in GameElement::idTable" << std::endl;
        }
        else{
            GameElement::idTable.erase(search);
        }
    }
}