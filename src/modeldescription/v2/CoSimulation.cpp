#include "CoSimulation.h"

CoSimulation::CoSimulation(){}

string CoSimulation::model_identifier(){return model_identifier_;}
void CoSimulation::model_identifier(string new_model_identifier){model_identifier_ = new_model_identifier;}
bool CoSimulation::needs_execution_tool(){return needs_execution_tool_;}
void CoSimulation::needs_execution_tool(bool new_needs_execution_tool){needs_execution_tool_ = new_needs_execution_tool;}
bool CoSimulation::can_handle_variable_communication_step_size(){return can_handle_variable_communication_step_size_;}
void CoSimulation::can_handle_variable_communication_step_size(bool new_can_handle_variable_communication_step_size){can_handle_variable_communication_step_size_ = new_can_handle_variable_communication_step_size;}
bool CoSimulation::can_interpolate_inputs(){return can_interpolate_inputs_;}
void CoSimulation::can_interpolate_inputs(bool new_can_interpolate_inputs){can_interpolate_inputs_ = new_can_interpolate_inputs;}
int CoSimulation::max_output_derivative_order(){return max_output_derivative_order_;}
void CoSimulation::max_output_derivative_order(int new_max_output_derivative_order){max_output_derivative_order_ = new_max_output_derivative_order;}
bool CoSimulation::can_run_asynchronously(){return can_run_asynchronously_;}
void CoSimulation::can_run_asynchronously(bool new_can_run_asynchronously){can_run_asynchronously_ = new_can_run_asynchronously;}
bool CoSimulation::can_be_instantiated_only_once_per_process(){return can_be_instantiated_only_once_per_process_;}
void CoSimulation::can_be_instantiated_only_once_per_process(bool new_can_be_instantiated_only_once_per_process){can_be_instantiated_only_once_per_process_ = new_can_be_instantiated_only_once_per_process;}
bool CoSimulation::can_not_use_memory_management_functions(){return can_not_use_memory_management_functions_;}
void CoSimulation::can_not_use_memory_management_functions(bool new_can_not_use_memory_management_functions){can_not_use_memory_management_functions_ = new_can_not_use_memory_management_functions;}
bool CoSimulation::can_get_and_set_fmu_state(){return can_get_and_set_fmu_state_;}
void CoSimulation::can_get_and_set_fmu_state(bool new_can_get_and_set_fmu_state){can_get_and_set_fmu_state_ = new_can_get_and_set_fmu_state;}
bool CoSimulation::can_serialize_fmu_state(){return can_serialize_fmu_state_;}
void CoSimulation::can_serialize_fmu_state(bool new_can_serialize_fmu_state){can_serialize_fmu_state_ = new_can_serialize_fmu_state;}
bool CoSimulation::provides_directional_derivative(){return provides_directional_derivative_;}
void CoSimulation::provides_directional_derivative(bool new_provides_directional_derivative){provides_directional_derivative_ = new_provides_directional_derivative;}
shared_ptr<Capabilities> CoSimulation::capabilities(){return capabilities_;}
void CoSimulation::capabilities(shared_ptr<Capabilities> new_capabilities){capabilities_ = new_capabilities;}
void CoSimulation::AddSourceFile(SourceFile source_file){source_files_.push_back(source_file);}
vector<SourceFile> CoSimulation::source_files(){return source_files_;}












