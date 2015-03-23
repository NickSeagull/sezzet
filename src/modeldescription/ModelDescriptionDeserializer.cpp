#include "ModelDescriptionDeserializer.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/assign.hpp>
#include "elementtree/node.h"
#include "elementtree/NodeFiller.h"
#include "elementtree/ModelDescriptionFiller.h"
#include <iostream>
#include <memory>
#include <map>

using boost::property_tree::ptree;
using std::make_shared;
using boost::assign::list_of;

void FillModelDescription(shared_ptr<ModelDescription> model_description, shared_ptr<Node> node);
void FillCoSimulation(shared_ptr<ModelDescription> model_description, shared_ptr<Node> node);

std::map<string, FillerFunction> filler_functions_map;

void CallFillerIfExists(shared_ptr<Node> child, shared_ptr<ModelDescription>& model_description) {
	if (filler_functions_map.find(child->name()) != filler_functions_map.end())
		filler_functions_map[child->name()](model_description, child);
}

void FillChilds(shared_ptr<Node>& node, shared_ptr<ModelDescription>& model_description) {
	for (auto& child : node->childs()) CallFillerIfExists(child, model_description);
}

void FillModelDescription (shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
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

void FillCoSimulation(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
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

void FillLogCategories(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	FillChilds(node, model_description);
}

void FillLogCategoriesCategory(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	Category category;
	for (auto& pair : node->attributes()) {
		string field_name(pair.first);
		string field_value(pair.second);
		if(field_name == "name") category.name(field_value);
		else if(field_name == "description") category.description(field_value);
	}
	model_description->AddLogCategory(category);
}

void FillModelExchange(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	ModelExchange model_exchange;
	for (auto& pair : node->attributes()) {
		string field_name(pair.first);
		string field_value(pair.second);
		if (field_name == "modelIdentifier") model_exchange.model_identifier(field_value);
		else if (field_name == "needsExecutionTool") model_exchange.needs_execution_tool(field_value == "true");
		else if (field_name == "completedIntegratorStepNotNeeded") model_exchange.completed_integrator_step_not_needed(field_value == "true");
		else if (field_name == "canBeInstantiatedOnlyOncePerProcess") model_exchange.can_be_instantiated_only_once_per_process(field_value == "true");
		else if (field_name == "canNotUseMemoryManagementFunctions") model_exchange.can_not_use_memory_management_functions(field_value == "true");
		else if (field_name == "canGetAndSetFmuState") model_exchange.can_get_and_set_fmu_state(field_value == "true");
		else if (field_name == "providesDirectionalDerivative") model_exchange.provides_directional_derivative(field_value == "true");
		else if (field_name == "canSerializeFmuState") model_exchange.can_serialize_fmu_state(field_value == "true");
	}
	model_description->model_exchange(model_exchange);
	FillChilds(node, model_description);
}

void FillVendorAnnotations(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	for (auto& child : node->childs()) {
		Tool tool;
		for (auto& pair : child->attributes()) {
			string field_name(pair.first);
			string field_value(pair.second);
			if(field_name == "name") tool.name(field_value);
		}
		model_description->AddVendorAnnotations(tool);
	}
}

void FillModelVariables(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	for (auto& child : node->childs())
		FillChilds(child, model_description);
}




ptree EmptyPTree(){
	ptree tree;
	return tree;
}

ModelDescriptionDeserializer::ModelDescriptionDeserializer(){
	filler_functions_map["fmiModelDescription"] = &FillModelDescription;
	filler_functions_map["fmiModelDescription/CoSimulation"] = &FillCoSimulation;
	filler_functions_map["fmiModelDescription/LogCategories"] = &FillLogCategories;
	filler_functions_map["fmiModelDescription/LogCategories/Category"] = &FillLogCategoriesCategory;
	filler_functions_map["fmiModelDescription/ModelExchange"] = &FillModelExchange;
	filler_functions_map["fmiModelDescription/VendorAnnotations"] = &FillVendorAnnotations;
}

ModelDescriptionDeserializer::~ModelDescriptionDeserializer() {}

shared_ptr<Node> FillElementTreeRoot(PtreePointer& raw_tree){
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

