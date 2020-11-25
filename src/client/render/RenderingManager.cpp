

#include "RenderingManager.h"


using namespace std;
using namespace render;

RenderingManager::RenderingManager(){
    /*window.create(sf::VideoMode(1000, 1000), "Rendering");
    std::shared_ptr<state::Game> _game = state::Game::GetInstance().lock();

    std::vector<std::weak_ptr<state::Player>> _players = _game->GetPlayers();
    
    for(std::size_t i =0;i<_players.size();i++){
        std::shared_ptr<state::Player> _player = _players[i].lock();

        zoneRenderers.push_back(std::unique_ptr<ZoneRenderer>(new PlayerRenderer(_player)));
        zoneRenderers.push_back(std::unique_ptr<ZoneRenderer>(new GraveyardRenderer(_player->GetGraveyard())));
        zoneRenderers.push_back(std::unique_ptr<ZoneRenderer>(new HandRenderer(_player->GetHand())));
        zoneRenderers.push_back(std::unique_ptr<ZoneRenderer>(new LibraryRenderer(_player->GetLibrary())));
    }

    zoneRenderers.push_back(std::unique_ptr<ZoneRenderer>(new BattlefieldRenderer(_game->GetBattlefield())));
    zoneRenderers.push_back(std::unique_ptr<ZoneRenderer>(new ExileRenderer(_game->GetExile())));
    zoneRenderers.push_back(std::unique_ptr<ZoneRenderer>(new StackRenderer(_game->GetStack())));
    */
}

void RenderingManager::update (state::IObservable* state){
    /*window.clear();
    for(std::size_t i =0;i<zoneRenderers.size();i++){
        window.draw(*(zoneRenderers[i]));
    }
    window.display(); 
    */
}

