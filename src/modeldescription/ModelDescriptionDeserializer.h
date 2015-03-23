#ifndef MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_

#include <string>
#include "v2/ModelDescription.h"
#include <functional>
#include <memory>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "elementtree/Node.h"

#define let const auto


using std::string;
using std::function;
using boost::property_tree::ptree;

typedef shared_ptr<ptree> PtreePointer;
typedef void(*FillerFunction)(shared_ptr<ModelDescription>&, shared_ptr<Node>&);

class ModelDescriptionDeserializer{
public:
	ModelDescriptionDeserializer();
	~ModelDescriptionDeserializer();

	shared_ptr<ModelDescription> Deserialize(string xml_file_path);
};


#endif
