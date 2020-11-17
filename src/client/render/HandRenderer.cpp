#include "HandRenderer.h"

HandRenderer::HandRenderer (std::weak_ptr<state::Hand> hand) {
	this->hand = hand;
}

HandRenderer::~HandRenderer () {}

HandRenderer::update (state::IObservable* obj) {
	this->cards = obj->cards;
	std::shared_ptr<RenderingManager> manager = RenderingManager.GetInstance().lock();
	manager->update();
}

HandRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	for (size_t i = 0; i < this->cards.size(); i++){
		// Draw cards
		target.draw (cards[i], states);
    }
}
