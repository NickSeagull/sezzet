#include "node_filler.h"
#include <boost/foreach.hpp>

void NodeFiller::Fill(Node node, ptree::value_type xml_element){
	BOOST_FOREACH(auto& raw_attribute, GetAttributesTree(xml_element)){
		node.AddAttribute(BuildAttribute(raw_attribute));
	}
}

Attribute NodeFiller::BuildAttribute(ptree::value_type raw_attribute){
	Attribute attribute;
	attribute.name(raw_attribute.first.data());
	attribute.value(raw_attribute.second.data());
	return attribute;
}

ptree NodeFiller::GetAttributesTree(ptree::value_type xml_element){
	ptree tree;
	xml_element.second.get_child("<xmlattr>", tree);
	return tree;
}
