#ifndef MODELDESCRIPTION_MODELDESCRIPTIONTESTFIXTURE
#define MODELDESCRIPTION_MODELDESCRIPTIONTESTFIXTURE

#include <string>
#include <memory>
#include "../../src/modeldescription/model_description_deserializer.h"

using std::string;
using std::make_shared;

struct Fixture {
    const string kModelDescriptionPath = "../test_resources/modeldescription/v2/";
    const string kModelDescriptionFileName = "modelDescription.xml";
    auto make_deserializer(){
        return make_shared<ModelDescriptionDeserializer>();
    }
    auto make_model_description(){
        return deserializer->Deserialize(make_shared<ModelDescription>(), kModelDescriptionPath + kModelDescriptionFileName);
    }
    // Setup
    Fixture():deserializer(make_deserializer()),
	    	  model_description(make_model_description()){}
	// TearDown
	~Fixture(){
        deserializer = NULL;
        model_description = NULL;
    }
	shared_ptr<ModelDescriptionDeserializer> deserializer;
    shared_ptr<ModelDescription> model_description;
};

#endif
