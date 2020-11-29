#include "GraveyardRenderer.h"

using namespace std;
using namespace render;
using namespace state;

GraveyardRenderer::GraveyardRenderer (std::weak_ptr<state::Graveyard> graveyard, sf::Vector2f position) {
	this->graveyard = graveyard;
	this->graveyard.lock()->addObserver(this);
	this->setPosition(position);
	this->texture.loadFromFile("../res/textures/denim.png");
	this->update((state::IObservable*) this->graveyard.lock().get(),state::EventID::UPDATE);
}

GraveyardRenderer::~GraveyardRenderer () {
	this->cards.clear();
	this->graveyard.lock()->removeObserver(this);
}

void GraveyardRenderer::update (state::IObservable* obj,state::EventID eventID) {
	this->cards.clear();
	for (size_t i = 0; i<this->graveyard.lock()->cards.size(); i++) {
		// Create unique pointers for every card in the zone
		shared_ptr<CardRenderer> _newRenderer (new CardRenderer(weak_ptr<Card>(this->graveyard.lock()->cards.at(i))));
		this->cards.push_back(_newRenderer);
	}
	
	this->notify(eventID); // Indirect call to RenderingManager
}

void GraveyardRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Get my position:
	sf::Vector2f _position = this->getPosition();
	
	// Card's relative position:
	sf::Vector2f _card_position(20.f, 20.f);
	
	// Create a sprite with background texture :
	sf::Sprite _SpriteGraveyard(this->texture);
	_SpriteGraveyard.setPosition(_position);
	
	// Cf. Test.cpp for the magic numbers
	_SpriteGraveyard.setScale(73/_SpriteGraveyard.getLocalBounds().width,100/_SpriteGraveyard.getLocalBounds().height);
	
	// Only draw top card :
	CardRenderer * _renderer = (this->cards.at(this->cards.size()-1).get());
	
	// Card's relative position and scale :
	_renderer->setPosition(_card_position + _position);
	_renderer->setScale(73/_renderer->getLocalBounds().width,100/_renderer->getLocalBounds().height);
	
    // Draw background
	target.draw(_SpriteGraveyard);
	
	// Draw card
	target.draw(*_renderer);
}

