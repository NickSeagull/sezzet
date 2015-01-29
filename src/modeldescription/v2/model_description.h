#ifndef MODELDESCRIPTION_V2_MODELDESCRIPTION_H_
#define MODELDESCRIPTION_V2_MODELDESCRIPTION_H_

#include <unordered_map>
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

using std::unordered_map;
using std::string;
using std::vector;

class ModelDescription {
public:
	unordered_map<string, string> attributes();
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
private:
	unordered_map<string, string> attributes_;
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
};

#endif
