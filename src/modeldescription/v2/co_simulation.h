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
	inline void provides_directional_derivative(bool new_provides_directional_derivative);
	inline bool provides_directional_derivative();
	inline void can_serialize_fmu_state(bool new_can_serialize_fmu_state);
	inline bool can_serialize_fmu_state();
	inline void can_get_and_set_fmu_state(bool new_can_get_and_set_fmu_state);
	inline bool can_get_and_set_fmu_state();
	inline void can_not_use_memory_management_functions(bool new_can_not_use_memory_management_functions);
	inline bool can_not_use_memory_management_functions();
	inline void can_be_instantiated_only_once_per_process(bool new_can_be_instantiated_only_once_per_process);
	inline bool can_be_instantiated_only_once_per_process();
	inline void can_run_asynchronously(bool new_can_run_asynchronously);
	inline bool can_run_asynchronously();
	inline void max_output_derivative_order(int new_max_output_derivative_order);
	inline int max_output_derivative_order();
	inline void can_interpolate_inputs(bool new_can_interpolate_inputs);
	inline bool can_interpolate_inputs();
	inline void can_handle_variable_communication_step_size(bool new_can_handle_variable_communication_step_size);
	inline bool can_handle_variable_communication_step_size();
	inline void needs_execution_tool(bool new_needs_execution_tool);
	inline bool needs_execution_tool();
	inline void model_identifier(string new_model_identifier);
	inline string model_identifier();
    CoSimulation();
	shared_ptr<Capabilities> capabilities();
};


#endif
