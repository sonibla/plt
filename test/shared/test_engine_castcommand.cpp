
#include <boost/test/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/shared/state.h"
#include "../../src/shared/engine.h"

using namespace state;
using namespace engine;


BOOST_AUTO_TEST_SUITE(test_engine_castcommand)

BOOST_AUTO_TEST_CASE(test_castcommand_create){
    int cardID;
    std::shared_ptr<CastCommand> castCommand = std::make_shared<CastCommand>(cardID);

    BOOST_TEST(castCommand->cardID == cardID);
    BOOST_TEST(castCommand->getId() == CommandID::CAST);
}


BOOST_AUTO_TEST_SUITE_END();