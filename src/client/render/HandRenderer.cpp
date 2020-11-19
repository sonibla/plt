#include "HandRenderer.h"

using namespace std;
using namespace render;
#include <algorithm>

HandRenderer::HandRenderer (std::weak_ptr<state::Hand> hand) {
	this->hand = hand;
}

HandRenderer::~HandRenderer () {}

void HandRenderer::update (state::IObservable* obj) {
	this->cards = obj->cards;
	std::shared_ptr<RenderingManager> manager = RenderingManager.GetInstance().lock();
	manager->update();
}

void HandRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Draw at most 7 cards
	for (size_t i = 0; i < max(this->cards.size(), 7); i++){
		target.draw (this->cards[i], states);
    }
}

