
#include <boost/test/unit_test.hpp>
#include <memory>

#include "../../src/shared/state.h"

using namespace state;

BOOST_AUTO_TEST_SUITE(test_state_spell)

BOOST_AUTO_TEST_CASE(test_spell_create){
  std::shared_ptr<state::Spell> spell = std::dynamic_pointer_cast<Spell>(Spell::Create());
  BOOST_TEST(spell.get() != nullptr,"Spell::Create create a non-Spell object.");
}

BOOST_AUTO_TEST_SUITE_END();
