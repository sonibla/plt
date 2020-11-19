#include "LibraryRenderer.h"

using namespace std;
using namespace render;
using namespace state;

LibraryRenderer::LibraryRenderer (std::weak_ptr<state::Library> library) {
	this->library = library;
	this->library.lock()->addObserver(this);
	this->update((state::IObservable*) this->library.lock().get());
}

LibraryRenderer::~LibraryRenderer () {
	this->cards.clear();
	this->library.lock()->removeObserver(this);
}

void LibraryRenderer::update (state::IObservable* obj) {
	this->cards.clear();
	for (size_t i = 0; i<this->library.lock()->cards.size(); i++) {
		// Create unique pointers for every card in the zone
		unique_ptr<CardRenderer> newRenderer (new CardRenderer(weak_ptr<Card>(this->library.lock()->cards.at(i)));
		this->cards.push_back(newRenderer);
	}
	
	std::shared_ptr<RenderingManager> manager = RenderingManager.GetInstance().lock();
	manager->update();
}

void LibraryRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Only draw top card :
	target.draw(this->cards.at(this->cards.size()-1), states);
}

