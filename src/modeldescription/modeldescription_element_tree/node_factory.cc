#include "node_factory.h"
#include "node_filler.h"
#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <memory>

using std::unique_ptr;

Node NodeFactory::NewNode(string element_name, ptree::value_type xml_element){
	if(element_name == "fmiModelDescription"){
		return BuildNewModelDescriptionNode(xml_element);
	}
	Node node;
	return node;
}

Node NodeFactory::BuildNewModelDescriptionNode(ptree::value_type xml_element){
	Node node;
	NodeFiller node_filler;
	node_filler.Fill(node, xml_element);
	return node;
}



