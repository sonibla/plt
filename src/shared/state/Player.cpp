//
// Created by maxime on 13/10/2020.
//

#include "Player.h"
#include "Spell.h"
#include <iostream>
using namespace state;
using namespace std;


bool Player::Cast(int cardID){


    //On a créer un nouveau ability - type Spell à mettre
    std::shared_ptr<state::Spell> _spell = std::dynamic_pointer_cast<Spell>(state::Spell::Create());
    std::shared_ptr<Card> _card = std::dynamic_pointer_cast<Card>(GameElement::GetPtr(cardID).lock()); //on bloque le pointeur et on le transforme en shared
    _spell->source = _card; //On complète la source de l'ability par la carte en entrée 
    std::weak_ptr<Game> game = Game::GetInstance();
    auto _game = game.lock();
    auto ptr_stack =  _game->GetStack().lock(); //renvoie le pointeur du stack 
    ptr_stack->stackContent.push(_spell); //Ajout de la carte dans la stack
    //boucle sur la taille main, comparaison id et enlever la carte en conséquence :
    for(int i = 0; i < this->hand->cards.size(); i++){
        if(this->hand->cards[i]->GetID () == cardID){
            this->hand->cards.erase(this->hand->cards.begin()+i); 
        }
    } 
    _card->ChangeID();

    return true;
}
bool Player::Play(int cardID){}
bool Player::ActivateAbility(int source){}
void Player::PassPriority(){}
bool Player::Draw(int nb){
    std::cout << "cards to be drawed :" << nb << std::endl;
    std::cout << "cards in library :" << library->cards.size() << std::endl;
        for(int i=0; i<nb; i++){
            if(!library->cards.empty()){
                int library_size = library->cards.size();
                library->cards[library_size -1]->ChangeID();
                hand->cards.push_back(library->cards[library_size -1]);
                library->cards.pop_back();
                hand->notify(EventID::UPDATE);
                library->notify(EventID::UPDATE);
            }
            else{
                this->Lose();
            }
        }
    std::cout << "end drawing" << std::endl;
    
}
bool Player::Discard(int nb){}
std::list<int> Player::Target(){}
bool Player::Win(){}
bool Player::Lose(){
    std::cout << "you lose" << std::endl;
    return true;
}

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

std::string Player::type(){
    return "player";
}

std::shared_ptr<GameElement> Player::Create(){
    std::shared_ptr<Player> _gameElement = std::make_shared<Player>();

    GameElement::Store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}
