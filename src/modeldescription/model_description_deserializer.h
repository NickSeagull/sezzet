#ifndef MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_

#include <string>
#include "v2/model_description.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using std::string;
using boost::property_tree::ptree;

class ModelDescriptionDeserializer{
private:
	ModelDescriptionElementTree tree_;
public:
    ModelDescriptionDeserializer();
	shared_ptr<ModelDescription> Deserialize(shared_ptr<ModelDescription> model_description, string model_description_path);
};


#endif
