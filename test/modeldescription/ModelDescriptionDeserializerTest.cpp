#define BOOST_TEST_DYN_LINK
#include "../../src/modeldescription/elementtree/NodeFiller.h"
#include "../../src/modeldescription/v2/ModelDescription.h"
#include "../../src/modeldescription/ModelDescriptionDeserializer.h"

#define BOOST_TEST_MODULE ModelDescriptionDeserializerTest

#include <boost/test/unit_test.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/test/test_tools.hpp>
#include <boost/test/output_test_stream.hpp>
#include <memory>
#include <string>
#include <vector>
#include "../../src/modeldescription/elementtree/node.h"

using std::unique_ptr;
using std::make_unique;
using boost::property_tree::ptree;
using std::make_shared;
using std::vector;

std::string bouncing_ball_xml_path("resources/bouncing_ball_md.xml");
std::string tank_xml_path("resources/tank_md.xml");
boost::test_tools::output_test_stream output;

ptree MakeEmptyTree(){
	ptree tree;
	return tree;
}

BOOST_AUTO_TEST_CASE( a_node_will_be_filled_with_attributes_after_being_passed_to_a_node_filler ){
	shared_ptr<Node> node;
	NodeFiller filler;
	ptree property_tree;
	read_xml(bouncing_ball_xml_path, property_tree);
	string node_name = "fmiModelDescription";
	ptree xml_subtree = property_tree.get_child(node_name, MakeEmptyTree());
	filler.Fill(node, node_name, xml_subtree);
	BOOST_CHECK_EQUAL(node->GetAttribute("fmiVersion"), "1.0");
	BOOST_CHECK_EQUAL(node->GetAttribute("modelName"), "bouncingBall");
	BOOST_CHECK_EQUAL(node->GetAttribute("modelIdentifier"), "bouncingBall");
	BOOST_CHECK_EQUAL(node->GetAttribute("guid"), "{8c4e810f-3df3-4a00-8276-176fa3c9f003}");
	BOOST_CHECK_EQUAL(node->GetAttribute("numberOfContinuousStates"), "2");
	BOOST_CHECK_EQUAL(node->GetAttribute("numberOfEventIndicators"), "1");
}

BOOST_AUTO_TEST_CASE( a_node_will_know_its_name_after_being_passed_to_a_node_filler ){
	shared_ptr<Node> node;
	NodeFiller filler;
	ptree property_tree;
	read_xml(bouncing_ball_xml_path, property_tree);
	string node_name = "fmiModelDescription";
	ptree xml_subtree = property_tree.get_child(node_name, MakeEmptyTree());
	filler.Fill(node, node_name, xml_subtree);
	BOOST_CHECK_EQUAL(node->name(), "fmiModelDescription");
}

BOOST_AUTO_TEST_CASE( a_node_will_have_other_nodes_as_childs_if_the_xml_has_that_structure ){
	shared_ptr<Node> node;
	NodeFiller filler;
	ptree property_tree;
	read_xml(bouncing_ball_xml_path, property_tree);
	string node_name = "fmiModelDescription";
	ptree xml_subtree = property_tree.get_child(node_name, MakeEmptyTree());
	filler.Fill(node, node_name, xml_subtree);
	BOOST_CHECK_EQUAL(node->childs().at(0)->name(), "ModelVariables");
	BOOST_CHECK_EQUAL(node->childs().at(0)->childs().at(0)->name(), "ScalarVariable");
}

BOOST_AUTO_TEST_CASE( deserializer_test ){
	ModelDescription model_description;
	ModelDescriptionDeserializer deserializer(tank_xml_path);
	deserializer.Deserialize(model_description);
	BOOST_CHECK_EQUAL("tankv3", model_description.model_name());
	BOOST_CHECK_EQUAL("tankv3", model_description.co_simulation().model_identifier());
}