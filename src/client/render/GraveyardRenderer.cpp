#include "GraveyardRenderer.h"

GraveyardRenderer::GraveyardRenderer (std::weak_ptr<state::Graveyard> graveyard) {
	this->graveyard = graveyard;
}

GraveyardRenderer::~GraveyardRenderer () {}

GraveyardRenderer::update (state::IObservable* obj) {
	this->cards = obj->cards;
	std::shared_ptr<RenderingManager> manager = RenderingManager.GetInstance().lock();
	manager->update();
}

GraveyardRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {}

