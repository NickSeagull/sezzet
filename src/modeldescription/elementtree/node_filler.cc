#include "node_filler.h"
#include <boost/foreach.hpp>

NodeFiller::NodeFiller(){}

void NodeFiller::Fill(Node& node, ptree& xml_tree){
	ptree attributes_tree;
	xml_tree.get_child("<xmlattr>", attributes_tree);
	BOOST_FOREACH(auto attribute, xml_tree){
		node.AddAttribute(attribute.first.data(), attribute.second.data());
	}
}
