#include "Serializable.h"

using namespace std;
using namespace state;

Json::Value Serializable::serialize() {
	Json::Value emptyJson;
	return emptyJson;
}

void Serializable::deserialize(Json::Value json) {

}
