
#include "PlayerRenderer.h"
using namespace render;
using namespace std;


PlayerRenderer::PlayerRenderer(std::weak_ptr<state::Player> player){
    this->player=player;
    std::shared_ptr<state::Player> _player = player.lock();
    _player->addObserver(this);

    this->setPosition(sf::Vector2f(10,690));
    sf::Vector2f position = this->getPosition();
    
    this->texture.loadFromFile("../res/textures/denim.png");

    this->sprite.setTexture(this->texture);
    this->sprite.setScale(150/this->sprite.getLocalBounds().width,300/this->sprite.getLocalBounds().height);
    this->sprite.setPosition(position.x,position.y);

    this->font.loadFromFile("../res/fonts/arial.ttf");

    this->text.setCharacterSize(30);
    this->text.setPosition(position.x+10,position.y);
    this->text.setFont(this->font);
    
    this->update((state::IObservable*) _player.get());
}


PlayerRenderer::~PlayerRenderer (){
    this->player.lock()->removeObserver(this);
}


void PlayerRenderer::update (state::IObservable* obj){

    this->text.setString(std::string("Player \nLife :") + std::to_string(_player->life) + std::string("\nMana :") + std::to_string(_player->mana) + std::string("/")+std::to_string(_player->manaMax));
    this->notify();
}



void PlayerRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const{
    
    target.draw(this->sprite);
    target.draw(this->text);

}