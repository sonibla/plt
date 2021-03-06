#include "CardRenderer.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace render;

CardRenderer::CardRenderer (std::weak_ptr<state::Card> card) {
    std::shared_ptr<state::Card> _card = card.lock();

    std::string _image_location = _card->image_location;
    
    this->texture.loadFromFile(_image_location);
    this->setTexture(this->texture);
    this->setScale(73/this->getLocalBounds().width, 100/this->getLocalBounds().height);
}

CardRenderer::~CardRenderer () {

}
