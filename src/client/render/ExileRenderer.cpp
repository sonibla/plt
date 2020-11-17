#include "ExileRenderer.h"

ExileRenderer::ExileRenderer (std::weak_ptr<state::Exile> exile) {
	this->exile = exile;
}

ExileRenderer::~ExileRenderer () {}

ExileRenderer::update (state::IObservable* obj) {
	this->cards = obj->cards;
	std::weak_ptr<RenderingManager> manager = RenderingManager.GetInstance();
	manager->update();
}

ExileRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {}
