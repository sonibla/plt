#include "GraveyardRenderer.h"

using namespace std;
using namespace render;

GraveyardRenderer::GraveyardRenderer (std::weak_ptr<state::Graveyard> graveyard) {
	this->graveyard = graveyard;
	this->graveyard.lock()->addObserver(this);
	this->update((state::IObservable*) this->graveyard.lock().get());
}

GraveyardRenderer::~GraveyardRenderer () {
	this->cards.clear();
	this->graveyard.lock()->removeObserver(this);
}

void GraveyardRenderer::update (state::IObservable* obj) {
	this->cards.clear();
	for (size_t i = 0; i<this->graveyard.lock()->cards.size(); i++) {
		// Create unique pointers for every card in the zone
		unique_ptr<CardRenderer> newRenderer (new CardRenderer(weak_ptr<Card>(this->graveyard.lock()->cards.at(i)));
		this->cards.push_back(newRenderer);
	}
	
	std::shared_ptr<RenderingManager> manager = RenderingManager.GetInstance().lock();
	manager->update();
}

void GraveyardRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Only draw top card :
	target.draw(this->cards.at(this->cards.size()-1), states);
}

