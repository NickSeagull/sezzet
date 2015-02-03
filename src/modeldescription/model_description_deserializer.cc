#include "model_description_deserializer.h"
#include <memory>

using std::make_shared;

ModelDescriptionDeserializer::ModelDescriptionDeserializer(){}

shared_ptr<ModelDescription> ModelDescriptionDeserializer::Deserialize(shared_ptr<ModelDescription> model_description, string model_description_path){
	return model_description;
}
