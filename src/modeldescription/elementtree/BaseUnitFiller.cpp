#include "BaseUnitFiller.h"
#include <string>

using std::stoi;

BaseUnitFiller::BaseUnitFiller(){}

void BaseUnitFiller::Fill(BaseUnit& base_unit, NodePointer node){
	for(auto& pair : node->attributes())
		SetField(base_unit, pair.first, pair.second);
}

void BaseUnitFiller::SetField(BaseUnit& base_unit, string field_name, string field_value){
	if(field_name == "kg") base_unit.kg(stoi(field_value));
	if(field_name == "m") base_unit.m(stoi(field_value));
	if(field_name == "s") base_unit.s(stoi(field_value));
	if(field_name == "a") base_unit.a(stoi(field_value));
	if(field_name == "k") base_unit.k(stoi(field_value));
	if(field_name == "mol") base_unit.mol(stoi(field_value));
	if(field_name == "cd") base_unit.cd(stoi(field_value));
	if(field_name == "rad") base_unit.rad(stoi(field_value));
	if(field_name == "factor") base_unit.factor(stod(field_value));
	if(field_name == "offset") base_unit.offset(stod(field_value));
}
