#include "TargetCommand.h"

using namespace engine;

TargetCommand::TargetCommand(std::vector<int> targetIDs){
    this->id = CommandID::TARGET;
    this->targetIDs = targetIDs;
}
