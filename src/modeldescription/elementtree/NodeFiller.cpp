#include "NodeFiller.h"
#include <memory>
#include <iostream>

NodeFiller::NodeFiller(){}

using boost::property_tree::ptree;
using std::make_shared;
using std::for_each;

void NodeFiller::Fill(const shared_ptr<Node>& node, string node_name, const shared_ptr<ptree>& xml_tree){
	node->name(node_name);
	FillWithAttributes(node, xml_tree);
	FillWithChilds(node, xml_tree);
}

void NodeFiller::FillWithAttributes(const shared_ptr<Node>& node, const shared_ptr<ptree>& xml_tree){
	for(auto& attribute : GetAttributeTree(xml_tree))
		node->AddAttribute(attribute.first.data(), attribute.second.data());
}

ptree NodeFiller::GetAttributeTree(const shared_ptr<ptree>& xml_tree){
	return xml_tree->get_child("<xmlattr>", MakeEmptyTree());
}

void NodeFiller::FillWithChilds(const shared_ptr<Node>& node, const shared_ptr<ptree>& xml_tree){
	for_each(xml_tree->begin(), xml_tree->end(), [&](ptree::value_type& xml_element){MakeAndAddChildIfNotAttribute(xml_element, node);});
}

void NodeFiller::MakeAndAddChildIfNotAttribute(ptree::value_type &xml_element, const shared_ptr<Node>& node) {
	if (strcmp(xml_element.first.data(), "<xmlattr>") != 0) MakeAndAddChild(node, xml_element);
}

void NodeFiller::MakeAndAddChild(const shared_ptr<Node>& node, ptree::value_type& xml_element) {
	auto sub_node = make_shared<Node>();
	Fill(sub_node, node->name() + "/" + xml_element.first.data(), make_shared<ptree>(xml_element.second));
	node->AddChild(sub_node);
}

ptree NodeFiller::MakeEmptyTree(){
	ptree tree;
	return tree;
}
