#define BOOST_TEST_DYN_LINK
#include "../../src/modeldescription/model_description_deserializer.h"
#define BOOST_TEST_MODULE ModelDescriptionDeserializerTest

#include <boost/test/unit_test.hpp>
#include <string>
#include <memory>
#include "model_description_test_fixture.cc"

using std::string;
using std::make_shared;

BOOST_FIXTURE_TEST_CASE( it_is_possible_to_initialize_deserializer , Fixture){
	BOOST_CHECK(deserializer != NULL);
}

BOOST_FIXTURE_TEST_CASE( deserialized_model_description_is_not_null , Fixture){
	BOOST_CHECK(model_description != NULL);
}

