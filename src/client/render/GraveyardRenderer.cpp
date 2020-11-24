#include "GraveyardRenderer.h"

using namespace std;
using namespace render;
using namespace state;

GraveyardRenderer::GraveyardRenderer (std::weak_ptr<state::Graveyard> graveyard, sf::Vector2f position) {
	this->graveyard = graveyard;
	this->graveyard.lock()->addObserver(this);

	sf::Vector2f _default_position(186.f, 890.f);
	if ((position.x == -1) && (position.y == -1))
	{
		// Default position
		this->setPosition(_default_position);
	}
	else
	{
		this->setPosition(position);
	}
	
	this->update((state::IObservable*) this->graveyard.lock().get());
}

GraveyardRenderer::~GraveyardRenderer () {
	this->cards.clear();
	this->graveyard.lock()->removeObserver(this);
}

void GraveyardRenderer::update (state::IObservable* obj) {
	this->cards.clear();
	for (size_t i = 0; i<this->graveyard.lock()->cards.size(); i++) {
		// Create unique pointers for every card in the zone
		shared_ptr<CardRenderer> _newRenderer (new CardRenderer(weak_ptr<Card>(this->graveyard.lock()->cards.at(i))));
		this->cards.push_back(_newRenderer);
	}
	
	this->notify(); // Indirect call to RenderingManager
}

void GraveyardRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Get my position:
	sf::Vector2f _position = this->getPosition();
	
	// Card's relative position:
	sf::Vector2f _card_position(20.f, 20.f);
	
	// Create a sprite with background texture :
	sf::Texture _texture;
	_texture.loadFromFile("../res/textures/denim.png");
	sf::Sprite _SpriteGraveyard(_texture);
	_SpriteGraveyard.setPosition(_position);
	
	// Cf. Test.cpp for the magic numbers
	_SpriteGraveyard.setScale(73/_SpriteGraveyard.getLocalBounds().width,100/_SpriteGraveyard.getLocalBounds().height);
	
	// Only draw top card :
	CardRenderer * _renderer = (this->cards.at(this->cards.size()-1).get());
	
	// Card's relative position and scale :
	_renderer->setPosition(_card_position + _position);
	_renderer->setScale(73/_renderer->getLocalBounds().width,100/_renderer->getLocalBounds().height);
	
	target.draw(*_renderer, states);
}

