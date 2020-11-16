#include "CardRenderer.h"

using namespace std;
using namespace render;
using namespace state;

CardRenderer::CardRenderer (state::Card card) {
	sf::Texture texture;
    texture.loadFromFile(card.image_location);
    this->setTexture(texture);
    this->setScale(73/this->getLocalBounds().width, 100/this->getLocalBounds().height);
}

CardRenderer::~CardRenderer () {}
