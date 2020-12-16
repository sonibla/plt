//
// Created by maxime on 13/10/2020.
//

#include "CardZone.h"
using namespace state;
using namespace std;

void CardZone::setCards (std::vector<std::shared_ptr<Card>> cards){
    this->cards = cards;
}

std::weak_ptr<Card> CardZone::getCard(int position){
    return cards[position];
}

std::vector<std::weak_ptr<Card>> CardZone::getCards(){
    std::vector<std::weak_ptr<Card>> _cards;
    for(size_t i =0; i<cards.size();i++){
        _cards.push_back(cards[i]);
    }
    return _cards;
}


void CardZone::putOnTheBattlefield(std::weak_ptr<Card>){}



Json::Value CardZone::serialize() {
	

	
}

void CardZone::deserialize (Json::Value ) {
    
}