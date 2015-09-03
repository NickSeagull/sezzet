#include "Unit.h"

Unit::Unit(){}

string Unit::name(){return name_;}
void Unit::name(string new_name){name_ = new_name;}
shared_ptr<BaseUnit> Unit::base_unit(){return base_unit_;}
void Unit::base_unit(shared_ptr<BaseUnit> new_base_unit){base_unit_ = new_base_unit;}

void Unit::AddDisplayUnit(DisplayUnit display_unit){
	display_units_.push_back(display_unit);
}

