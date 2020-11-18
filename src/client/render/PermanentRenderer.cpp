#include "PermanentRenderer.h"

using namespace std;
using namespace render;


PermanentRenderer::PermanentRenderer (std::weak_ptr<state::Permanent> permanent){

    std::shared_ptr<state::Permanent> _permanent = permanent.lock();
    sf::Texture texture;
    texture.loadFromFile(_permanent->image_location);
    this->setTexture(texture);
    if (_permanent->tapped){
        this->setRotation(90);
    }
    else{
        this->setRotation(0);
    }
}
