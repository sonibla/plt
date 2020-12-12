
#include <boost/test/unit_test.hpp>
#include <memory>

#include "../../src/shared/state.h"

using namespace state;

BOOST_AUTO_TEST_SUITE(test_state_player)

BOOST_AUTO_TEST_CASE(test_player_create){
    std::shared_ptr<state::Player> player = std::dynamic_pointer_cast<Player>(Player::Create());
    BOOST_TEST(player.get() != nullptr,"Player::Create create a non-Player object.");
}

BOOST_AUTO_TEST_CASE(test_player_draw){
    BOOST_TEST(0);
}

BOOST_AUTO_TEST_CASE(test_player_draw){
    BOOST_TEST(0);
}

BOOST_AUTO_TEST_SUITE_END();
