#include "GraveyardRenderer.h"

using namespace std;
using namespace render;

GraveyardRenderer::GraveyardRenderer (std::weak_ptr<state::Graveyard> graveyard) {
	this->graveyard = graveyard;
}

GraveyardRenderer::~GraveyardRenderer () {}
/*
void GraveyardRenderer::update (state::IObservable* obj) {
	this->cards = obj->cards;
	std::shared_ptr<RenderingManager> manager = RenderingManager.GetInstance().lock();
	manager->update();
}

void GraveyardRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Only draw top card :
	target.draw(this->cards.at(this->cards.size()-1), states);
}
*/
