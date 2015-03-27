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

void ProcessModelDescriptionAtribute(string field_name, shared_ptr<ModelDescription>& model_description, string field_value) {
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

void FillModelDescription (shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	for (auto& attribute_pair : node->attributes())
		ProcessModelDescriptionAtribute(attribute_pair.first, model_description, attribute_pair.second);
	FillChilds(node, model_description);
}

void ProcessCoSimulationAttribute(string field_name, CoSimulation &co_simulation, string field_value) {
	if (field_name == "modelIdentifier") co_simulation.model_identifier(field_value);
	else if (field_name == "needsExecutionTool") co_simulation.needs_execution_tool(field_value == "true");
	else if (field_name == "canHandleVariableCommunicationStepSize") co_simulation.can_handle_variable_communication_step_size(field_value == "true");
	else if (field_name == "canInterpolateInputs") co_simulation.can_interpolate_inputs(field_value == "true");
	else if (field_name == "maxOutputDerivativeOrder") co_simulation.max_output_derivative_order(stoi(field_value));
	else if (field_name == "canRunAsynchronously") co_simulation.can_run_asynchronously(field_value == "true");
	else if (field_name == "canBeInstantiatedOnlyOncePerProcess") co_simulation.can_be_instantiated_only_once_per_process(field_value == "true");
	else if (field_name == "canNotUseMemoryManagementFunctions") co_simulation.can_not_use_memory_management_functions(field_value == "true");
	else if (field_name == "canGetAndSetFmuState") co_simulation.can_get_and_set_fmu_state(field_value == "true");
	else if (field_name == "canSerializeFmuState") co_simulation.can_serialize_fmu_state(field_value == "true");
	else if (field_name == "providesDirectionalDerivative") co_simulation.provides_directional_derivative(field_value == "true");
}

void FillCoSimulation(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	CoSimulation co_simulation;
	for (auto& attribute_pair : node->attributes())
		ProcessCoSimulationAttribute(attribute_pair.first, co_simulation, attribute_pair.second);
	model_description->co_simulation(co_simulation);
	FillChilds(node, model_description);
}

void FillLogCategories(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	FillChilds(node, model_description);
}

void ProcessLogCategoriesCategoryAttribute(string field_name, Category &category, string field_value) {
	if (field_name == "name") category.name(field_value);
	else if (field_name == "description") category.description(field_value);
}

void FillLogCategoriesCategory(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	Category category;
	for (auto& attribute_pair : node->attributes())
		ProcessLogCategoriesCategoryAttribute(attribute_pair.first, category, attribute_pair.second);
	model_description->AddLogCategory(category);
}

void ProcessModelExchangeAttribute(string field_name, ModelExchange &model_exchange, string field_value) {
	if (field_name == "modelIdentifier") model_exchange.model_identifier(field_value);
	else if (field_name == "needsExecutionTool") model_exchange.needs_execution_tool(field_value == "true");
	else if (field_name == "completedIntegratorStepNotNeeded") model_exchange.completed_integrator_step_not_needed(field_value == "true");
	else if (field_name == "canBeInstantiatedOnlyOncePerProcess") model_exchange.can_be_instantiated_only_once_per_process(field_value == "true");
	else if (field_name == "canNotUseMemoryManagementFunctions") model_exchange.can_not_use_memory_management_functions(field_value == "true");
	else if (field_name == "canGetAndSetFmuState") model_exchange.can_get_and_set_fmu_state(field_value == "true");
	else if (field_name == "providesDirectionalDerivative") model_exchange.provides_directional_derivative(field_value == "true");
	else if (field_name == "canSerializeFmuState") model_exchange.can_serialize_fmu_state(field_value == "true");
}

void FillModelExchange(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	ModelExchange model_exchange;
	for (auto& pair : node->attributes()) 
		ProcessModelExchangeAttribute(pair.first, model_exchange, pair.second);
	model_description->model_exchange(model_exchange);
	FillChilds(node, model_description);
}

void FillVendorAnnotations(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	FillChilds(node, model_description);
}

void ProcessVendorAnnotationsToolAttributes(string field_name, Tool &tool, string field_value) {
	if (field_name == "name") tool.name(field_value);
}

void FillVendorAnnotationsTool(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	Tool tool;
	for (auto& pair : node->attributes()) 
		ProcessVendorAnnotationsToolAttributes(pair.first, tool, pair.second);
	model_description->AddVendorAnnotations(tool);
}

void FillModelVariables(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	FillChilds(node, model_description);
}

void ProcessModelVariablesScalarVariableAttribute(string field_name, ScalarVariable &scalar_variable, string field_value) {
	if (field_name == "causality") scalar_variable.causality(field_value);
	else if (field_name == "variability") scalar_variable.variability(field_value);
	else if (field_name == "name") scalar_variable.name(field_value);
	else if (field_name == "description") scalar_variable.description(field_value);
	else if (field_name == "initial") scalar_variable.initial(field_value);
	else if (field_name == "previous") scalar_variable.previous(stoi(field_value));
	else if (field_name == "canHandleMultipleSetPerTimeInstant") scalar_variable.can_handle_multiple_set_per_time_instant(field_value == "true");
}

bool IsBoolean(vector<shared_ptr<Node>>::const_reference child) {
	return child->name() == "fmiModelDescription/ModelVariables/ScalarVariable/Boolean";
}

bool IsReal(vector<shared_ptr<Node>>::const_reference child) {
	return child->name() == "fmiModelDescription/ModelVariables/ScalarVariable/Real";
}

bool IsInteger(vector<shared_ptr<Node>>::const_reference child) {
	return child->name() == "fmiModelDescription/ModelVariables/ScalarVariable/Integer";
}

bool IsString(vector<shared_ptr<Node>>::const_reference child) {
	return child->name() == "fmiModelDescription/ModelVariables/ScalarVariable/String";
}

void ProcessBooleanTypeAttribue(string field_name, BooleanType &boolean_type, string field_value) {
	if (field_name == "declaredType") boolean_type.declared_type(field_value);
	else if (field_name == "start") boolean_type.start(field_value == "true");
}

void ProcessRealTypeAttribute(string field_name, RealType &real_type, string field_value) {
	if (field_name == "declaredType") real_type.declared_type(field_value);
	else if (field_name == "quantity") real_type.quantity(field_value);
	else if (field_name == "unit") real_type.unit(field_value);
	else if (field_name == "relativeQuantity") real_type.relative_quantity(field_value == "true");
	else if (field_name == "min") real_type.min(stod(field_value));
	else if (field_name == "max") real_type.max(stod(field_value));
	else if (field_name == "nominal") real_type.nominal(stod(field_value));
	else if (field_name == "unbound") real_type.unbound(field_value == "true");
	else if (field_name == "start") real_type.start(stod(field_value));
	else if (field_name == "derivative") real_type.derivative(stoi(field_value));
	else if (field_name == "reinit") real_type.reinit(field_value == "true");
}

void ProcessIntegerTypeAttribute(string field_name, IntegerType &integer_type, string field_value) {
	if (field_name == "declaredType") integer_type.declared_type(field_value);
	else if (field_name == "quantity") integer_type.quantity(field_value);
	else if (field_name == "min") integer_type.min(stod(field_value));
	else if (field_name == "max") integer_type.max(stod(field_value));
	else if (field_name == "start") integer_type.start(stoi(field_value));
}

void ProcessStringTypeAttribute(string field_name, StringType &string_type, string field_value) {
	if (field_name == "declaredType") string_type.declared_type(field_value);
}

void ProcessModelVariableScalarVariableType(vector<shared_ptr<Node>>::const_reference child, ScalarVariable &scalar_variable) {
	if (IsBoolean(child)) {
		BooleanType boolean_type;
		for (auto& pair : child->attributes())
			ProcessBooleanTypeAttribue(pair.first, boolean_type, pair.second);
		scalar_variable.boolean(make_shared<BooleanType>(boolean_type));
	} else if (IsReal(child)) {
		RealType real_type;
		for (auto& pair : child->attributes()) 
			ProcessRealTypeAttribute(pair.first, real_type, pair.second);
		scalar_variable.real(make_shared<RealType>(real_type));
	} else if (IsInteger(child)) {
		IntegerType integer_type;
		for (auto& pair : child->attributes())
			ProcessIntegerTypeAttribute(pair.first, integer_type, pair.second);
		scalar_variable.integer(make_shared<IntegerType>(integer_type));
	} else if (IsString(child)) {
		StringType string_type;
		for (auto& pair : child->attributes())
			ProcessStringTypeAttribute(pair.first, string_type, pair.second);
		scalar_variable.stringg(make_shared<StringType>(string_type));
	}
}

void FillModelVariablesScalarVariable(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	ScalarVariable scalar_variable;
	for (auto& pair : node->attributes()) 
		ProcessModelVariablesScalarVariableAttribute(pair.first, scalar_variable, pair.second);
	ProcessModelVariableScalarVariableType(node->childs().at(0), scalar_variable);
	model_description->AddModelVariable(scalar_variable);
}

void FillUnitDefinitions(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	FillChilds(node, model_description);
}

void ProcessUnitDefinitionsUnitAttribute(string field_name, Unit &unit, string field_value) {
	if (field_name == "name") unit.name(field_value);
}

void ProcessBaseUnitAttribute(string field_name, BaseUnit &base_unit, string field_value) {
	if (field_name == "kg") base_unit.kg(stoi(field_value));
	else if (field_name == "m") base_unit.m(stoi(field_value));
	else if (field_name == "s") base_unit.s(stoi(field_value));
	else if (field_name == "a") base_unit.a(stoi(field_value));
	else if (field_name == "k") base_unit.k(stoi(field_value));
	else if (field_name == "mol") base_unit.mol(stoi(field_value));
	else if (field_name == "cd") base_unit.cd(stoi(field_value));
	else if (field_name == "rad") base_unit.rad(stoi(field_value));
	else if (field_name == "factor") base_unit.factor(stod(field_value));
	else if (field_name == "offset") base_unit.offset(stod(field_value));
}

void ProcessDisplayUnitAttribute(string field_name, DisplayUnit &display_unit, string field_value) {
	if (field_name == "name") display_unit.name(field_value);
	if (field_name == "factor") display_unit.factor(stod(field_value));
	if (field_name == "offset") display_unit.offset(stod(field_value));
}

bool IsBaseUnit(shared_ptr<Node> child) {
	return child->name() == "fmiModelDescription/UnitDefinitions/Unit/baseUnit";
}

bool IsDisplayUnit(shared_ptr<Node> child) {
	return child->name() == "fmiModelDescription/UnitDefinitions/Unit/displayUnit";
}

void MakeAndAddBaseUnit(shared_ptr<Node> child, Unit &unit) {
	BaseUnit base_unit;
	for (auto& pair : child->attributes())
		ProcessBaseUnitAttribute(pair.first, base_unit, pair.second);
	unit.base_unit(make_shared<BaseUnit>(base_unit));
}

void MakeAndAddDisplayUnit(shared_ptr<Node> child, Unit &unit) {
	DisplayUnit display_unit;
	for (auto& pair : child->attributes())
		ProcessDisplayUnitAttribute(pair.first, display_unit, pair.second);
	unit.AddDisplayUnit(display_unit);
}

void ProcessUnitDefinitionsUnitChild(shared_ptr<Node> child, Unit &unit) {
	if (IsBaseUnit(child)) 
		MakeAndAddBaseUnit(child, unit);
	else if (IsDisplayUnit(child))
		MakeAndAddDisplayUnit(child, unit);
}

void FillUnitDefinitionsUnit(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	Unit unit;
	for(auto& pair : node->attributes())
		ProcessUnitDefinitionsUnitAttribute(pair.first, unit, pair.second);
	for(auto& child : node->childs())
		ProcessUnitDefinitionsUnitChild(child, unit);
	model_description->AddUnitDefinition(unit);
}

void ProcessDefaultExperimentAttribute(string field_name, DefaultExperiment &default_experiment, string field_value) {
	if (field_name == "stepSize") default_experiment.step_size(stod(field_value));
	if (field_name == "stopTime") default_experiment.stop_time(stod(field_value));
	if (field_name == "startTime") default_experiment.start_time(stod(field_value));
	if (field_name == "tolerance") default_experiment.tolerance(stod(field_value));
}

void FillDefaultExperiment(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	DefaultExperiment default_experiment;
	for(auto& pair : node->attributes())
		ProcessDefaultExperimentAttribute(pair.first, default_experiment, pair.second);
	model_description->default_experiment(default_experiment);
}

void ProcessOutputAttribute(string field_name, Unknown &unknown, string field_value) {
	if (field_name == "index") unknown.index(stoi(field_value));
	else if (field_name == "dependencies") unknown.dependencies(field_value);
	else if (field_name == "dependenciesKind") unknown.dependencies_kind(field_value);
}

void MakeAndAddOutput(shared_ptr<Node> child, ModelStructure &model_structure) {
	Unknown unknown;
	for (auto& pair : child->attributes()) 
		ProcessOutputAttribute(pair.first, unknown, pair.second);
	model_structure.AddOutput(unknown);
}

void ProcessDerivativeAttribute(string field_name, Unknown &unknown, string field_value) {
	if (field_name == "index") unknown.index(stoi(field_value));
	else if (field_name == "dependencies") unknown.dependencies(field_value);
	else if (field_name == "dependenciesKind") unknown.dependencies_kind(field_value);
}

void MakeAndAddDerivative(shared_ptr<Node> child, ModelStructure &model_structure) {
	for (auto& child : child->childs()) {
		Unknown unknown;
		for (auto& pair : child->attributes()) 
			ProcessDerivativeAttribute(pair.first, unknown, pair.second);
		model_structure.AddDerivative(unknown);
	}
}

void ProcessModelStructureChild(shared_ptr<Node> child, ModelStructure &model_structure) {
	if (child->name() == "fmiModelDescription/ModelStructure/Outputs") 
		MakeAndAddOutput(child, model_structure);
	else if (child->name() == "fmiModelDescription/ModelStructure/Derivatives") 
		MakeAndAddDerivative(child, model_structure);
}

void FillModelStructure(shared_ptr<ModelDescription>& model_description, shared_ptr<Node>& node) {
	ModelStructure model_structure;
	for(auto& child : node->childs())
		ProcessModelStructureChild(child, model_structure);
	model_description->model_structure(model_structure);
}





ModelDescriptionDeserializer::ModelDescriptionDeserializer(){
	filler_functions_map["fmiModelDescription"] = &FillModelDescription;
	filler_functions_map["fmiModelDescription/CoSimulation"] = &FillCoSimulation;
	filler_functions_map["fmiModelDescription/LogCategories"] = &FillLogCategories;
	filler_functions_map["fmiModelDescription/LogCategories/Category"] = &FillLogCategoriesCategory;
	filler_functions_map["fmiModelDescription/ModelExchange"] = &FillModelExchange;
	filler_functions_map["fmiModelDescription/VendorAnnotations"] = &FillVendorAnnotations;
	filler_functions_map["fmiModelDescription/VendorAnnotations/Tool"] = &FillVendorAnnotationsTool;
	filler_functions_map["fmiModelDescription/ModelVariables"] = &FillModelVariables;
	filler_functions_map["fmiModelDescription/ModelVariables/ScalarVariable"] = &FillModelVariablesScalarVariable;
	filler_functions_map["fmiModelDescription/UnitDefinitions"] = &FillUnitDefinitions;
	filler_functions_map["fmiModelDescription/UnitDefinitions/Unit"] = &FillUnitDefinitionsUnit;
	filler_functions_map["fmiModelDescription/DefaultExperiment"] = &FillDefaultExperiment;
	filler_functions_map["fmiModelDescription/ModelStructure"] = &FillModelStructure;
}

ModelDescriptionDeserializer::~ModelDescriptionDeserializer() {}

ptree EmptyPTree(){
	ptree tree;
	return tree;
}

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

