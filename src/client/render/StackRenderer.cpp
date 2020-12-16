#include "StackRenderer.h"

using namespace std;
using namespace render;
#include <iostream>


void StackRenderer::update(state::IObservable* obj,state::EventID eventID){

    std::shared_ptr<state::Stack> _stack = this->stack.lock();

    std::stack<std::shared_ptr<state::Ability>> tmp_stack_abilities = _stack->abilities;

    while (!tmp_stack_abilities.empty()){
        std::shared_ptr<AbilityRenderer> _rendered_ability = std::make_shared<AbilityRenderer>(tmp_stack_abilities.top());
        this->abilities.push_back(_rendered_ability);
        tmp_stack_abilities.pop();
    }
    this->notify(eventID);
}

StackRenderer::StackRenderer (std::weak_ptr<state::Stack> stack, sf::Vector2f position){
    this->stack = stack;
    std::shared_ptr<state::Stack> _stack = stack.lock();
    _stack->addObserver(this);

    //Initialising position
    this->setPosition(position);

    //Loading the BF background
    this->texture.loadFromFile("../res/textures/denim.png");

    this->update(_stack.get(),state::EventID::UPDATE);
}


void StackRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
    
    sf::Vector2f stack_position = this->getPosition();
    float x_length = 120;
    float y_length = 560;

    sf::Sprite bg_stack(this->texture);
    bg_stack.setPosition(stack_position);
    bg_stack.setScale(x_length/bg_stack.getLocalBounds().width,y_length/bg_stack.getLocalBounds().height);

    target.draw(bg_stack);

    int i = 0;
    
    for (auto it = this->abilities.rbegin(); it!=this->abilities.rend(); it++){
        
        (*it)->setPosition(stack_position.x + i*90+10 , stack_position.y + 10);
        i++;
        target.draw(*(*it));
        
    }
    
}