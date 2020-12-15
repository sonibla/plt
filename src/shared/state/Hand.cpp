//
// Created by maxime on 13/10/2020.
//

#include "Hand.h"
using namespace state;
using namespace std;

Hand::Hand() {}
Hand::~Hand() {}

Json::Value Hand::serialize () {

    Json::Value json;

    //int maximumHandSize     = 7;
    //int startingHandSize     = 7;

    json["maximumHandSize"] = maximumHandSize;
    json["startingHandSize"] = startingHandSize;

    return json;
}

void Hand::deserialize (Json::Value json) {
    maximumHandSize = json["maximumHandSize"].isInt();
    startingHandSize = json["startingHandSize"].isInt();
}
