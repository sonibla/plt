
#include "PlayerRenderer.h"
using namespace render;
using namespace std;


PlayerRenderer::PlayerRenderer(std::weak_ptr<state::Player> player, sf::Vector2f position){
    this->player=player;
    std::shared_ptr<state::Player> _player = player.lock();
    _player->addObserver(this);

    this->setPosition(position);

    this->texture.loadFromFile("../res/textures/denim.png");

    this->font.loadFromFile("../res/fonts/arial.ttf");

    this->update((state::IObservable*) _player.get(),state::EventID::UPDATE);
}


PlayerRenderer::~PlayerRenderer (){
    this->player.lock()->removeObserver(this);
}


void PlayerRenderer::update (state::IObservable* obj,state::EventID eventID){

    std::shared_ptr<state::Player> _player = player.lock();
    this->life = _player->life;
    this->mana = _player->mana;
    this->manaMax = _player->manaMax;
    
    this->notify(eventID);

}



void PlayerRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const{
    sf::Vector2f _position = this->getPosition();

    sf::Sprite _sprite(this->texture);
    _sprite.setScale(150/_sprite.getLocalBounds().width,300/_sprite.getLocalBounds().height);
    _sprite.setPosition(_position.x,_position.y);

    sf::Text _text(std::string("Player \nLife :") + std::to_string(this->life) + std::string("\nMana :") + std::to_string(this->mana) + std::string("/")+std::to_string(this->manaMax) ,this->font, 30);
    _text.setPosition(_position.x+10,_position.y);
    
    target.draw(_sprite);
    target.draw(_text);
}