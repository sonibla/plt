
#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"

using namespace state;

BOOST_AUTO_TEST_SUITE(test_state_player)

BOOST_AUTO_TEST_CASE(test_player_create){
    std::shared_ptr<state::Player> player = std::dynamic_pointer_cast<Player>(Player::create());
    BOOST_TEST(player.get() != nullptr,"Player::create() create a non-Player object.");
}

BOOST_AUTO_TEST_CASE(test_player_draw){
    std::shared_ptr<state::Player> player = std::dynamic_pointer_cast<Player>(Player::create());
    std::shared_ptr<state::Library> library = player->getLibrary().lock();
    std::shared_ptr<state::Hand> hand = player->getHand().lock();

    int ids[5];
    for(int i=0;i<5;i++){
        std::shared_ptr<state::Card> _card = std::dynamic_pointer_cast<Card>(Card::create());
        ids[i] = _card->getID();
        library->cards.push_back(_card);
    }
    BOOST_TEST(hand->cards.size() == 0,"Player::Draw testing setup failed");
    BOOST_TEST(library->cards.size() == 5,"Player::Draw testing setup failed");
    player->draw(0);
    BOOST_TEST((hand->cards.size() == 0),"Player::Draw(0) alter the number of cards or hand");
    BOOST_TEST(library->cards.size() == 5,"Player::Draw(0) alter the number of cards in library");
    player->draw(3);
    BOOST_TEST((hand->cards.size() == 3),"Player::Draw() doesn't draw the appropriate number of cards when the library is not empty");
    BOOST_TEST(library->cards.size() == 2,"Player::Draw() doesn't draw the appropriate number of cards when the library is not empty");
    
    player->draw(3);
    BOOST_TEST((hand->cards.size() == 5),"Player::Draw() doesn't draw the appropriate number of cards when the library is empty");
    BOOST_TEST(library->cards.size() == 0,"Player::Draw() doesn't draw the appropriate number of cards when the library is empty");
    
    for(int i=0;i<5;i++){
        std::shared_ptr<GameElement> gE = GameElement::getPtr(ids[i]);
        BOOST_TEST(gE == nullptr,"Player::Draw() does not change the ids of the cards it moves");
    }

    //test getptr ?
}

BOOST_AUTO_TEST_CASE(test_player_cast){
    std::shared_ptr<state::Game> game = state::Game::create();
    std::shared_ptr<state::Stack> stack = game->getStack().lock();
    std::shared_ptr<state::Player> player = std::dynamic_pointer_cast<Player>(Player::create());
    std::vector<std::shared_ptr<Player>> players;
    players.push_back(player);
    game->setPlayers(players);
    std::shared_ptr<state::Hand> hand = player->getHand().lock();
    std::shared_ptr<state::Card> card = std::dynamic_pointer_cast<Card>(Card::create());
    int id_card = card->getID();
    hand->cards.push_back(card);

    player->cast(id_card);
    
    //size of stack 
    BOOST_TEST(stack->abilities.size() == 1);

    //size of hand
    BOOST_TEST(hand->cards.size() == 0);

    //is a spell
    std::shared_ptr<state::Spell> spell = std::dynamic_pointer_cast<Spell>(stack->abilities.top());
    BOOST_TEST(spell != nullptr);

    //controller of the spell
    BOOST_TEST(spell->controller ==player->getID());

    //owner of the spell
    BOOST_TEST(spell->owner ==player->getID());

    //source of the spell
    BOOST_TEST(spell->source->getID() == card->getID());

    //id of the source
    BOOST_TEST(card->getID()!=id_card);





    //behaviour(not yet)
    BOOST_TEST(1);


}

BOOST_AUTO_TEST_SUITE_END();
