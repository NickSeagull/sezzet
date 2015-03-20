#include "ModelDescriptionDeserializer.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "elementtree/node.h"
#include "elementtree/NodeFiller.h"
#include "elementtree/ModelDescriptionFiller.h"
#include <iostream>
#include <memory>
#include <map>

using boost::property_tree::ptree;
using std::make_shared;

void FillModelDescription(shared_ptr<ModelDescription> model_description, shared_ptr<Node> node);
void FillCoSimulation(shared_ptr<ModelDescription> model_description, shared_ptr<Node> node);

std::map<string, FillerFunction> filler_functions_map = { 
	{ "fmiModelDescription", &FillModelDescription },
	{ "fmiModelDescription/CoSimulation", &FillCoSimulation}
};

void FillChilds(shared_ptr<Node> node, shared_ptr<ModelDescription> model_description) {
	for (auto& child : node->childs()) filler_functions_map[child->name()](model_description, child);
}

void FillModelDescription (shared_ptr<ModelDescription> model_description, shared_ptr<Node> node) {
	for (auto& attribute_pair : node->attributes()) {
		string field_name(attribute_pair.first);
		string field_value(attribute_pair.second);
		if (field_name == "fmiVersion") model_description->fmi_version(field_value);
		else if (field_name == "modelName") model_description->model_name(field_value);
		else if (field_name == "guid") model_description->guid(field_value);
		else if (field_name == "description") model_description->description(field_value);
		else if (field_name == "author") model_description->author(field_value);
		else if (field_name == "version") model_description->version(field_value);
		else if (field_name == "copyright") model_description->copyright(field_value);
		else if (field_name == "license") model_description->license(field_value);
		else if (field_name == "generationTool") model_description->generation_tool(field_value);
		else if (field_name == "generationDateAndTime") model_description->generation_date_and_time(field_value);
		else if (field_name == "variableNamingConvention") model_description->variable_naming_convention(field_value);
		else if (field_name == "numberOfEventIndicators") model_description->number_of_event_indicators(stoi(field_value));
	}
	FillChilds(node, model_description);
};

void FillCoSimulation(shared_ptr<ModelDescription> model_description, shared_ptr<Node> node) {
	CoSimulation co_simulation;
	for (auto& attribute_pair : node->attributes()) {
		string field_name(attribute_pair.first);
		string field_value(attribute_pair.second);
		if(field_name == "modelIdentifier") co_simulation.model_identifier(field_value);
		else if(field_name == "needsExecutionTool") co_simulation.needs_execution_tool(field_value == "true");
		else if(field_name == "canHandleVariableCommunicationStepSize") co_simulation.can_handle_variable_communication_step_size(field_value == "true");
		else if(field_name == "canInterpolateInputs") co_simulation.can_interpolate_inputs(field_value == "true");
		else if(field_name == "maxOutputDerivativeOrder") co_simulation.max_output_derivative_order(stoi(field_value));
		else if(field_name == "canRunAsynchronously") co_simulation.can_run_asynchronously(field_value == "true");
		else if(field_name == "canBeInstantiatedOnlyOncePerProcess") co_simulation.can_be_instantiated_only_once_per_process(field_value == "true");
		else if(field_name == "canNotUseMemoryManagementFunctions") co_simulation.can_not_use_memory_management_functions(field_value == "true");
		else if(field_name == "canGetAndSetFmuState") co_simulation.can_get_and_set_fmu_state(field_value == "true");
		else if(field_name == "canSerializeFmuState") co_simulation.can_serialize_fmu_state(field_value == "true");
		else if(field_name == "providesDirectionalDerivative") co_simulation.provides_directional_derivative(field_value == "true");	
	}
	model_description->co_simulation(co_simulation);
	FillChilds(node, model_description);
}




ptree EmptyPTree(){
	ptree tree;
	return tree;
}

ModelDescriptionDeserializer::ModelDescriptionDeserializer(){}
ModelDescriptionDeserializer::~ModelDescriptionDeserializer() {}

shared_ptr<Node> FillElementTreeRoot(PtreePointer raw_tree){
	shared_ptr<Node> element_tree_root(make_shared<Node>());
	NodeFiller node_filler;
	node_filler.Fill(element_tree_root, "fmiModelDescription", raw_tree);
	return element_tree_root;
}

shared_ptr<Node> FillModelDescriptionRawTree(ptree &property_tree) {
	PtreePointer raw_tree(make_shared<ptree>(property_tree.get_child("fmiModelDescription", EmptyPTree())));
	return FillElementTreeRoot(raw_tree);
}

shared_ptr<Node> GetElementTreeFromXml(string xml_file_path) {
	ptree property_tree;
	read_xml(xml_file_path, property_tree);
	return FillModelDescriptionRawTree(property_tree);
}

shared_ptr<ModelDescription> ModelDescriptionDeserializer::Deserialize(string xml_file_path) {
	shared_ptr<Node> element_tree_root = GetElementTreeFromXml(xml_file_path);
	shared_ptr<ModelDescription> model_description(make_shared<ModelDescription>());
 	filler_functions_map["fmiModelDescription"](model_description, element_tree_root);
	return model_description;
}

