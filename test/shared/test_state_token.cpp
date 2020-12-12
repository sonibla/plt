
#include <boost/test/unit_test.hpp>
#include <memory>

#include "../../src/shared/state.h"

using namespace state;

BOOST_AUTO_TEST_SUITE(test_state_token)

BOOST_AUTO_TEST_CASE(test_token_create){
  std::shared_ptr<state::Token> token = std::dynamic_pointer_cast<Token>(Token::Create());
  BOOST_TEST(token.get() != nullptr,"Token::Create create a non-Token object.");
}

BOOST_AUTO_TEST_SUITE_END();
