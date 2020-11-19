#include "BattlefieldRenderer.h"

using namespace std;
using namespace render;


BattlefieldRenderer::BattlefieldRenderer (std::weak_ptr<state::Battlefield> battlefield){
    this->battlefield = battlefield;
    std::shared_ptr<state::Battlefield> _battlefield = battlefield.lock();
    _battlefield->addObserver(this);

    std::vector<std::unique_ptr<PermanentRenderer>> permanents;

    //this->update(battlefield);
}

void BattlefieldRenderer::update(state::IObservable* obj){


    std::shared_ptr<state::Battlefield> _battlefield = this->battlefield.lock();

    std::vector<std::weak_ptr<state::Permanent>> list_permanents = _battlefield->GetPermanents();

    for (size_t i=0; i<list_permanents.size();i++){
        render::PermanentRenderer rendered_permanent(list_permanents[i]);
        std::unique_ptr<PermanentRenderer> _rendered_permanent;
        this->permanents.push_back(_rendered_permanent);
    }
}