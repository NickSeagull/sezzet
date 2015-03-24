#include "ModelDescriptionFiller.h"
#include "CoSimulationFiller.h"
#include "ModelExchangeFiller.h"
#include "DefaultExperimentFiller.h"
#include "ModelStructureFiller.h"

ModelDescriptionFiller::ModelDescriptionFiller(){}

void ModelDescriptionFiller::Fill(ModelDescription& model_description, Node& node) {
	for(auto& pair : node.attributes())
		SetField(model_description, pair.first, pair.second);
	for(auto child : node.childs())
		SetChild(model_description, child);
}

void ModelDescriptionFiller::SetField(ModelDescription& model_description, string field_name, string field_value){
	if(field_name == "fmiVersion") model_description.fmi_version(field_value);
	if(field_name == "modelName") model_description.model_name(field_value);
	if(field_name == "guid") model_description.guid(field_value);
	if(field_name == "description") model_description.description(field_value);
	if(field_name == "author") model_description.author(field_value);
	if(field_name == "version") model_description.version(field_value);
	if(field_name == "copyright") model_description.copyright(field_value);
	if(field_name == "license") model_description.license(field_value);
	if(field_name == "generationTool") model_description.generation_tool(field_value);
	if(field_name == "generationDateAndTime") model_description.generation_date_and_time(field_value);
	if(field_name == "variableNamingConvention") model_description.variable_naming_convention(field_value);
	if(field_name == "numberOfEventIndicators") model_description.number_of_event_indicators(stoi(field_value));
}

void ModelDescriptionFiller::SetChild(ModelDescription& model_description, shared_ptr<Node> child){
	if(child->name() == "CoSimulation") FillAndSetCoSimulation(model_description, child);
	if(child->name() == "ModelExchange") FillAndSetModelExchange(model_description, child);
	if(child->name() == "UnitDefinitions") FillAndSetUnitDefinitions(model_description, child);
	if(child->name() == "LogCategories") FillAndSetLogCategories(model_description, child);
	if(child->name() == "DefaultExperiment") FillAndSetDefaultExperiment(model_description, child);
	if(child->name() == "VendorAnnotations") FillAndSetVendorAnnotations(model_description, child);
	if(child->name() == "ModelVariables") FillAndSetModelVariables(model_description, child);
	if(child->name() == "ModelStructure") FillAndSetModelStructure(model_description, child); 
}

void ModelDescriptionFiller::FillAndSetCoSimulation(ModelDescription& model_description, shared_ptr<Node> node){
	CoSimulationFiller filler;
	CoSimulation co_simulation;
	filler.Fill(co_simulation, node);
	model_description.co_simulation(co_simulation);
}

void ModelDescriptionFiller::FillAndSetModelExchange(ModelDescription& model_description, shared_ptr<Node> node){
	ModelExchangeFiller filler;
	ModelExchange model_exchange;
	filler.Fill(model_exchange, node);
	model_description.model_exchange(model_exchange);
}

void ModelDescriptionFiller::FillAndSetUnitDefinitions(ModelDescription& model_description, shared_ptr<Node> node){
	UnitFiller filler;
	for(auto& child : node->childs())
		FillAndAddUnit(model_description, child, filler);
}

void ModelDescriptionFiller::FillAndAddUnit(ModelDescription& model_description, shared_ptr<Node> child, UnitFiller& filler){
	Unit unit;
	filler.Fill(unit, child);
	model_description.AddUnitDefinition(unit);
}

void ModelDescriptionFiller::FillAndSetLogCategories(ModelDescription& model_description, shared_ptr<Node> node){
	CategoryFiller filler;
	for(auto& child : node->childs())
		FillAndAddCategory(model_description, child, filler);
}

void ModelDescriptionFiller::FillAndAddCategory(ModelDescription& model_description, shared_ptr<Node> child, CategoryFiller& filler){
	Category category;
	filler.Fill(category, child);
	model_description.AddLogCategory(category);
}

void ModelDescriptionFiller::FillAndSetDefaultExperiment(ModelDescription& model_description, shared_ptr<Node> node){
	DefaultExperiment default_experiment;
	DefaultExperimentFiller filler;
	filler.Fill(default_experiment, node);
	model_description.default_experiment(default_experiment);
}

void ModelDescriptionFiller::FillAndSetVendorAnnotations(ModelDescription& model_description, shared_ptr<Node> node){
	ToolFiller filler;
	for(auto& child : node->childs())
		FillAndAddVendorAnnotation(model_description, child, filler);
}

void ModelDescriptionFiller::FillAndAddVendorAnnotation(ModelDescription& model_description, shared_ptr<Node> child, ToolFiller& filler){
	Tool tool;
	filler.Fill(tool, child);
	model_description.AddVendorAnnotations(tool);
}

void ModelDescriptionFiller::FillAndSetModelVariables(ModelDescription& model_description, shared_ptr<Node> node){
	ScalarVariableFiller filler;
	for(auto& child : node->childs())
		FillAndAddScalarVariable(model_description, child, filler);
}

void ModelDescriptionFiller::FillAndAddScalarVariable(ModelDescription& model_description, shared_ptr<Node> node, ScalarVariableFiller& filler){
	ScalarVariable scalar_variable;
	filler.Fill(scalar_variable, node);
	model_description.AddModelVariable(scalar_variable);
}

void ModelDescriptionFiller::FillAndSetModelStructure(ModelDescription& model_description, shared_ptr<Node> node){
	ModelStructureFiller filler;
	ModelStructure model_structure;
	filler.Fill(model_structure, node);
	model_description.model_structure(model_structure);
}
