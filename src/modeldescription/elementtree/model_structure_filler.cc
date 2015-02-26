#include "model_structure_filler.h"

ModelStructureFiller::ModelStructureFiller(){}

void ModelStructureFiller::Fill(ModelStructure& model_structure, shared_ptr<Node> node){
	for(auto& child : node->childs())
		SetChild(model_structure, child);
}

void ModelStructureFiller::SetChild(ModelStructure& model_structure, shared_ptr<Node> child){
	if (child->name() == "Outputs") FillAndAddOutputs(model_structure, child);
	if (child->name() == "Derivatives") FillAndAddDerivatives(model_structure, child);
}

void ModelStructureFiller::FillAndAddOutputs(ModelStructure& model_structure, shared_ptr<Node> node){
	UnknownFiller filler;
	for(auto& child : node->childs())
		FillAndAddOutput(model_structure, child, filler);
}

void ModelStructureFiller::FillAndAddOutput(ModelStructure& model_structure, shared_ptr<Node> child, UnknownFiller filler){
	Unknown unknown;
	filler.Fill(unknown, child);
	model_structure.AddOutput(unknown);
}

void ModelStructureFiller::FillAndAddDerivatives(ModelStructure& model_structure, shared_ptr<Node> node){
	UnknownFiller filler;
	for(auto& child : node->childs())
		FillAndAddDerivative(model_structure, child, filler);
}

void ModelStructureFiller::FillAndAddDerivative(ModelStructure& model_structure, shared_ptr<Node> child, UnknownFiller filler){
	Unknown unknown;
	filler.Fill(unknown, child);
	model_structure.AddOutput(unknown);
}
