#include "default_experiment.h"

DefaultExperiment::DefaultExperiment(){}
double DefaultExperiment::step_size(){return step_size_;}
void DefaultExperiment::step_size(double new_step_size){step_size_ = new_step_size;}
double DefaultExperiment::stop_time(){return stop_time_;}
void DefaultExperiment::stop_time(double new_stop_time){stop_time_ = new_stop_time;}
double DefaultExperiment::start_time(){return start_time_;}
void DefaultExperiment::start_time(double new_start_time){start_time_ = new_start_time;}
double DefaultExperiment::tolerance(){return tolerance_;}
void DefaultExperiment::tolerance(double new_tolerance){tolerance_ = new_tolerance;}




