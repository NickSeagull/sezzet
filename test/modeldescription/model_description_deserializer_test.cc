#define BOOST_TEST_DYN_LINK
#include "../../src/modeldescription/model_description_deserializer.h"
#define BOOST_TEST_MODULE ModelDescriptionDeserializerTest

#include <boost/test/unit_test.hpp>
#include "model_description_test_fixture.cc"

BOOST_FIXTURE_TEST_CASE( it_is_possible_to_initialize_deserializer , Fixture ){
	BOOST_CHECK(deserializer != NULL); 
}

BOOST_FIXTURE_TEST_CASE( deserialized_model_description_is_not_null , Fixture ){
	BOOST_CHECK(model_description != NULL);
}

BOOST_FIXTURE_TEST_CASE( deserializer_gets_the_fmi_version , Fixture ){
	deserializer->Deserialize(model_description, "");
	BOOST_CHECK(model_description->fmi_version() == "1.0");
}
