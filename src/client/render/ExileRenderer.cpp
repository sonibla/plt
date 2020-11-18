#include "ExileRenderer.h"

using namespace std;
using namespace render;

ExileRenderer::ExileRenderer (std::weak_ptr<state::Exile> exile) {
	this->exile = exile;
}

ExileRenderer::~ExileRenderer () {}
/*
void ExileRenderer::update (state::IObservable* obj) {
	this->cards = obj->cards;
	std::shared_ptr<RenderingManager> manager = RenderingManager.GetInstance().lock();
	manager->update();
}


 
void ExileRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	for (size_t i = 0; i < this->cards.size(); i++){
		// Draw cards
		target.draw(this->cards[i], states);
    }
}
*/