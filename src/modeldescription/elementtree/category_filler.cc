#include "category_filler.h"

CategoryFiller::CategoryFiller(){}

void CategoryFiller::Fill(Category& category, shared_ptr<Node> node){
	for(auto& pair : node->attributes())
		SetField(category, pair.first, pair.second);
}

void CategoryFiller::SetField(Category& category, string field_name, string field_value){
	if(field_name == "name") category.name(field_value);
	if(field_name == "description") category.name(field_value);
}
