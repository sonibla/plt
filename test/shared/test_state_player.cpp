
#include <boost/test/unit_test.hpp>
#include <memory>

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
        std::weak_ptr<GameElement> gE = GameElement::getPtr(ids[i]);
        //BOOST_TEST(gE == nullptr,"Player::Draw() does not change the ids of the cards it moves");
    }

    //test getptr ?
}

BOOST_AUTO_TEST_CASE(test_player_cast){
    std::shared_ptr<state::Game> game = Game::create();
    std::shared_ptr<state::Stack> stack = game->getStack().lock();

    std::shared_ptr<state::Player> player = game->getPlayers()[0].lock();
    std::shared_ptr<state::Hand> hand = player->getHand().lock();

    std::shared_ptr<state::Card> _card = std::dynamic_pointer_cast<Card>(Card::create());
    int id_card = _card->getID();
    hand->cards.push_back(_card);

    //size of stack 
    BOOST_TEST(1);

    //size of hand
    BOOST_TEST(1);

    //is a spell
    BOOST_TEST(1);

    //controller of the spell
    BOOST_TEST(1);

    //owner of the spell
    BOOST_TEST(1);

    //source of the spell
    BOOST_TEST(1);

    //id of the source
    BOOST_TEST(1);





    //behaviour(not yet)
    BOOST_TEST(1);


}

BOOST_AUTO_TEST_SUITE_END();
