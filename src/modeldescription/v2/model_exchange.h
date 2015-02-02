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
	bool completed_integratior_step_not_needed_;
	bool can_be_instantiated_only_per_process_;
	bool can_not_use_memory_management_functions_;
	bool can_get_and_set_fmu_state_;
	bool can_serialize_fmu_state_;
	bool provides_directional_derivative_;
	
	vector<SourceFile> source_files_;
public:
	inline void provides_directional_derivative(bool new_provides_directional_derivative);
	inline bool provides_directional_derivative();
	inline void can_serialize_fmu_state(bool new_can_serialize_fmu_state);
	inline bool can_serialize_fmu_state();
	inline void can_get_and_set_fmu_state(bool new_can_get_and_set_fmu_state);
	inline bool can_get_and_set_fmu_state();
	inline void can_not_use_memory_management_functions(bool new_can_not_use_memory_management_functions);
	inline bool can_not_use_memory_management_functions();
	inline void can_be_instantiated_only_per_process(bool new_can_be_instantiated_only_per_process);
	inline bool can_be_instantiated_only_per_process();
	inline void completed_integratior_step_not_needed(bool new_completed_integratior_step_not_needed);
	inline bool completed_integratior_step_not_needed();
	inline void needs_execution_tool(bool new_needs_execution_tool);
	inline bool needs_execution_tool();
	inline void model_identifier(string new_model_identifier);
	inline string model_identifier();
    ModelExchange();
	vector<SourceFile> source_files();
	void set_source_files(vector<SourceFile> source_files);
};


#endif
