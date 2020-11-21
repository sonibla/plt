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
	
	this->notify(); // Indirect call to RenderingManager
}
 
void ExileRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Create a sprite with background texture :
	sf::Texture texture;
	texture.loadFromFile("../res/textures/denim.png");
	sf::Sprite SpriteExile(texture);
	SpriteExile.setPosition(0,0); // Position relatively to this. Relatively to the window : (186,778)
	// Cf. Test.cpp for the magic numbers
	SpriteExile.setScale(73/SpriteExile.getLocalBounds().width,100/SpriteExile.getLocalBounds().height);
	
	// Only draw top card :
	CardRenderer * renderer = (this->cards.at(this->cards.size()-1).get());
	
	// Card's relative position and scale :
	renderer->setPosition(20,20);
	renderer->setScale(73/_renderer.getLocalBounds().width,100/_renderer.getLocalBounds().height);
	
	target.draw(*renderer, states);
}
