#ifndef MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONDESERIALIZER_H_

#include <string>
#include "v2/model_description.h"

using std::string;

class ModelDescriptionDeserializer{
private:
public:
    ModelDescriptionDeserializer();
	shared_ptr<ModelDescription> Deserialize(shared_ptr<ModelDescription> model_description, string model_description_path);
};


#endif
