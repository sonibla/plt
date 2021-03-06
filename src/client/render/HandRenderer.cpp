#include "HandRenderer.h"

using namespace std;
using namespace render;
using namespace state;

HandRenderer::HandRenderer (std::weak_ptr<state::Hand> hand, sf::Vector2f position) {
	this->hand = hand;
	this->hand.lock()->addObserver(this);
	this->setPosition(position);
	this->texture.loadFromFile("../res/textures/denim.png");
	this->update((state::IObservable*) this->hand.lock().get(),state::EventID::UPDATE);
}

HandRenderer::~HandRenderer () {
	this->cards.clear();
	this->hand.lock()->removeObserver(this);
}

void HandRenderer::update (state::IObservable* obj,state::EventID eventID) {
	this->cards.clear();
	for (size_t i = 0; i<this->hand.lock()->cards.size(); i++) {
		// Create unique pointers for every card in the zone
		shared_ptr<CardRenderer> _newRenderer (new CardRenderer(weak_ptr<Card>(this->hand.lock()->cards.at(i))));
		this->cards.push_back(_newRenderer);
	}
	
	this->notify(eventID); // Indirect call to RenderingManager
}

void HandRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Get my position:
	sf::Vector2f _position = this->getPosition();
	
	// Create a sprite with background texture :
	sf::Sprite _SpriteHand(this->texture);
	_SpriteHand.setPosition(_position);
	
	// Cf. Test.cpp for the magic numbers
	_SpriteHand.setScale(631/_SpriteHand.getLocalBounds().width,200/_SpriteHand.getLocalBounds().height);
	
    // Draw background
	target.draw(_SpriteHand);
	
	// Draw cards
	for (size_t i = 0; i < this->cards.size(); i++){
		CardRenderer * _renderer = (this->cards.at(i).get());
		
		// Card's relative position and scale :
		_renderer->setPosition(_position.x + 10 + i*90, _position.y);
		_renderer->setScale(73/_renderer->getLocalBounds().width,100/_renderer->getLocalBounds().height);
		
		target.draw(*_renderer);
    }
}

