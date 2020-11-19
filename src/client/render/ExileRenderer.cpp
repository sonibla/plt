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
	// Only draw top card :
	target.draw(this->cards.at(this->cards.size()-1), states);
}
*/
