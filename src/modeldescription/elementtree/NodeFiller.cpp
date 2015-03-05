#include "NodeFiller.h"
#include <memory>

NodeFiller::NodeFiller(){}

using boost::property_tree::ptree;
using std::make_shared;

void NodeFiller::Fill(shared_ptr<Node> node, string node_name, ptree& xml_tree){
	node->name(node_name);
	FillWithAttributes(node, xml_tree);
	FillWithChilds(node, xml_tree);
}

void NodeFiller::FillWithAttributes(shared_ptr<Node> node, ptree& xml_tree){
	for(auto& attribute : GetAttributeTree(xml_tree))
		node->AddAttribute(attribute.first.data(), attribute.second.data());
}
ptree NodeFiller::GetAttributeTree(ptree& xml_tree){
	return xml_tree.get_child("<xmlattr>", MakeEmptyTree());
}

void NodeFiller::FillWithChilds(shared_ptr<Node> node, ptree& xml_tree){
	for(auto& xml_element : xml_tree)
		if (strcmp(xml_element.first.data(), "<xmlattr>") != 0) MakeAndAddChild(node, xml_element);
}

void NodeFiller::MakeAndAddChild(shared_ptr<Node> node, ptree::value_type& xml_element){
	auto sub_node = make_shared<Node>();
	Fill(sub_node, xml_element.first.data(), xml_element.second);
	node->AddChild(sub_node);
}

ptree NodeFiller::MakeEmptyTree(){
	ptree tree;
	return tree;
}
