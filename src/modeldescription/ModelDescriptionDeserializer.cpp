#include "NodeFiller.h"
#include "ModelDescriptionFiller.h"
#include "ModelDescriptionDeserializer.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using boost::property_tree::ptree;

ptree EmptyPTree(){
	ptree tree;
	return tree;
}

ModelDescriptionDeserializer::ModelDescriptionDeserializer(string xml_path){
	xml_path_ = xml_path;
}

void ModelDescriptionDeserializer::Deserialize(ModelDescription& model_description){
	Node element_tree_root;
	ptree property_tree;
	read_xml(xml_path_, property_tree);
	ptree root_ptree = property_tree.get_child("fmiModelDescription", EmptyPTree());

	NodeFiller node_filler;
	node_filler.Fill(element_tree_root, "fmiModelDescription", root_ptree);

	ModelDescriptionFiller model_description_filler;
	model_description_filler.Fill(model_description, element_tree_root);
}

