#include "Battlefield.h"

using namespace std;
using namespace state;

Battlefield::Battlefield() {}
Battlefield::~Battlefield() {}


std::vector<std::weak_ptr<Permanent>> Battlefield::getPermanents (){
    std::vector<std::weak_ptr<Permanent>> _permanents;
    for(size_t i =0; i<permanents.size();i++){
        _permanents.push_back(permanents[i]);
    }
    return _permanents;
}

void Battlefield::setPermanents (std::vector<std::shared_ptr<Permanent>> permanents){
    this->permanents = permanents;
};

Json::Value Battlefield::serialize() {
	Json::Value json;

    for (int i(0); i<this->permanents.size(); i++)
	{
		json["permanents"][i] = this->permanents[i]->serialize();
	}
	
	return json;
}


void Battlefield::deserialize (Json::Value json) {
    for (Json::ArrayIndex i(0); i<json["permanents"].size(); i++)
	{
		this->permanents[i]->serialize()= json["permanents"][i];
	}
}