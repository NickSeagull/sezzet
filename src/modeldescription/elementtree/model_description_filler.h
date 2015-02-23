#ifndef MODELDESCRIPTION_ELEMENTTREE_MODELDESCRIPTIONFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_MODELDESCRIPTIONFILLER_H_

#include "../v2/model_description.h"
#include "node.h"
#include "unit_filler.h"
#include "category_filler.h"

class ModelDescriptionFiller{
private:
    void SetField(ModelDescription& model_description, string field_name, string field_value);
	void SetChild(ModelDescription& model_description, shared_ptr<Node> child);
	void FillAndSetCoSimulation(ModelDescription& model_description, shared_ptr<Node> node);
	void FillAndSetModelExchange(ModelDescription& model_description, shared_ptr<Node> node);
	void FillAndSetUnitDefinitions(ModelDescription& model_description, shared_ptr<Node> node);
	void FillAndAddUnit(ModelDescription& model_description, shared_ptr<Node> child, UnitFiller& filler);
	void FillAndSetLogCategories(ModelDescription& model_description, shared_ptr<Node> child);
	void FillAndAddCategory(ModelDescription& model_description, shared_ptr<Node> child, CategoryFiller& filler);
public:
	ModelDescriptionFiller();
	void Fill(ModelDescription& model_description, Node& node); 
};


#endif
