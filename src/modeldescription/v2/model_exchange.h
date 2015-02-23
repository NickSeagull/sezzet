#ifndef MODELDESCRIPTION_V2_MODELEXCHANGE_H_
#define MODELDESCRIPTION_V2_MODELEXCHANGE_H_

#include <string>
#include <vector>
#include "source_file.h"

using std::string;
using std::vector;

class ModelExchange{
private:
	string model_identifier_;
	bool needs_execution_tool_;
	bool completed_integrator_step_not_needed_;
	bool can_be_instantiated_only_once_per_process_;
	bool can_not_use_memory_management_functions_;
	bool can_get_and_set_fmu_state_;
	bool can_serialize_fmu_state_;
	bool provides_directional_derivative_;
	
	vector<SourceFile> source_files_;
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
	void completed_integrator_step_not_needed(bool new_completed_integrator_step_not_needed);
	bool completed_integrator_step_not_needed();
	void needs_execution_tool(bool new_needs_execution_tool);
	bool needs_execution_tool();
	void model_identifier(string new_model_identifier);
	string model_identifier();
    ModelExchange();
	vector<SourceFile> source_files();
	void set_source_files(vector<SourceFile> source_files);
};


#endif
