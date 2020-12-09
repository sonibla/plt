//
// Created by maxime on 13/10/2020.
//

#include "Player.h"
#include "Spell.h"
#include <iostream>
using namespace state;
using namespace std;

/*
Prend la carte et supprime de la main et créer un ability qui correspond à la carte et l'ajoute dans le stack 
*/
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

    return true;
}

bool Player::Play(int cardID){

}

/*
A faire 
*/
bool Player::ActivateAbility(int sourceID){

}

/*
A faire
*/
void Player::PassPriority(){

}



bool Player::Draw(int nb){
    for(int i=0; i<nb; i++){
        int library_size = library->cards.size();
        hand->cards.push_back(library->cards[library_size -1]);
        library->cards.pop_back();
    }
}

/*
Discard(int nb) 
Renvoie un booléen 
*/
bool Player::Discard(int nb){
    /*
    std::list<std::weak_ptr<GameElement>> _list = Target();
    if (_list.size() == nb){
        //Mettre les cartes de la liste dans le cimetière
    }
    */

}


bool Player::Win(){

}


bool Player::Lose(){

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



/*
Target() demande à l'utilisateur les ID cartes cibles et 
les renvoie dans une liste
*/
std::list<std::weak_ptr<GameElement>> Target (){
    /*
    std::list<std::weak_ptr<GameElement>>  _targetedCards;
    std::weak_ptr<GameElement> pointeur;
    int ID;
    
    while(ID != -1){
    cout<<"Enter targeted card ID : ";
    cin>> ID;
    //récupère weak pointeur à partir de l'ID pointeur = pointeurID
    _targetedCards.push_back(pointeur);
    }

    return _targetedCards;
    */
}


std::string Player::type(){
    return "player";
}





std::shared_ptr<GameElement> Player::Create(){
    std::shared_ptr<Player> _gameElement = std::make_shared<Player>();

    GameElement::Store(_gameElement);

    std::cout << "created :" <<_gameElement->id << std::endl;
    return _gameElement;
}
