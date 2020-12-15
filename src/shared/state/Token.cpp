#include "Token.h"
#include <iostream>
using namespace std;
using namespace state;

Token::Token() {}
Token::~Token() {}


std::shared_ptr<GameElement> Token::create(){
    std::shared_ptr<Token> _gameElement = std::make_shared<Token>();

    GameElement::store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}