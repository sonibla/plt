//
// Created by maxime on 13/10/2020.
//

#include "Player.h"

using namespace state;
using namespace std;


bool Player::Cast(std::weak_ptr<Card>){}
bool Player::Play(std::weak_ptr<Card>){}
bool Player::ActivateAbility(std::weak_ptr<PlayableGameElement> source){}
void Player::PassPriority(){}
bool Player::Draw(int nb){}
bool Player::Discard(int nb){}
std::list<std::weak_ptr<GameElement>> Player::Target(){}
bool Player::Win(){}
bool Player::Lose(){}
std::weak_ptr<Graveyard> Player::GetGraveyard(){
    return graveyard;
}
std::weak_ptr<Library> Player::GetLibrary(){
    return library;
}
std::weak_ptr<Hand> Player::GetHand(){
    return hand;
}
Player::Player(){
    graveyard = make_shared<Graveyard>();
    library = make_shared<Library>();
    hand = make_shared<Hand>();
}
Player::~Player(){}

