//
// Created by maxime on 26/10/2020.
//

#include "Test.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>


using namespace client;
using namespace state;

std::vector<std::shared_ptr<Card>> create_cards_placeholder(){
    std::vector<std::shared_ptr<Card>> _cards;
    for(int i =0; i<6;i++){
        std::shared_ptr<Card> _card = std::make_shared<Card>();
        //art of a black lotus
        _card->image_uri = "https://c1.scryfall.com/file/scryfall-cards/large/front/b/a/bad6b494-d773-4f7d-ac39-85d82e1d3015.jpg";
        _card->name = "Place Holder";
        _cards.push_back(_card);
    }
    return _cards;
}

std::shared_ptr<Player> create_player_placeholder(){

    std::shared_ptr<Player> _player = std::make_shared<Player>();
    std::weak_ptr<Graveyard> _graveyard = _player->GetGraveyard();
    _graveyard.lock()->SetCards(create_cards_placeholder());
    std::weak_ptr<Library> _library = _player->GetLibrary();
    _library.lock()->SetCards(create_cards_placeholder());
    std::weak_ptr<Hand> _hand = _player->GetHand();
    _hand.lock()->SetCards(create_cards_placeholder());
    return _player;
}

void Test::state(){
    std::vector<std::shared_ptr<Player>> _players;

    std::shared_ptr<Player> _player = create_player_placeholder();
    _players.push_back(_player);
    _player = create_player_placeholder();
    _players.push_back(_player);
    
    std::weak_ptr<Game> game = Game::GetInstance();
    auto _game = game.lock();
    _game->GetExile().lock()->SetCards(create_cards_placeholder());
    _game->SetPlayers(_players);

    std::cout << _game->GetPlayers().size() << std::endl;
}


//Test Render


void Test::render(){

	
    int numPlayerHand = 1;
    int numOpponentHand = 3;
    int numPlayerPermanent = 3;
    int numOpponentPermanent = 2;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Rendering");

    // Load a sprite to display
    sf::Texture texture;
    texture.loadFromFile("../res/textures/card.png");

    sf::Texture hand_texture;
    hand_texture.loadFromFile("../res/textures/grey_wash_wall.png");

    sf::Texture hub_texture;
    hub_texture.loadFromFile("../res/textures/denim.png");

    sf::Texture bf_texture;
    bf_texture.loadFromFile("../res/textures/concrete_wall.png");
    
    // Card Sprite
    sf::Sprite sprite(texture);
    sprite.setScale(73/sprite.getLocalBounds().width,100/sprite.getLocalBounds().height);

    //Setting Player Side
    sf::Sprite PlayerHub(hub_texture);
    PlayerHub.setPosition(10,690);
    PlayerHub.setScale(150/PlayerHub.getLocalBounds().width,300/PlayerHub.getLocalBounds().height);

    sf::Sprite PlayerExile(texture);
    PlayerExile.setPosition(186,778);
    PlayerExile.setScale(73/PlayerExile.getLocalBounds().width,100/PlayerExile.getLocalBounds().height);

    sf::Sprite PlayerGraveyard(texture);
    PlayerGraveyard.setPosition(186,890);
    PlayerGraveyard.setScale(73/PlayerGraveyard.getLocalBounds().width,100/PlayerGraveyard.getLocalBounds().height);

    sf::Sprite PlayerLibrary(texture);
    PlayerLibrary.setPosition(916,890);
    PlayerLibrary.setScale(73/PlayerLibrary.getLocalBounds().width,100/PlayerLibrary.getLocalBounds().height);

    sf::Sprite PlayerHand(hand_texture);
    PlayerHand.setPosition(272,790);
    PlayerHand.setScale(631/PlayerHand.getLocalBounds().width,200/PlayerHand.getLocalBounds().height);


    //Setting Opponent Side
    sf::Sprite OpponentHub(hub_texture);
    OpponentHub.setPosition(10,10);
    OpponentHub.setScale(150/OpponentHub.getLocalBounds().width,300/OpponentHub.getLocalBounds().height);

    sf::Sprite OpponentExile(texture);
    OpponentExile.setPosition(916,122);
    OpponentExile.setScale(73/OpponentExile.getLocalBounds().width,100/OpponentExile.getLocalBounds().height);

    sf::Sprite OpponentGraveyard(texture);
    OpponentGraveyard.setPosition(916,10);
    OpponentGraveyard.setScale(73/OpponentGraveyard.getLocalBounds().width,100/OpponentGraveyard.getLocalBounds().height);

    sf::Sprite OpponentLibrary(texture);
    OpponentLibrary.setPosition(186,10);
    OpponentLibrary.setScale(73/OpponentLibrary.getLocalBounds().width,100/OpponentLibrary.getLocalBounds().height);

    sf::Sprite OpponentHand(hand_texture);
    OpponentHand.setPosition(272,10);
    OpponentHand.setScale(631/OpponentHand.getLocalBounds().width,200/OpponentHand.getLocalBounds().height);


    //Setting the Battlefield
    sf::Sprite Battlefield(bf_texture);
    Battlefield.setPosition(272,320);
    Battlefield.setScale(631/Battlefield.getLocalBounds().width,360/Battlefield.getLocalBounds().height);


    //Setting the cards drawing

    // Draw Player Hand
    std::vector<sf::Sprite> HandCardVect;
    sf::Sprite CardBuffer(texture);
    CardBuffer.setScale(146/CardBuffer.getLocalBounds().width,200/CardBuffer.getLocalBounds().height);
	int CardCenter = 73;
	for (int i = 0; i < numPlayerHand; i++){
            HandCardVect.push_back(CardBuffer);
            HandCardVect[i].setPosition(272 + (i+1)*(631/numPlayerHand+1) - CardCenter, 790);
        }
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(PlayerLibrary);
        window.draw(PlayerExile);
        window.draw(PlayerGraveyard);
        window.draw(PlayerHub);
        window.draw(PlayerHand);

        window.draw(OpponentLibrary);
        window.draw(OpponentExile);
        window.draw(OpponentGraveyard);
        window.draw(OpponentHub);
        window.draw(OpponentHand);

	window.draw(Battlefield);


        // Draw Cards

/*
	for (int i = 0; i < numPlayerHand; i++){
            window.draw(HandCardVect[i]);
        }
*/
        // Update the window
        window.display();
    }


}
