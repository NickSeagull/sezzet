#ifndef MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_

#include <string>
#include "v2/model_description.h"

using std::string;

class ModelDescriptionDeserializer{
private:
	string xml_path_;
public:
    ModelDescriptionDeserializer(string xml_path);
	void Deserialize(ModelDescription& model_description);
};


#endif
