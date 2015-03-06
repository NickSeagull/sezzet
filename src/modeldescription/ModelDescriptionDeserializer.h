#ifndef MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_

#include <string>
#include "v2/ModelDescription.h"
#include <unordered_map>
#include <functional>
#include <memory>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "elementtree/Node.h"

using std::string;
using boost::property_tree::ptree;

class ModelDescriptionDeserializer{
private:
	string xml_path_;
	shared_ptr<Node> element_tree_root_;
	ptree raw_tree_;
	unordered_map<string, std::function<void()>> model_description_class_factory_;
public:
	ModelDescriptionDeserializer(string xml_path);

	void InitializeFactoryMap();

	void Deserialize(ModelDescription& model_description);

	void FillModelDescriptionRawTree(ptree &property_tree);

	void FillModelDescription();
	void FillElementTreeRoot();

};


#endif
