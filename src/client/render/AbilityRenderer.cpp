#include "AbilityRenderer.h"
#include "state/Card.h"

using namespace std;
using namespace render;


AbilityRenderer::AbilityRenderer (std::weak_ptr<state::Ability> ability){

    std::shared_ptr<state::Ability> _ability = ability.lock();
    sf::Texture texture_load;
    std::shared_ptr<state::Card> _source = std::dynamic_pointer_cast<state::Card>(_ability->source);
    texture_load.loadFromFile(_source->image_location);
    this->texture = texture_load;
    this->setTexture(this->texture);
    this->controllerID = _ability->controller;
}

AbilityRenderer::~AbilityRenderer (){

};
