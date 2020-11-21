#include "HandRenderer.h"

using namespace std;
using namespace render;
using namespace state;

HandRenderer::HandRenderer (std::weak_ptr<state::Hand> hand) {
	this->hand = hand;
	this->hand.lock()->addObserver(this);
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
		shared_ptr<CardRenderer> newRenderer (new CardRenderer(weak_ptr<Card>(this->hand.lock()->cards.at(i))));
		this->cards.push_back(newRenderer);
	}
	
	this->notify(); // Indirect call to RenderingManager
}

void HandRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Create a sprite with background texture :
	sf::Texture texture;
	texture.loadFromFile("../res/textures/denim.png");
	sf::Sprite SpriteHand(texture);
	SpriteHand.setPosition(0,0); // Position relatively to this. Relatively to the window : (272,790)
	// Cf. Test.cpp for the magic numbers
	SpriteHand.setScale(631/SpriteHand.getLocalBounds().width,200/SpriteHand.getLocalBounds().height);
	
	// Draw cards
	for (size_t i = 0; i < this->cards.size(); i++){
		CardRenderer * renderer = (this->cards.at(i).get());
		
		// Card's relative position and scale :
		renderer->setPosition(10 + i*90, 0);
		renderer->setScale(73/_renderer.getLocalBounds().width,100/_renderer.getLocalBounds().height);
		
		target.draw(*renderer, states);
    }
}

