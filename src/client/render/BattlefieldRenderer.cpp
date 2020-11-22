#include "BattlefieldRenderer.h"

using namespace std;
using namespace render;



void BattlefieldRenderer::update(state::IObservable* obj){


    std::shared_ptr<state::Battlefield> _battlefield = this->battlefield.lock();

    std::vector<std::weak_ptr<state::Permanent>> list_permanents = _battlefield->GetPermanents();

    for (size_t i=0; i<list_permanents.size();i++){
        std::shared_ptr<PermanentRenderer> _rendered_permanent = std::make_shared<PermanentRenderer>(list_permanents[i]);
        this->permanents.push_back(_rendered_permanent);
    }
}


BattlefieldRenderer::BattlefieldRenderer (std::weak_ptr<state::Battlefield> battlefield){
    this->battlefield = battlefield;
    std::shared_ptr<state::Battlefield> _battlefield = battlefield.lock();
    _battlefield->addObserver(this);

    //Initialising position and dimensions
    float x_pos = 272;
    float y_pos = 220;
    float x_length = 631;
    float y_length = 560;
    this->setPosition(x_pos, y_pos);

    //Loading the BF background
    this->texture.loadFromFile("../res/textures/concrete_wall.png");
    this->sprite = sf::Sprite(this->texture);

    this->sprite.setPosition(x_pos, y_pos);
    this->sprite.setScale(x_length/this->sprite.getLocalBounds().width,y_length/this->sprite.getLocalBounds().height);

    this->update(_battlefield.get());
}

BattlefieldRenderer::~BattlefieldRenderer (){

}

/*
void BattlefieldRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(this->sprite);

    for (size_t i=0; i<this->permanents.size(); i++){

        //Testing dummy permanent
        std::weak_ptr<state::Permanent> permanent;
        std::shared_ptr<state::Permanent> _permanent = permanent.lock();
            //Test
        sf::Texture texture;
        texture.loadFromFile("../res/textures/card.png");   
        sf::Sprite HandCardBuffer(texture);
        std::string path;
        path = "../res/textures/card.png";
        _permanent->image_location = path;
        //End dummy test

        //std::shared_ptr<PermanentRenderer> _drawed_permanent = this->permanents[i];
        std::shared_ptr<PermanentRenderer> _drawed_permanent = std::make_shared<PermanentRenderer>(_permanent);

        _drawed_permanent->setPosition(10, i*90);
        _drawed_permanent->setScale(73/_drawed_permanent->getLocalBounds().width,100/_drawed_permanent->getLocalBounds().height);
        target.draw(*_drawed_permanent);
    }
}
*/


void BattlefieldRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(this->sprite);
    sf::Vector2f bf_postion = this->getPosition();

    for (size_t i=0; i<this->permanents.size(); i++){

        std::shared_ptr<PermanentRenderer> _drawed_permanent = this->permanents[i];

        _drawed_permanent->setPosition(bf_postion.x + i*90 + 10, bf_postion.y + 10);
        _drawed_permanent->setScale(73/_drawed_permanent->getLocalBounds().width,100/_drawed_permanent->getLocalBounds().height);
        target.draw(*_drawed_permanent);
    }
}