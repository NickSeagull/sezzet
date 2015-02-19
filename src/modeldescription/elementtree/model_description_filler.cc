#include "model_description_filler.h"
#include "co_simulation_filler.h"

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
}

void ModelDescriptionFiller::FillAndSetCoSimulation(ModelDescription& model_description, shared_ptr<Node> node){
	CoSimulationFiller filler;
	CoSimulation co_simulation;
	filler.Fill(co_simulation, node);
	model_description.co_simulation(co_simulation);
}
