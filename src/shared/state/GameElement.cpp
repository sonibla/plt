#include "GameElement.h"
#include <iostream>
#include <memory>

using namespace std;
using namespace state;

int GameElement::lastID= 0;
std::map<int,std::weak_ptr<GameElement>> GameElement::idTable;

int GameElement::getID (){
    return id;
}

std::shared_ptr<GameElement> GameElement::getPtr (int id){
    std::shared_ptr<GameElement> gameElement;
    auto search = GameElement::idTable.find(id);
    if(search != GameElement::idTable.end()){
        gameElement= search->second.lock();
    }
    else{
        std::cout << "could not find gameElement " << id << std::endl;
    }
    return gameElement;
}

//Change the id of a gameElement , mostly when a gameElement move from a zone to another
void GameElement::changeID (){
    idTable.erase(this->id);

    this->id = GameElement::newID();

    GameElement::store(this->shared_from_this());
}

int GameElement::newID (){
    GameElement::lastID++;
    return lastID;
}
void GameElement::store(std::shared_ptr<GameElement> gameElement){
    GameElement::idTable[gameElement->id] = gameElement->weak_from_this();
}
std::string GameElement::type(){ 
    return "gameElement";
}

std::shared_ptr<GameElement> GameElement::create(){
    std::shared_ptr<GameElement> _gameElement = std::make_shared<GameElement>();

    GameElement::store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}

GameElement::GameElement(){
    this->id = GameElement::newID();
}

GameElement::~GameElement(){

    if(this->id != -1){
        std::cout << "destroying :" << this->id << std::endl;    
        GameElement::idTable.erase(this->id);
    }
}

Json::Value GameElement::serialize () {

    Json::Value json;
    json = Serializable::serialize();

    json["behaviour"] = behaviour;
    json["id"] = id;
    
    return json;
}

void GameElement::deserialize (Json::Value json) {
    Serializable::deserialize(json);
    behaviour = json["behaviour"];    
    id = json["id"].asInt(); 

    GameElement::store(std::make_shared(*this));
}

