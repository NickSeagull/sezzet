#ifndef MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_

#include <string>
#include "v2/ModelDescription.h"
#include <unordered_map>
#include <functional>
#include <memory>

using std::string;

class ModelDescriptionDeserializer{
private:
	string xml_path_;
	shared_ptr<Node> element_tree_root_;
	ptree raw_tree_;
	static unordered_map<string, std::function<void(const ModelDescriptionDeserializer&)>> model_description_class_factory;
public:
	ModelDescriptionDeserializer(string xml_path);
	void Deserialize(ModelDescription& model_description);

	void FillModelDescriptionRawTree(ptree &property_tree);

	void FillModelDescription();
	void FillElementTreeRoot();

};


#endif
