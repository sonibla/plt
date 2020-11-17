#include "LibraryRenderer.h"

LibraryRenderer::LibraryRenderer (std::weak_ptr<state::Library> library) {
	this->library = library;
}

LibraryRenderer::~LibraryRenderer () {}

LibraryRenderer::update (state::IObservable* obj) {
	this->cards = obj->cards;
	std::weak_ptr<RenderingManager> manager = RenderingManager.GetInstance();
	manager->update();
}

LibraryRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {}
