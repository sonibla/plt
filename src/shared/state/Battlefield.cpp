#include "Battlefield.h"

using namespace std;
using namespace state;

Battlefield::Battlefield() {}
Battlefield::~Battlefield() {}


std::vector<std::weak_ptr<Permanent>> Battlefield::GetPermanents (){
    std::vector<std::weak_ptr<Permanent>> _permanents;
    for(size_t i =0; i<permanents.size();i++){
        _permanents.push_back(permanents[i]);
    }
    return _permanents;
}



void Battlefield::SetPermanents (std::vector<std::shared_ptr<Permanent>> permanents){
    this->permanents = permanents;
};
