#include "GameElement.h"
#include <iostream>

using namespace std;
using namespace state;

int GameElement::lastID= 0;
std::map<int,std::weak_ptr<GameElement>> GameElement::idTable;

int GameElement::GetID (){
    return id;
}

/*
//Change the id of a gameElement , mostly when a gameElement move from a zone to another
void GameElement::ChangeID (){
    idTable.erase(this->id);

    this->id = GameElement::NewID();

    GameElement::Store(this->shared_from_this());
}
*/

/*
static int NewID (std::shared_ptr<GameElement> gameElement){
    GameElement::lastID++;
    return lastID;
}
*/

/*
void GameElement::Store(std::shared_ptr<GameElement> gameElement){

    GameElement::idTable[gameElement->id] = gameElement->weak_from_this();
}
*/

/*
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
        GameElement::idTable.erase(GameElement::idTable.find(this->id));
        /*auto finder = GameElement::idTable.find(this->id);
        if(finder != GameElement::idTable.end()){
            //GameElement::idTable.erase(finder);
            std::cout << this->id <<" destroyed properly" << std::endl;
        }
        else{
            std::cout << this->id <<" not found" << std::endl;
        }
    }


}
*/