#include "Command.h"

using  namespace engine;

CommandID Command::getId() const {
    return this->id;
}
void Command::setId(CommandID id){
    this->id =id;
}
