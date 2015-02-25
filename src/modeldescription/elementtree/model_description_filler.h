#ifndef MODELDESCRIPTION_ELEMENTTREE_MODELDESCRIPTIONFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_MODELDESCRIPTIONFILLER_H_

#include "../v2/model_description.h"
#include "node.h"
#include "unit_filler.h"
#include "category_filler.h"
#include "tool_filler.h"
#include "scalar_variable_filler.h"

class ModelDescriptionFiller{
private:
    void SetField(ModelDescription& model_description, string field_name, string field_value);
	void SetChild(ModelDescription& model_description, shared_ptr<Node> child);
	void FillAndSetCoSimulation(ModelDescription& model_description, shared_ptr<Node> node);
	void FillAndSetModelExchange(ModelDescription& model_description, shared_ptr<Node> node);
	void FillAndSetUnitDefinitions(ModelDescription& model_description, shared_ptr<Node> node);
	void FillAndSetDefaultExperiment(ModelDescription& model_description, shared_ptr<Node> node);
	void FillAndSetVendorAnnotations(ModelDescription& model_description, shared_ptr<Node> node);
	void FillAndSetModelVariables(ModelDescription& model_description, shared_ptr<Node> node);
	void FillAndAddUnit(ModelDescription& model_description, shared_ptr<Node> child, UnitFiller& filler);
	void FillAndSetLogCategories(ModelDescription& model_description, shared_ptr<Node> child);
	void FillAndAddCategory(ModelDescription& model_description, shared_ptr<Node> child, CategoryFiller& filler);
	void FillAndAddVendorAnnotation(ModelDescription& model_description, shared_ptr<Node> child, ToolFiller& filler);
	void FillAndAddScalarVariable(ModelDescription& model_description, shared_ptr<Node> node, ScalarVariableFiller& filler);
	void FillAndSetModelStructure(ModelDescription& model_description, shared_ptr<Node> node);
public:
	ModelDescriptionFiller();
	void Fill(ModelDescription& model_description, Node& node); 
};


#endif
