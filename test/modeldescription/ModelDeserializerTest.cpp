#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../../src/modeldescription/v2/ModelDescription.h"
#include "../../src/modeldescription/ModelDescriptionDeserializer.h"

string project_root("C:\\Users\\ntchayka\\Documents\\Desarrollo\\sezzet\\");
string xml_path(project_root + "resources\\tank_md.xml");

BOOST_AUTO_TEST_CASE(a_deserializer_will_fill_all_the_class_hierarchy) {
	ModelDescriptionDeserializer deserializer;
	shared_ptr<ModelDescription> model_description(deserializer.Deserialize(xml_path));

	BOOST_REQUIRE_EQUAL("tankv3", model_description->model_name());
	BOOST_REQUIRE_EQUAL("tankv3", model_description->co_simulation().model_identifier());
	BOOST_REQUIRE_EQUAL("logLevel1 - fatal errors", model_description->log_categories().at(0).description());
	BOOST_REQUIRE_EQUAL("JModelica.org", model_description->vendor_annotations().at(0).name());
	BOOST_REQUIRE_EQUAL("parameter", model_description->model_variables().at("_block_jacobian_check")->causality());
}