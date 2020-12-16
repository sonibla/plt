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