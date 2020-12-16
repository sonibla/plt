#include "PlayableGameElement.h"

using namespace std;
using namespace state;

    Json::Value PlayableGameElement::serialize () {
        Json::Value json;

        /*
        std::string color;
        int cmc;
        std::set<std::string> types;

        json["color"] = color;
        json["cmc"] = cmc;
        json["color"] = color;

        for (int i(0); i<this->types.size(); i++)
	    {
		json["players"][i] = types[i];
	    }

        return json;
        */
    }

    void PlayableGameElement::deserialize (Json::Value json) {

    }