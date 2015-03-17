#include "ModelDescriptionDeserializer.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "elementtree/node.h"
#include "elementtree/NodeFiller.h"
#include "elementtree/ModelDescriptionFiller.h"
#include <iostream>

using boost::property_tree::ptree;

ptree EmptyPTree(){
	ptree tree;
	return tree;
}

ModelDescriptionDeserializer::ModelDescriptionDeserializer(string xml_path) {
	xml_path_ = xml_path;
	InitializeFactoryMap();
}


ModelDescriptionDeserializer::~ModelDescriptionDeserializer() {
}

void ModelDescriptionDeserializer::InitializeFactoryMap() {
	model_description_class_factory_["fmiModelDescription"] = std::bind(&ModelDescriptionDeserializer::FillModelDescription, this);
}

void ModelDescriptionDeserializer::Deserialize(ModelDescription& model_description) {
	ptree property_tree;
	read_xml(xml_path_, property_tree);
	FillModelDescriptionRawTree(property_tree);
	
}

void ModelDescriptionDeserializer::FillModelDescriptionRawTree(ptree &property_tree) {
	raw_tree_ = property_tree.get_child("fmiModelDescription", EmptyPTree());
	FillElementTreeRoot();
}

void ModelDescriptionDeserializer::FillElementTreeRoot(){
	NodeFiller node_filler;
	node_filler.Fill(element_tree_root_, "fmiModelDescription", raw_tree_);
}

void ModelDescriptionDeserializer::FillModelDescription(){
	std::cout << xml_path_ << std::endl;
}