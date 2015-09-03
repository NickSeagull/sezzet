#include "IntegerTypeFiller.h"

IntegerTypeFiller::IntegerTypeFiller(){}

void IntegerTypeFiller::Fill(IntegerType& integer_type, shared_ptr<Node> node){
	for(auto& pair : node->attributes())
		SetField(integer_type, pair.first, pair.second);
}

void IntegerTypeFiller::SetField(IntegerType& integer_type, string field_name, string field_value){
	if(field_name == "declaredType") integer_type.declared_type(field_value);
	if(field_name == "quantity") integer_type.quantity(field_value);
	if(field_name == "min") integer_type.min(stod(field_value));
	if(field_name == "max") integer_type.max(stod(field_value));
	if(field_name == "start") integer_type.start(stoi(field_value));
}
