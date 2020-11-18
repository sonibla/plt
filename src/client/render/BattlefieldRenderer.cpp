#include "BattlefieldRenderer.h"

using namespace std;
using namespace render;


BattlefieldRenderer::BattlefieldRenderer (std::weak_ptr<state::Battlefield> battlefield){
    this->battlefield = battlefield;
    std::shared_ptr<state::Battlefield> _battlefield = battlefield.lock();
    _battlefield->addObserver(this);

    std::vector<std::weak_ptr<state::Permanent>> _statePermanents = _battlefield->GetPermanent

    this.update(_battlefield);
}

BattlefieldRenderer::update(state::IObservable* _battlefield){
    for (size_t i=0; i<_battlefield->battlefieldContent.size();i++){
        this.permanents->push_back(PermanentRenderer::PermanentRenderer(_battlefield->battlefieldContent))
    }
}
