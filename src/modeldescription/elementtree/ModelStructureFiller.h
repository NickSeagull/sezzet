#ifndef MODELDESCRIPTION_ELEMENTTREE_MODELSTRUCTUREFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_MODELSTRUCTUREFILLER_H_

#include "ModelStructure.h"
#include "Node.h"
#include "UnknownFiller.h"

class ModelStructureFiller{
private:
    void SetChild(ModelStructure& model_structure, shared_ptr<Node> child);
	void FillAndAddOutputs(ModelStructure& model_structure, shared_ptr<Node> node);
	void FillAndAddOutput(ModelStructure& model_structure, shared_ptr<Node> child, UnknownFiller filler);
	void FillAndAddDerivatives(ModelStructure& model_structure, shared_ptr<Node> node);
	void FillAndAddDerivative(ModelStructure& model_structure, shared_ptr<Node> child, UnknownFiller filler);
public:
	ModelStructureFiller();
	void Fill(ModelStructure& model_structure, shared_ptr<Node> node);
};


#endif
