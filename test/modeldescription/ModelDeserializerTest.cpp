#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/modeldescription/v2/ModelDescription.h"
#include "../../src/modeldescription/ModelDescriptionDeserializer.h"

string xml_path("C:\\Users\\Nikita\\Desarrollo\\SIANI\\sezzet\\resources\\tank_md.xml");

BOOST_AUTO_TEST_CASE(a_deserializer_will_fill_all_the_class_hierarchy) {
	ModelDescription model_description;
	ModelDescriptionDeserializer deserializer(xml_path);
	deserializer.Deserialize(model_description);
	BOOST_CHECK_EQUAL("tankv3", model_description.model_name());
	BOOST_CHECK_EQUAL("tankv3", model_description.co_simulation().model_identifier());
}