#include "ExileRenderer.h"

ExileRenderer::ExileRenderer (std::weak_ptr<state::Exile> exile) {
	this->exile = exile;
}

ExileRenderer::~ExileRenderer () {}

ExileRenderer::update (state::IObservable* obj) {
	this->cards = obj->cards;
	std::shared_ptr<RenderingManager> manager = RenderingManager.GetInstance().lock();
	manager->update();
}

ExileRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {}
