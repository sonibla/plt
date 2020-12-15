
#include <boost/test/unit_test.hpp>
#include <memory>

#include "../../src/shared/state.h"

using namespace state;

BOOST_AUTO_TEST_SUITE(test_state_card)

BOOST_AUTO_TEST_CASE(test_card_create){
    std::shared_ptr<state::Card> card = std::dynamic_pointer_cast<Card>(Card::create());
    BOOST_TEST(card.get() != nullptr,"Card::Create create a non-Card object.");
}

BOOST_AUTO_TEST_SUITE_END();
