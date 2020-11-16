#include "HandRenderer.h"

HandRenderer::HandRenderer (std::weak_ptr<state::Hand> hand) {}
HandRenderer::~HandRenderer () {}

HandRenderer::update (state::IObservable* obj) {}
HandRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const {}
