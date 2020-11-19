#include "ExileRenderer.h"

using namespace std;
using namespace render;
using namespace state;

ExileRenderer::ExileRenderer (std::weak_ptr<state::Exile> exile) {
	this->exile = exile;
	this->exile.lock()->addObserver(this);
	this->update((state::IObservable*) this->exile.lock().get());
}

ExileRenderer::~ExileRenderer () {
	this->cards.clear();
	this->exile.lock()->removeObserver(this);
}

void ExileRenderer::update (state::IObservable* obj) {
	this->cards.clear();
	for (size_t i = 0; i<this->exile.lock()->cards.size(); i++) {
		// Create unique pointers for every card in the zone
		shared_ptr<CardRenderer> newRenderer (new CardRenderer(weak_ptr<Card>(this->exile.lock()->cards.at(i))));
		this->cards.push_back(newRenderer);
	}
	
	std::shared_ptr<RenderingManager> manager = RenderingManager::GetInstance().lock();
	manager->update();
}
 
void ExileRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Only draw top card :
	target.draw(*(this->cards.at(this->cards.size()-1).get()), states);
}
