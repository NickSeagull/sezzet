#ifndef MODELDESCRIPTION_V2_MODELDESCRIPTION_H_
#define MODELDESCRIPTION_V2_MODELDESCRIPTION_H_

#include <string>
#include <vector>
#include "unit.h"
#include "simple_type.h"
#include "category.h"
#include "default_experiment.h"
#include "tool.h"
#include "scalar_variable.h"
#include "model_structure.h"
#include "model_exchange.h"
#include "co_simulation.h"
#include "../elementtree/node.h"

using std::string;
using std::vector;

class ModelDescription : public Node {
private:
	string fmi_version_;
	string model_name_;
	string guid_;
	string description_;
	string author_;
	string version_;
	string copyright_;
	string license_;
	string generation_tool_;
	string generation_date_and_time_;
	string variable_naming_convention_;
	int number_of_event_indicators_;
	
	vector<Unit> unit_definitions_;
	vector<SimpleType> type_definitions_;
	vector<Category> log_categories_;
	DefaultExperiment default_experiment_;
	vector<Tool> vendor_annotations_;
	vector<ScalarVariable> model_variables_list_;
	ModelStructure model_structure_;
	ModelExchange model_exchange_;
	CoSimulation co_simulation_;
	unordered_map<string, ScalarVariable> model_variables_;
	Capabilities capabilities_;
	vector<string> variables_names_;
public:
	void number_of_event_indicators(int new_number_of_event_indicators);
	int number_of_event_indicators();
	void variable_naming_convention(string new_variable_naming_convention);
	string variable_naming_convention();
	void generation_date_and_time(string new_generation_date_and_time);
	string generation_date_and_time();
	void generation_tool(string new_generation_tool);
	string generation_tool();
	void license(string new_license);
	string license();
	void copyright(string new_copyright);
	string copyright();
	void version(string new_version);
	string version();
	void author(string new_author);
	string author();
	void description(string new_description);
	string description();
	void guid(string new_guid);
	string guid();
	void model_name(string new_model_name);
	string model_name();
	void fmi_version(string new_fmi_version);
	string fmi_version();
	vector<Unit> unit_definitions();
	vector<SimpleType> type_definitions();
	vector<Category> log_categories();
	DefaultExperiment default_experiment();
	vector<Tool> vendor_annotations();
	vector<ScalarVariable> model_variables_list();
	ModelStructure model_structure();
	ModelExchange model_exchange();
	CoSimulation co_simulation();
	unordered_map<string, ScalarVariable> model_variables();
	Capabilities capabilities();
	vector<string> variables_names();
	ModelDescription();
};

#endif
