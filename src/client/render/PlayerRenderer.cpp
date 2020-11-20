
#include "PlayerRenderer.h"
using namespace render;
using namespace std;


PlayerRenderer::PlayerRenderer(std::weak_ptr<state::Player> player){
    
}
PlayerRenderer::~PlayerRenderer (){

}
void PlayerRenderer::update (state::IObservable* obj){

}



void PlayerRenderer::draw (sf::RenderTarget &target, sf::RenderStates states) const{
    
    int PlayerHP = 4;

    sf::Texture hub_texture;
    hub_texture.loadFromFile("../res/textures/denim.png");
    sf::Font font;
    font.loadFromFile("../res/fonts/arial.ttf");


    sf::Sprite PlayerHub(hub_texture);
    PlayerHub.setPosition(10,690);
    PlayerHub.setScale(150/PlayerHub.getLocalBounds().width,300/PlayerHub.getLocalBounds().height);
    
    std::string PlayerString = std::string("Player \nHP :") + std::to_string(PlayerHP);
    sf::Text PlayerHubText(PlayerString, font);
    PlayerHubText.setCharacterSize(30);
    PlayerHubText.setPosition(20,710);

    target.draw(PlayerHub);
    target.draw(PlayerHubText);

}