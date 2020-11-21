#include "GraveyardRenderer.h"

using namespace std;
using namespace render;
using namespace state;

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
		shared_ptr<CardRenderer> _newRenderer (new CardRenderer(weak_ptr<Card>(this->graveyard.lock()->cards.at(i))));
		this->cards.push_back(_newRenderer);
	}
	
	this->notify(); // Indirect call to RenderingManager
}

void GraveyardRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Create a sprite with background texture :
	sf::Texture _texture;
	_texture.loadFromFile("../res/textures/denim.png");
	sf::Sprite _SpriteGraveyard(_texture);
	_SpriteGraveyard.setPosition(0,0); // Position relatively to this. Relatively to the window : (186,890)
	// Cf. Test.cpp for the magic numbers
	_SpriteGraveyard.setScale(73/_SpriteGraveyard.getLocalBounds().width,100/_SpriteGraveyard.getLocalBounds().height);
	
	// Only draw top card :
	CardRenderer * _renderer = (this->cards.at(this->cards.size()-1).get());
	
	// Card's relative position and scale :
	_renderer->setPosition(20,20);
	_renderer->setScale(73/__renderer->getLocalBounds().width,100/__renderer->getLocalBounds().height);
	
	target.draw(*_renderer, states);
}

