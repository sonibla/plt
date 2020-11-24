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


BattlefieldRenderer::BattlefieldRenderer (std::weak_ptr<state::Battlefield> battlefield, sf::Vector2f position){
    this->battlefield = battlefield;
    std::shared_ptr<state::Battlefield> _battlefield = battlefield.lock();
    _battlefield->addObserver(this);

    //Initialising position
    this->setPosition(position);

    //Loading the BF background
    this->texture.loadFromFile("../res/textures/concrete_wall.png");

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

    sf::Vector2f bf_postion = this->getPosition();
    float x_length = 631;
    float y_length = 560;
    float _playeroffset = 0;  

    sf::Sprite bg_battlefield(this->texture);
    bg_battlefield.setPosition(bf_postion);
    bg_battlefield.setScale(x_length/bg_battlefield.getLocalBounds().width,y_length/bg_battlefield.getLocalBounds().height);

    target.draw(bg_battlefield);

    for (size_t i=0; i<this->permanents.size(); i++){

        std::shared_ptr<PermanentRenderer> _drawed_permanent = this->permanents[i];

        if(_drawed_permanent->owner = opponent){
            _playeroffset = 0;
        }else{
            _playeroffset = 450;
        }

        if (_drawed_permanent->getRotation() == 0){ //Checking if the permanent is not tapped
            _drawed_permanent->setPosition(bf_postion.x + i*90 + 10, bf_postion.y + 10 +_playeroffset);
            _drawed_permanent->setScale(73/_drawed_permanent->getLocalBounds().width,100/_drawed_permanent->getLocalBounds().height);
        }
        else {
             _drawed_permanent->setPosition(bf_postion.x + i*90 + 10 - 8, bf_postion.y + 10 + 100 + _playeroffset); //Adding the tapped offset in the x and y axis
            _drawed_permanent->setScale(73/_drawed_permanent->getLocalBounds().width,100/_drawed_permanent->getLocalBounds().height);
        }
        target.draw(*_drawed_permanent);
    }
}