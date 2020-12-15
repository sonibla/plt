
#include <boost/test/unit_test.hpp>
#include <memory>

#include "../../src/shared/state.h"

using namespace state;

BOOST_AUTO_TEST_SUITE(test_state_serializable)

BOOST_AUTO_TEST_CASE(test_serialize){
	Serializable * serial = new Serializable;
	Json::Value emptyJson;
    	BOOST_TEST(serial->serialize() == emptyJson,"Serializable::serialize must return an empty Json by default");
}

BOOST_AUTO_TEST_SUITE_END();
