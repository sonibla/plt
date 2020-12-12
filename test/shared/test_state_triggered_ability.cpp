
#include <boost/test/unit_test.hpp>
#include <memory>

#include "../../src/shared/state.h"

using namespace state;

BOOST_AUTO_TEST_SUITE(test_state_triggered_ability)

BOOST_AUTO_TEST_CASE(test_triggered_ability_create){
    std::shared_ptr<state::TriggeredAbility> triggeredAbility = std::dynamic_pointer_cast<TriggeredAbility>(TriggeredAbility::Create());
    BOOST_TEST(triggeredAbility.get() != nullptr,"TriggeredAbility::Create create a non-TriggeredAbility object.");
}

BOOST_AUTO_TEST_SUITE_END();
