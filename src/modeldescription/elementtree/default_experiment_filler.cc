#include "default_experiment_filler.h"

DefaultExperimentFiller::DefaultExperimentFiller(){}

void DefaultExperimentFiller::Fill(DefaultExperiment& default_experiment, shared_ptr<Node> node){
	for(auto& pair : node->attributes())
		SetField(default_experiment, pair.first, pair.second);
}

void DefaultExperimentFiller::SetField(DefaultExperiment& default_experiment, string field_name, string field_value){
	if(field_name == "stepSize") default_experiment.step_size(stod(field_value));
	if(field_name == "stopTime") default_experiment.stop_time(stod(field_value));
	if(field_name == "startTime") default_experiment.start_time(stod(field_value));
	if(field_name == "tolerance") default_experiment.tolerance(stod(field_value));
}
