#include "HandRenderer.h"

HandRenderer::HandRenderer (std::weak_ptr<state::Hand> hand) {
	this->hand = hand;
}

HandRenderer::~HandRenderer () {}

HandRenderer::update (state::IObservable* obj) {
	this->cards = obj->cards;
	std::weak_ptr<RenderingManager> manager = RenderingManager.GetInstance();
	manager->update();
}

HandRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	
}
