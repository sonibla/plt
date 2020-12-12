
#include <boost/test/unit_test.hpp>
#include <memory>

#include "../../src/shared/state.h"

using namespace state;

BOOST_AUTO_TEST_SUITE(test_state_activated_ability)

BOOST_AUTO_TEST_CASE(test_state_activated_ability_create){
  std::shared_ptr<state::ActivatedAbility> activatedAbility = std::dynamic_pointer_cast<ActivatedAbility>(ActivatedAbility::Create());
  BOOST_TEST(activatedAbility.get() != nullptr,"ActivatedAbility::Create create a non-ActivatedAbility object.");
}

BOOST_AUTO_TEST_SUITE_END();
