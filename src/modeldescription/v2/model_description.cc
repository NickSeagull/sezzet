#include "model_description.h"

ModelDescription::ModelDescription(){}

string ModelDescription::fmi_version(){return fmi_version_;}
void ModelDescription::fmi_version(string new_fmi_version){fmi_version_ = new_fmi_version;}
string ModelDescription::model_name(){return model_name_;}
void ModelDescription::model_name(string new_model_name){model_name_ = new_model_name;}
string ModelDescription::guid(){return guid_;}
void ModelDescription::guid(string new_guid){guid_ = new_guid;}
string ModelDescription::description(){return description_;}
void ModelDescription::description(string new_description){description_ = new_description;}
string ModelDescription::author(){return author_;}
void ModelDescription::author(string new_author){author_ = new_author;}
string ModelDescription::version(){return version_;}
void ModelDescription::version(string new_version){version_ = new_version;}
string ModelDescription::copyright(){return copyright_;}
void ModelDescription::copyright(string new_copyright){copyright_ = new_copyright;}
string ModelDescription::license(){return license_;}
void ModelDescription::license(string new_license){license_ = new_license;}
string ModelDescription::generation_tool(){return generation_tool_;}
void ModelDescription::generation_tool(string new_generation_tool){generation_tool_ = new_generation_tool;}
string ModelDescription::generation_date_and_time(){return generation_date_and_time_;}
void ModelDescription::generation_date_and_time(string new_generation_date_and_time){generation_date_and_time_ = new_generation_date_and_time;}
string ModelDescription::variable_naming_convention(){return variable_naming_convention_;}
void ModelDescription::variable_naming_convention(string new_variable_naming_convention){variable_naming_convention_ = new_variable_naming_convention;}
int ModelDescription::number_of_event_indicators(){return number_of_event_indicators_;}
void ModelDescription::number_of_event_indicators(int new_number_of_event_indicators){number_of_event_indicators_ = new_number_of_event_indicators;}











