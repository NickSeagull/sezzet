#include "model_description.h"

ModelDescription::ModelDescription(){}

string ModelDescription::fmi_version(){return fmi_version_;}
void ModelDescription::fmi_version(string new_fmi_version){fmi_version_ = new_fmi_version;}

