#include "LibraryRenderer.h"

LibraryRenderer::LibraryRenderer (std::weak_ptr<state::Library> library) {
	this->library = library;
}

LibraryRenderer::~LibraryRenderer () {}

LibraryRenderer::update (state::IObservable* obj) {
	this->cards = obj->cards;
	std::shared_ptr<RenderingManager> manager = RenderingManager.GetInstance().lock();
	manager->update();
}

LibraryRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	for (size_t i = 0; i < this->cards.size(); i++){
		// Draw cards
		target.draw (cards[i], states);
    }
}
