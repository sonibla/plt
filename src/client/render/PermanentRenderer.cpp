#include "PermanentRenderer.h"


PermanentRenderer::PermanentRenderer (state::Permanent permanent){
    PermanentRenderer.setTexture(permanent.image_location)
    if (permanent.tapped){
        PermanentRenderer.setRotation(45);
    }
    else{
        PermanentRenderer.setRotation(0);
    }
    
}