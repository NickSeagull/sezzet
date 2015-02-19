#ifndef MODELDESCRIPTION_V2_COSIMULATION_H_
#define MODELDESCRIPTION_V2_COSIMULATION_H_

#include <vector>
#include "source_file.h"
#include "capabilities.h"
#include <memory>

using std::vector;
using std::shared_ptr;

class CoSimulation{
private:
	string model_identifier_;
	bool needs_execution_tool_;
	bool can_handle_variable_communication_step_size_;
	bool can_interpolate_inputs_;
	int max_output_derivative_order_;
	bool can_run_asynchronously_;
	bool can_be_instantiated_only_once_per_process_;
	bool can_not_use_memory_management_functions_;
	bool can_get_and_set_fmu_state_;
	bool can_serialize_fmu_state_;
	bool provides_directional_derivative_;
	
	vector<SourceFile> source_files_;
	shared_ptr<Capabilities> capabilities_;
public:
	void provides_directional_derivative(bool new_provides_directional_derivative);
	bool provides_directional_derivative();
	void can_serialize_fmu_state(bool new_can_serialize_fmu_state);
	bool can_serialize_fmu_state();
	void can_get_and_set_fmu_state(bool new_can_get_and_set_fmu_state);
	bool can_get_and_set_fmu_state();
	void can_not_use_memory_management_functions(bool new_can_not_use_memory_management_functions);
	bool can_not_use_memory_management_functions();
	void can_be_instantiated_only_once_per_process(bool new_can_be_instantiated_only_once_per_process);
	bool can_be_instantiated_only_once_per_process();
	void can_run_asynchronously(bool new_can_run_asynchronously);
	bool can_run_asynchronously();
	void max_output_derivative_order(int new_max_output_derivative_order);
	int max_output_derivative_order();
	void can_interpolate_inputs(bool new_can_interpolate_inputs);
	bool can_interpolate_inputs();
	void can_handle_variable_communication_step_size(bool new_can_handle_variable_communication_step_size);
	bool can_handle_variable_communication_step_size();
	void needs_execution_tool(bool new_needs_execution_tool);
	bool needs_execution_tool();
	void model_identifier(string new_model_identifier);
	string model_identifier();
    CoSimulation();
	shared_ptr<Capabilities> capabilities();
	void capabilities(shared_ptr<Capabilities> new_capabilities);
	void AddSourceFile(SourceFile source_file);
	vector<SourceFile> source_files();
};


#endif
