#include "model_exchange_filler.h"
#include "source_file_filler.h"

ModelExchangeFiller::ModelExchangeFiller(){}

void ModelExchangeFiller::Fill(ModelExchange& model_exchange, shared_ptr<Node> node){
	for(auto& pair : node->attributes())
		SetField(model_exchange, pair.first, pair.second);
	for(auto& child : node->childs())
		SetChild(model_exchange, child);
}

void ModelExchangeFiller::SetField(ModelExchange& model_exchange, string field_name, string field_value){
	if(field_name == "modelIdentifier") model_exchange.model_identifier(field_value);
	if(field_name == "needsExecutionTool") model_exchange.needs_execution_tool(field_value == "true");
	if(field_name == "completedIntegratorStepNotNeeded") model_exchange.completed_integrator_step_not_needed(field_value == "true");
	if(field_name == "canBeInstantiatedOnlyOncePerProcess") model_exchange.can_be_instantiated_only_once_per_process(field_value == "true");
	if(field_name == "canNotUseMemoryManagementFunctions") model_exchange.can_not_use_memory_management_functions(field_value == "true");
	if(field_name == "canGetAndSetFmuState") model_exchange.can_get_and_set_fmu_state(field_value == "true");
	if(field_name == "providesDirectionalDerivative") model_exchange.provides_directional_derivative(field_value == "true");
	if(field_name == "canSerializeFmuState") model_exchange.can_serialize_fmu_state(field_value == "true");
}

void ModelExchangeFiller::SetChild(ModelExchange& model_exchange, shared_ptr<Node> child){
	if(child->name() == "SourceFile") FillAndAddSourceFile(model_exchange, child);	
}

void ModelExchangeFiller::FillAndAddSourceFile(ModelExchange& model_exchange, shared_ptr<Node> node){
	SourceFileFiller filler;
	SourceFile source_file;
	filler.Fill(source_file, node);
	model_exchange.AddSourceFile(source_file);
}

