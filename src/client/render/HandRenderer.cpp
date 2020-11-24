#include "HandRenderer.h"

using namespace std;
using namespace render;
using namespace state;

sf::Vector2f _default_position(272.f, 790.f);

HandRenderer::HandRenderer (std::weak_ptr<state::Hand> hand, sf::Vector2f position) {
	this->hand = hand;
	this->hand.lock()->addObserver(this);
	
	if ((position.x == -1) && (position.y == -1))
	{
		// Default position
		this->setPosition(_default_position);
	}
	else
	{
		this->setPosition(position);
	}
	
	this->update((state::IObservable*) this->hand.lock().get());
}

HandRenderer::~HandRenderer () {
	this->cards.clear();
	this->hand.lock()->removeObserver(this);
}

void HandRenderer::update (state::IObservable* obj) {
	this->cards.clear();
	for (size_t i = 0; i<this->hand.lock()->cards.size(); i++) {
		// Create unique pointers for every card in the zone
		shared_ptr<CardRenderer> _newRenderer (new CardRenderer(weak_ptr<Card>(this->hand.lock()->cards.at(i))));
		this->cards.push_back(_newRenderer);
	}
	
	this->notify(); // Indirect call to RenderingManager
}

void HandRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Get my position:
	sf::Vector2f _position = this->getPosition();
	
	// Create a sprite with background texture :
	sf::Texture _texture;
	_texture.loadFromFile("../res/textures/denim.png");
	sf::Sprite _SpriteHand(_texture);
	_SpriteHand.setPosition(_position);
	
	// Cf. Test.cpp for the magic numbers
	_SpriteHand.setScale(631/_SpriteHand.getLocalBounds().width,200/_SpriteHand.getLocalBounds().height);
	
	// Draw cards
	for (size_t i = 0; i < this->cards.size(); i++){
		CardRenderer * _renderer = (this->cards.at(i).get());
		
		// Card's relative position and scale :
		_renderer->setPosition(_position.x + 10 + i*90, _position.y);
		_renderer->setScale(73/_renderer->getLocalBounds().width,100/_renderer->getLocalBounds().height);
		
		target.draw(*_renderer, states);
    }
}

