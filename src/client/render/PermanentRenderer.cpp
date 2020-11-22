#include "PermanentRenderer.h"

using namespace std;
using namespace render;


PermanentRenderer::PermanentRenderer (std::weak_ptr<state::Permanent> permanent){

    std::shared_ptr<state::Permanent> _permanent = permanent.lock();
    sf::Texture texture_load;
    texture_load.loadFromFile(_permanent->image_location);
    this->texture = texture_load;
    this->setTexture(this->texture);
    if (_permanent->tapped){
        this->setRotation(90);
    }
    else{
        this->setRotation(0);
    }
}


PermanentRenderer::~PermanentRenderer (){

};
