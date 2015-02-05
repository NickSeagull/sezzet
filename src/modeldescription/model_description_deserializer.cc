#define XML_ATTRIBUTE "<xmlattr>."+

#include "model_description_deserializer.h"
#include <memory>
#include <fstream>
#include <exception>
#include <iostream>
#include <ostream>

using std::ifstream;
using std::exception;
using std::cout;
using std::endl;

ModelDescriptionDeserializer::ModelDescriptionDeserializer(){}

shared_ptr<ModelDescription> ModelDescriptionDeserializer::Deserialize(shared_ptr<ModelDescription> model_description, string model_description_path){
	ifstream input_stream(model_description_path.c_str());
	read_xml(input_stream, property_tree_);
	return model_description;
}
