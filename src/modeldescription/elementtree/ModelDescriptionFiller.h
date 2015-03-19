#ifndef MODELDESCRIPTION_ELEMENTTREE_MODELDESCRIPTIONFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_MODELDESCRIPTIONFILLER_H_

#include "../v2/ModelDescription.h"
#include "Node.h"
#include "UnitFiller.h"
#include "CategoryFiller.h"
#include "ToolFiller.h"
#include "ScalarVariableFiller.h"

class ModelDescriptionFiller{
private:
	void SetField(ModelDescription& model_description, string field_name, string field_value);
	void SetChild(ModelDescription& model_description, NodePointer child);
	void FillAndSetCoSimulation(ModelDescription& model_description, NodePointer node);
	void FillAndSetModelExchange(ModelDescription& model_description, NodePointer node);
	void FillAndSetUnitDefinitions(ModelDescription& model_description, NodePointer node);
	void FillAndSetDefaultExperiment(ModelDescription& model_description, NodePointer node);
	void FillAndSetVendorAnnotations(ModelDescription& model_description, NodePointer node);
	void FillAndSetModelVariables(ModelDescription& model_description, NodePointer node);
	void FillAndAddUnit(ModelDescription& model_description, NodePointer child, UnitFiller& filler);
	void FillAndSetLogCategories(ModelDescription& model_description, NodePointer child);
	void FillAndAddCategory(ModelDescription& model_description, NodePointer child, CategoryFiller& filler);
	void FillAndAddVendorAnnotation(ModelDescription& model_description, NodePointer child, ToolFiller& filler);
	void FillAndAddScalarVariable(ModelDescription& model_description, NodePointer node, ScalarVariableFiller& filler);
	void FillAndSetModelStructure(ModelDescription& model_description, NodePointer node);
public:
	ModelDescriptionFiller();
	void Fill(ModelDescription& model_description, Node& node); 
};


#endif
