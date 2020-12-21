
#include <boost/test/unit_test.hpp>
#include <memory>

#include "../../src/shared/state.h"

using namespace state;

BOOST_AUTO_TEST_SUITE(test_state_token)

BOOST_AUTO_TEST_CASE(test_token_create){
    std::shared_ptr<state::Token> token = std::dynamic_pointer_cast<Token>(Token::create());
    BOOST_TEST(token.get() != nullptr,"Token::Create create a non-Token object.");
}

BOOST_AUTO_TEST_CASE(test_token_serialize) {
	std::shared_ptr<state::Token> token1 = std::dynamic_pointer_cast<Token>(Token::create());
	std::shared_ptr<state::Token> token2 = std::dynamic_pointer_cast<Token>(Token::create());

	token1->tapped = true;
	token2->tapped = false; // They are different

	token1->color = "1";
	token2->color = "2";

	token2->deserialize(token1->serialize());

	BOOST_TEST(token1->tapped == token2->tapped);
	BOOST_TEST(token1->color == token2->color); // Now they are equal
}

BOOST_AUTO_TEST_SUITE_END();
