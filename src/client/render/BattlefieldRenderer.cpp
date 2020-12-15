#include "BattlefieldRenderer.h"

using namespace std;
using namespace render;
#include <iostream>


void BattlefieldRenderer::update(state::IObservable* obj,state::EventID eventID){


    std::shared_ptr<state::Battlefield> _battlefield = this->battlefield.lock();

    std::vector<std::weak_ptr<state::Permanent>> list_permanents = _battlefield->getPermanents();

    for (size_t i=0; i<list_permanents.size();i++){
        std::shared_ptr<PermanentRenderer> _rendered_permanent = std::make_shared<PermanentRenderer>(list_permanents[i]);
        this->permanents.push_back(_rendered_permanent);
    }
    this->notify(eventID);
}


BattlefieldRenderer::BattlefieldRenderer (std::weak_ptr<state::Battlefield> battlefield, sf::Vector2f position){
    this->battlefield = battlefield;
    std::shared_ptr<state::Battlefield> _battlefield = battlefield.lock();
    _battlefield->addObserver(this);

    //Initialising position
    this->setPosition(position);

    //Loading the BF background
    this->texture.loadFromFile("../res/textures/concrete_wall.png");

    this->update(_battlefield.get(),state::EventID::UPDATE);
}

BattlefieldRenderer::~BattlefieldRenderer (){

}


void BattlefieldRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
    
    sf::Vector2f bf_postion = this->getPosition();
    float x_length = 631;
    float y_length = 560;
    float controlleroffset = 440;  
    int playercount = 0;
    int opponentcount = 0;

    sf::Sprite bg_battlefield(this->texture);
    bg_battlefield.setPosition(bf_postion);
    bg_battlefield.setScale(x_length/bg_battlefield.getLocalBounds().width,y_length/bg_battlefield.getLocalBounds().height);

    target.draw(bg_battlefield);
    
    for (size_t i=0; i<this->permanents.size(); i++){

        std::shared_ptr<PermanentRenderer> _permanent = this->permanents[i];
        std::shared_ptr<state::Player> _controller = std::dynamic_pointer_cast<state::Player>(state::GameElement::getPtr(_permanent->controllerID).lock());

        
        if(_controller->getID() != 0){ //If the permanent is controlled by the opponent
        
            if (_permanent->getRotation() == 0){ //Checking if the permanent is not tapped
                _permanent->setPosition(bf_postion.x + opponentcount*90 + 10, bf_postion.y + 10);
                _permanent->setScale(73/_permanent->getLocalBounds().width,100/_permanent->getLocalBounds().height);
            }
            else {
            _permanent->setPosition(bf_postion.x + opponentcount*90 + 10 - 8, bf_postion.y + 10 + 100); //Adding the tapped offset in the x and y axis
            _permanent->setScale(73/_permanent->getLocalBounds().width,100/_permanent->getLocalBounds().height);
            }
            opponentcount++;
        }
        else{ //If the permanent is controlled by the player
            
            if (_permanent->getRotation() == 0){ //Checking if the permanent is not tapped
                _permanent->setPosition(bf_postion.x + playercount*90 + 10, bf_postion.y + 10 +controlleroffset);
                _permanent->setScale(73/_permanent->getLocalBounds().width,100/_permanent->getLocalBounds().height);
            }
            else {
                _permanent->setPosition(bf_postion.x + playercount*90 + 10 - 8, bf_postion.y + 10 + 100 + controlleroffset); //Adding the tapped offset in the x and y axis
                _permanent->setScale(73/_permanent->getLocalBounds().width,100/_permanent->getLocalBounds().height);
            }
            playercount++;
        }
        target.draw(*_permanent);
        
    }
    
}
