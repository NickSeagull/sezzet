#define BOOST_TEST_DYN_LINK
#include "../../src/modeldescription/model_description_deserializer.h"
#include "../../src/modeldescription/elementtree/element_tree.h"
#include "../../src/modeldescription/elementtree/node_filler.h"
#define BOOST_TEST_MODULE ModelDescriptionDeserializerTest

#include <boost/test/unit_test.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/test/output_test_stream.hpp>
#include <memory>
#include <string>

using std::unique_ptr;
using std::make_unique;
using boost::property_tree::ptree;
using std::make_shared;

std::string xml_file("/home/nick/Desarrollo/SIANI/sezzet/resources/modelDescription.xml");
boost::test_tools::output_test_stream output;

BOOST_AUTO_TEST_CASE( it_is_possible_to_initialize_deserializer ){
	unique_ptr<ModelDescriptionDeserializer> deserializer();
	BOOST_CHECK(deserializer != NULL); 
}

BOOST_AUTO_TEST_CASE( it_is_possible_to_create_a_tree_that_represents_the_model_description ){
	unique_ptr<ElementTree> tree();
	BOOST_CHECK(tree != NULL);
}

BOOST_AUTO_TEST_CASE( it_is_possible_to_create_a_node_for_mantaining_the_xml_elements_data ){
	unique_ptr<Node> node();
	BOOST_CHECK(node != NULL);
}

BOOST_AUTO_TEST_CASE( a_node_will_be_filled_with_attributes_after_being_passed_to_a_node_filler ){
	Node node;
	auto filler = make_unique<NodeFiller>();
	ptree property_tree;
	read_xml(xml_file, property_tree);
	ptree attributes;
	property_tree.get_child("fmiModelDescription",attributes);
	filler->Fill(node, attributes);
	BOOST_CHECK_EQUAL(node.GetAttribute("fmiVersion"), "1.0");
}
