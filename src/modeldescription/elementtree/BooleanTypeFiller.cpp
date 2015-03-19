#include "BooleanTypeFiller.h"

BooleanTypeFiller::BooleanTypeFiller(){}

void BooleanTypeFiller::Fill(BooleanType& boolean_type, NodePointer node){
	for(auto& pair : node->attributes())
		SetField(boolean_type, pair.first, pair.second);
}

void BooleanTypeFiller::SetField(BooleanType& boolean_type, string field_name, string field_value){
	if(field_name == "declaredType") boolean_type.declared_type(field_value);
	if(field_name == "start") boolean_type.start(field_value == "true");
}
