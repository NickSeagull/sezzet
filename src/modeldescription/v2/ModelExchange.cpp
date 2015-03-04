#include "ModelExchange.h"

ModelExchange::ModelExchange(){}

string ModelExchange::model_identifier(){return model_identifier_;}
void ModelExchange::model_identifier(string new_model_identifier){model_identifier_ = new_model_identifier;}
bool ModelExchange::needs_execution_tool(){return needs_execution_tool_;}
void ModelExchange::needs_execution_tool(bool new_needs_execution_tool){needs_execution_tool_ = new_needs_execution_tool;}
bool ModelExchange::completed_integrator_step_not_needed(){return completed_integrator_step_not_needed_;}
void ModelExchange::completed_integrator_step_not_needed(bool new_completed_integrator_step_not_needed){completed_integrator_step_not_needed_ = new_completed_integrator_step_not_needed;}
bool ModelExchange::can_not_use_memory_management_functions(){return can_not_use_memory_management_functions_;}
void ModelExchange::can_not_use_memory_management_functions(bool new_can_not_use_memory_management_functions){can_not_use_memory_management_functions_ = new_can_not_use_memory_management_functions;}
bool ModelExchange::can_get_and_set_fmu_state(){return can_get_and_set_fmu_state_;}
void ModelExchange::can_get_and_set_fmu_state(bool new_can_get_and_set_fmu_state){can_get_and_set_fmu_state_ = new_can_get_and_set_fmu_state;}
bool ModelExchange::provides_directional_derivative(){return provides_directional_derivative_;}
void ModelExchange::provides_directional_derivative(bool new_provides_directional_derivative){provides_directional_derivative_ = new_provides_directional_derivative;}
bool ModelExchange::can_serialize_fmu_state(){return can_serialize_fmu_state_;}
void ModelExchange::can_serialize_fmu_state(bool new_can_serialize_fmu_state){can_serialize_fmu_state_ = new_can_serialize_fmu_state;}
bool ModelExchange::can_be_instantiated_only_once_per_process(){return can_be_instantiated_only_once_per_process_;}
void ModelExchange::can_be_instantiated_only_once_per_process(bool new_can_be_instantiated_only_once_per_process){can_be_instantiated_only_once_per_process_ = new_can_be_instantiated_only_once_per_process;}

void ModelExchange::AddSourceFile(SourceFile source_file){
	source_files_.push_back(source_file);
}





