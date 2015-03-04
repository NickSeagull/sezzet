#include "UnknownFiller.h"

UnknownFiller::UnknownFiller(){}

void UnknownFiller::Fill(Unknown& unknown, shared_ptr<Node> node) {
	for(auto& pair : node->attributes())
		SetField(unknown, pair.first, pair.second);
}

void UnknownFiller::SetField(Unknown& unknown, string field_name, string field_value){
	if(field_name == "index") unknown.index(stoi(field_value));
	if(field_name == "dependencies") unknown.dependencies(field_value);
	if(field_name == "dependenciesKind") unknown.dependencies_kind(field_value);
}
