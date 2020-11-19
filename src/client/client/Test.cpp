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
using namespace render;

std::vector<std::shared_ptr<Card>> create_cards_placeholder(){
    std::vector<std::shared_ptr<Card>> _cards;
    for(int i =0; i<6;i++){
        std::shared_ptr<Card> _card = std::make_shared<Card>();
        //art of a black lotus
        _card->image_location = "../res/textures/card.png";
        _card->name = "Place Holder";
        _cards.push_back(_card);
    }
    return _cards;
}

std::vector<std::shared_ptr<Permanent>> create_permanents_placeholder(){
    std::vector<std::shared_ptr<Permanent>> _permanents;
    for(int i =0; i<6;i++){
        std::shared_ptr<Permanent> _permanent = std::make_shared<Permanent>();
        //art of a black lotus
        _permanent->image_location = "../res/textures/card.png";
        _permanents.push_back(_permanent);
    }
    return _permanents;
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


    std::shared_ptr<state::Battlefield> _battlefield = _game->GetBattlefield().lock();
    _battlefield->SetPermanents(create_permanents_placeholder());

    std::cout << _game->GetPlayers().size() << std::endl;
}


//Test Render


void Test::render(){

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Rendering Test");

    std::shared_ptr<Player> _player = create_player_placeholder();

    auto _game = Game::GetInstance().lock();
    
    std::shared_ptr<state::Battlefield> _battlefield = _game->GetBattlefield().lock();
    std::shared_ptr<state::Permanent> _permanent;

    std::string path;
    path = "../res/textures/card.png";
    _permanent->image_location;

    //render::PermanentRenderer _permanentrenderer(_permanent);

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
        window.clear();
        //window.draw(_permanentrenderer);
        //window.draw(_battlefield);
       window.display();
    }
    /*
    // Declare and load a font
    sf::Font font;
    font.loadFromFile("../res/fonts/arial.ttf");

	
    int numPlayerHand = 7;
    int numOpponentHand = 3;

    int numPlayerPermanent = 5;
    int numOpponentPermanent = 4;

    int numPlayerLand = 3;
    int numOpponentLand = 2 ;

    int PlayerHP = 4;
    int OpponentHP = 3;

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

    sf::Texture bg_texture;
    bg_texture.loadFromFile("../res/textures/dark-honeycomb.png");

    // Background Sprite
    sf::Sprite Background(bg_texture);
    Background.setPosition(0,0);
    Background.setScale(1000/Background.getLocalBounds().width,1000/Background.getLocalBounds().height);
    
    // Card Sprite
    sf::Sprite sprite(texture);
    sprite.setScale(73/sprite.getLocalBounds().width,100/sprite.getLocalBounds().height);

    //Setting Player Side
    sf::Sprite PlayerHub(hub_texture);
    PlayerHub.setPosition(10,690);
    PlayerHub.setScale(150/PlayerHub.getLocalBounds().width,300/PlayerHub.getLocalBounds().height);

    std::string PlayerString = std::string("Player \nHP :") + std::to_string(PlayerHP);
    sf::Text PlayerHubText(PlayerString, font);
    PlayerHubText.setCharacterSize(30);
    PlayerHubText.setPosition(20,710);

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

    std::string OpponentString = std::string("Opponent \nHP :") + std::to_string(OpponentHP);
    sf::Text OpponentHubText(OpponentString, font);
    OpponentHubText.setCharacterSize(30);
    OpponentHubText.setPosition(20,20);

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
    Battlefield.setPosition(272,220);
    Battlefield.setScale(631/Battlefield.getLocalBounds().width,560/Battlefield.getLocalBounds().height);


    //Setting the cards drawing

    sf::Sprite HandCardBuffer(texture);
    HandCardBuffer.setScale(73/HandCardBuffer.getLocalBounds().width,100/HandCardBuffer.getLocalBounds().height);

    sf::Sprite PermanentBuffer(texture);
    PermanentBuffer.setScale(73/PermanentBuffer.getLocalBounds().width,100/PermanentBuffer.getLocalBounds().height);

    // Draw Player Hand
    std::vector<sf::Sprite> PlayerHandCardVect;
	for (int i = 0; i < numPlayerHand; i++){
            PlayerHandCardVect.push_back(HandCardBuffer);
            PlayerHandCardVect[i].setPosition(10 + 272 + i*90, 800);
        }


    // Draw Opponent Hand
    std::vector<sf::Sprite> OpponentHandCardVect;
	for (int i = 0; i < numOpponentHand; i++){
            OpponentHandCardVect.push_back(HandCardBuffer);
            OpponentHandCardVect[i].setPosition(10 + 272 + i*90, 100);
        }

    // Draw Player Permanent
    std::vector<sf::Sprite> PlayerPermanentVect;
	for (int i = 0; i < numPlayerPermanent; i++){
            PlayerPermanentVect.push_back(PermanentBuffer);
            PlayerPermanentVect[i].setPosition(10 + 272 + i*90, 525);
        }

    // Draw Opponent Permanent
    std::vector<sf::Sprite> OpponentPermanentVect;
	for (int i = 0; i < numOpponentPermanent; i++){
            OpponentPermanentVect.push_back(PermanentBuffer);
            OpponentPermanentVect[i].setPosition(10 + 272 + i*90, 375);
        }

    // Draw Player Land
    std::vector<sf::Sprite> PlayerLandVect;
	for (int i = 0; i < numPlayerLand; i++){
            PlayerLandVect.push_back(PermanentBuffer);
            PlayerLandVect[i].setPosition(10 + 272 + i*90, 645);
        }

    // Draw Opponent Land
    std::vector<sf::Sprite> OpponentLandVect;
	for (int i = 0; i < numOpponentLand; i++){
            OpponentLandVect.push_back(PermanentBuffer);
            OpponentLandVect[i].setPosition(10 + 272 + i*90, 255);
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
        window.draw(Background);

        window.draw(PlayerLibrary);
        window.draw(PlayerExile);
        window.draw(PlayerGraveyard);
        window.draw(PlayerHub);
        window.draw(PlayerHubText);
        window.draw(PlayerHand);

        window.draw(OpponentLibrary);
        window.draw(OpponentExile);
        window.draw(OpponentGraveyard);
        window.draw(OpponentHub);
	window.draw(OpponentHubText);
        window.draw(OpponentHand);

	window.draw(Battlefield);


        // Draw Cards

        //Hand Player Cards
	for (int i = 0; i < numPlayerHand; i++){
            window.draw(PlayerHandCardVect[i]);
        }

        //Hand Opponent Cards
	for (int i = 0; i < numOpponentHand; i++){
            window.draw(OpponentHandCardVect[i]);
        }

        //Permanent Player Cards
	for (int i = 0; i < numPlayerPermanent; i++){
            window.draw(PlayerPermanentVect[i]);
        }

        //Permanent Opponent Cards
	for (int i = 0; i < numOpponentPermanent; i++){
            window.draw(OpponentPermanentVect[i]);
        }

        //Land Player Cards
	for (int i = 0; i < numPlayerLand; i++){
            window.draw(PlayerLandVect[i]);
        }

        //Land Opponent Cards
	for (int i = 0; i < numOpponentLand; i++){
            window.draw(OpponentLandVect[i]);
        }

        // Update the window
        window.display();
    }

    */
}
