#include "ToolFiller.h"

ToolFiller::ToolFiller(){}

void ToolFiller::Fill(Tool& tool, shared_ptr<Node> node){
	for(auto& pair : node->attributes())
		SetField(tool, pair.first, pair.second);
}

void ToolFiller::SetField(Tool& tool, string field_name, string field_value){
	if(field_name == "name") tool.name(field_value);
}
