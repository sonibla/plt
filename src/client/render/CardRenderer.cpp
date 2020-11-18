#include "CardRenderer.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace render;

//CardRenderer (std::weak_ptr<state::Card> card);
CardRenderer::CardRenderer (std::weak_ptr<state::Card> card) {
    std::shared_ptr<state::Card> _card = card.lock();
	sf::Texture texture;
    texture.loadFromFile(_card->image_location);
    this->setTexture(texture);
    this->setScale(73/this->getLocalBounds().width, 100/this->getLocalBounds().height);
}

CardRenderer::~CardRenderer () {}
