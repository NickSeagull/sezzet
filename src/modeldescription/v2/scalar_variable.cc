#include "scalar_variable.h"
#include <string>

using std::string;

string ScalarVariable::name(){return name_;}
void ScalarVariable::name(string new_name){name_ = new_name;}

string ScalarVariable::causality(){return causality_;}
void ScalarVariable::causality(string new_causality){causality_ = new_causality;}
string ScalarVariable::variability(){return variability_;}
void ScalarVariable::variability(string new_variability){variability_ = new_variability;}
string ScalarVariable::description(){return description_;}
void ScalarVariable::description(string new_description){description_ = new_description;}
string ScalarVariable::initial(){return initial_;}
void ScalarVariable::initial(string new_initial){initial_ = new_initial;}
int ScalarVariable::previous(){return previous_;}
void ScalarVariable::previous(int new_previous){previous_ = new_previous;}
bool ScalarVariable::can_handle_multiple_set_per_time_instant(){return can_handle_multiple_set_per_time_instant_;}
void ScalarVariable::can_handle_multiple_set_per_time_instant(bool new_can_handle_multiple_set_per_time_instant){can_handle_multiple_set_per_time_instant_ = new_can_handle_multiple_set_per_time_instant;}
shared_ptr<RealType> ScalarVariable::real(){return real_;}
void ScalarVariable::real(shared_ptr<RealType> new_real){real_ = new_real;}
shared_ptr<IntegerType> ScalarVariable::integer(){return integer_;}
void ScalarVariable::integer(shared_ptr<IntegerType> new_integer){integer_ = new_integer;}
shared_ptr<BooleanType> ScalarVariable::boolean(){return boolean_;}
void ScalarVariable::boolean(shared_ptr<BooleanType> new_boolean){boolean_ = new_boolean;}
shared_ptr<StringType> ScalarVariable::stringg(){return stringg_;}
void ScalarVariable::stringg(shared_ptr<StringType> new_stringg){stringg_ = new_stringg;}

void ScalarVariable::AddAnnotation(Tool annotation){
	annotations_.push_back(annotation);
}










