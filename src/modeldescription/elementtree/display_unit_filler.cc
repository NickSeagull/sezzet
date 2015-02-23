#include "display_unit_filler.h"

DisplayUnitFiller::DisplayUnitFiller(){}

void DisplayUnitFiller::Fill(DisplayUnit& display_unit, shared_ptr<Node> node){
	for(auto& pair : node->attributes())
		SetField(display_unit, pair.first, pair.second);
}

void DisplayUnitFiller::SetField(DisplayUnit& display_unit, string field_name, string field_value){
	if(field_name == "name") display_unit.name(field_value);
	if(field_name == "factor") display_unit.factor(stod(field_value));
	if(field_name == "offset") display_unit.offset(stod(field_value));
}
