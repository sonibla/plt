#include "LibraryRenderer.h"

using namespace std;
using namespace render;

LibraryRenderer::LibraryRenderer (std::weak_ptr<state::Library> library) {
	this->library = library;
}

LibraryRenderer::~LibraryRenderer () {}

void LibraryRenderer::update (state::IObservable* obj) {
	this->cards = obj->cards;
	std::shared_ptr<RenderingManager> manager = RenderingManager.GetInstance().lock();
	manager->update();
}

void LibraryRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Only draw top card :
	target.draw(this->cards.at(this->cards.size()-1), states);
}
