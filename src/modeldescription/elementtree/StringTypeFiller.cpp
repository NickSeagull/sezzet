#include "StringTypeFiller.h"

StringTypeFiller::StringTypeFiller(){}

void StringTypeFiller::Fill(StringType& string_type, shared_ptr<Node> node){
	for(auto& pair : node->attributes())
		SetField(string_type, pair.first, pair.second);
}

void StringTypeFiller::SetField(StringType& string_type, string field_name, string field_value){
	if(field_name == "declaredType") string_type.declared_type(field_value);
}
