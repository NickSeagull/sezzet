#ifndef MODELDESCRIPTION_ELEMENTTREE_MODELSTRUCTUREFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_MODELSTRUCTUREFILLER_H_

#include "../v2/ModelStructure.h"
#include "Node.h"
#include "UnknownFiller.h"

class ModelStructureFiller{
private:
    void SetChild(ModelStructure& model_structure, NodePointer child);
	void FillAndAddOutputs(ModelStructure& model_structure, NodePointer node);
	void FillAndAddOutput(ModelStructure& model_structure, NodePointer child, UnknownFiller filler);
	void FillAndAddDerivatives(ModelStructure& model_structure, NodePointer node);
	void FillAndAddDerivative(ModelStructure& model_structure, NodePointer child, UnknownFiller filler);
public:
	ModelStructureFiller();
	void Fill(ModelStructure& model_structure, NodePointer node);
};


#endif
