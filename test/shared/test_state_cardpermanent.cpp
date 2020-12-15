
#include <boost/test/unit_test.hpp>
#include <memory>

#include "../../src/shared/state.h"

using namespace state;

BOOST_AUTO_TEST_SUITE(test_state_cardpermanent)

BOOST_AUTO_TEST_CASE(test_cardpermanent_create){
    std::shared_ptr<state::CardPermanent> cardPermanent = std::dynamic_pointer_cast<CardPermanent>(CardPermanent::create());
    BOOST_TEST(cardPermanent.get() != nullptr,"CardPermanent::Create create a non-CardPermanent object.");
}

BOOST_AUTO_TEST_SUITE_END();
