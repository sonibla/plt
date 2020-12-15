#include "Engine.h"

using namespace engine;

Engine::Engine(std::shared_ptr<state::Game> game){
    this->game = game;
}

Engine::~Engine(){

}

void Engine::execute (std::shared_ptr<Command> command){
    command->execute(game);
}

bool Engine::verify (std::shared_ptr<Command> command){
    return command->verify(game);
}

void Engine::start(){
    // to be implemented later.
}