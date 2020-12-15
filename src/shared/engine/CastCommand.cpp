#include "CastCommand.h"

using namespace engine;

CastCommand::CastCommand(int cardID){
    this->id = CommandID::CAST;
    this->cardID = cardID;
}

CastCommand::~CastCommand(){

}
