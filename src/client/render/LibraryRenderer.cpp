#include "LibraryRenderer.h"

using namespace std;
using namespace render;
using namespace state;

LibraryRenderer::LibraryRenderer (std::weak_ptr<state::Library> library) {
	this->library = library;
	this->library.lock()->addObserver(this);
	this->update((state::IObservable*) this->library.lock().get());
}

LibraryRenderer::~LibraryRenderer () {
	this->cards.clear();
	this->library.lock()->removeObserver(this);
}

void LibraryRenderer::update (state::IObservable* obj) {
	this->cards.clear();
	for (size_t i = 0; i<this->library.lock()->cards.size(); i++) {
		// Create unique pointers for every card in the zone
		shared_ptr<CardRenderer> newRenderer (new CardRenderer(weak_ptr<Card>(this->library.lock()->cards.at(i))));
		this->cards.push_back(newRenderer);
	}
	
	this->notify(); // Indirect call to RenderingManager
}

void LibraryRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	// Create a sprite with background texture :
	sf::Texture texture;
	texture.loadFromFile("../res/textures/denim.png");
	sf::Sprite SpriteLibrary(texture);
	SpriteLibrary.setPosition(0,0); // Position relatively to this. Relatively to the window : (916,890)
	// Cf. Test.cpp for the magic numbers
	SpriteLibrary.setScale(73/SpriteLibrary.getLocalBounds().width,100/SpriteLibrary.getLocalBounds().height);
	
	// Only draw top card :
	CardRenderer * renderer = (this->cards.at(this->cards.size()-1).get());
	target.draw(*renderer, states);
	
	// Card's relative position and scale :
	renderer->setPosition(20,20);
	renderer->setScale(73/_renderer.getLocalBounds().width,100/_renderer.getLocalBounds().height);
}

