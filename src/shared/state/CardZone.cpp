//
// Created by maxime on 13/10/2020.
//

#include "CardZone.h"
using namespace state;
using namespace std;

void CardZone::SetCards (std::vector<std::shared_ptr<Card>> cards){
    this->cards = cards;
}
void CardZone::PutOnTheBattlefield(std::weak_ptr<Card>){}
std::weak_ptr<Card> CardZone::GetCard(int position){}
std::vector<std::weak_ptr<Card>> CardZone::GetCards(){}