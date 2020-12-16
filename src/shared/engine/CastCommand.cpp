#include "CastCommand.h"

using namespace engine;

CastCommand::CastCommand(int cardID){
    this->id = CommandID::CAST;
    this->cardID = cardID;
}

void CastCommand::execute (std::shared_ptr<state::Game> game){

}

bool CastCommand::verify (std::shared_ptr<state::Game> game){

}
