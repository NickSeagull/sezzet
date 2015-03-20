#include "RealTypeFiller.h"

RealTypeFiller::RealTypeFiller(){}

void RealTypeFiller::Fill(RealType& real_type, shared_ptr<Node> node){
	for(auto& pair : node->attributes())
		SetField(real_type, pair.first, pair.second);
}

void RealTypeFiller::SetField(RealType& real_type, string field_name, string field_value){
	if(field_name == "declaredType") real_type.declared_type(field_value);
	if(field_name == "quantity") real_type.quantity(field_value);
	if(field_name == "unit") real_type.unit(field_value);
	if(field_name == "relativeQuantity") real_type.relative_quantity(field_value == "true");
	if(field_name == "min") real_type.min(stod(field_value));
	if(field_name == "max") real_type.max(stod(field_value));
	if(field_name == "nominal") real_type.nominal(stod(field_value));
	if(field_name == "unbound") real_type.unbound(field_value == "true");
	if(field_name == "start") real_type.start(stod(field_value));
	if(field_name == "derivative") real_type.derivative(stoi(field_value));
	if(field_name == "reinit") real_type.reinit(field_value == "true");
}
