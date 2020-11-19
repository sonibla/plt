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
	// Draw cards
	for (size_t i = 0; i < this->cards.size(); i++){
		target.draw(*(this->cards.at(this->cards.size()-1).get()), states);
    }
}

