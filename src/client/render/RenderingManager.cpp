

#include "RenderingManager.h"


using namespace std;
using namespace render;

RenderingManager::RenderingManager(){
    this->window.create(sf::VideoMode(1000, 1000), "Rendering");
    std::shared_ptr<state::Game> _game = state::Game::getInstance().lock();

    std::vector<std::weak_ptr<state::Player>> _players = _game->getPlayers();
    
    int id_of_the_current_player=1; // To be changed later

    for(std::size_t i =0;i<_players.size();i++){
        std::shared_ptr<state::Player> _player = _players[i].lock();
        if(id_of_the_current_player == _player->getID()){
            zoneRenderers.push_back(std::shared_ptr<ZoneRenderer>(new PlayerRenderer(_player, sf::Vector2f(10, 690))));
            zoneRenderers.push_back(std::shared_ptr<ZoneRenderer>(new GraveyardRenderer(_player->getGraveyard(), sf::Vector2f(186, 890))));
            zoneRenderers.push_back(std::shared_ptr<ZoneRenderer>(new HandRenderer(_player->getHand(), sf::Vector2f(272, 790))));
            zoneRenderers.push_back(std::shared_ptr<ZoneRenderer>(new LibraryRenderer(_player->getLibrary(), sf::Vector2f(916, 890))));
        }
        else{
            zoneRenderers.push_back(std::shared_ptr<ZoneRenderer>(new PlayerRenderer(_player, sf::Vector2f(10, 20))));
            zoneRenderers.push_back(std::shared_ptr<ZoneRenderer>(new GraveyardRenderer(_player->getGraveyard(), sf::Vector2f(186, 220))));
            zoneRenderers.push_back(std::shared_ptr<ZoneRenderer>(new HandRenderer(_player->getHand(), sf::Vector2f(272, 10))));
            zoneRenderers.push_back(std::shared_ptr<ZoneRenderer>(new LibraryRenderer(_player->getLibrary(), sf::Vector2f(916, 220))));
        }
    }
    
    zoneRenderers.push_back(std::shared_ptr<ZoneRenderer>(new BattlefieldRenderer(_game->getBattlefield(), sf::Vector2f(272, 220))));
    zoneRenderers.push_back(std::shared_ptr<ZoneRenderer>(new ExileRenderer(_game->getExile(), sf::Vector2f(186, 778))));
    //zoneRenderers.push_back(std::shared_ptr<ZoneRenderer>(new StackRenderer(_game->getStack(), sf::Vector2f(, )))); // A placer par dessus le battlefield

}
RenderingManager::~RenderingManager(){

}

void RenderingManager::update (state::IObservable* state,state::EventID eventID){
    this->window.clear();
    for(std::size_t i =0;i<zoneRenderers.size();i++){
        this->window.draw(*(zoneRenderers[i]));
    }
    this->window.display(); 
}

