#include "ModelStructure.h"

ModelStructure::ModelStructure(){}

void ModelStructure::AddOutput(Unknown output) {
	outputs_.push_back(output);
}

void ModelStructure::AddDerivative(Unknown derivative) {
	derivatives_.push_back(derivative); 
}
