#include "DisplayUnit.h"

DisplayUnit::DisplayUnit(){}

string DisplayUnit::name(){return name_;}
void DisplayUnit::name(string new_name){name_ = new_name;}
double DisplayUnit::factor(){return factor_;}
void DisplayUnit::factor(double new_factor){factor_ = new_factor;}
double DisplayUnit::offset(){return offset_;}
void DisplayUnit::offset(double new_offset){offset_ = new_offset;}



