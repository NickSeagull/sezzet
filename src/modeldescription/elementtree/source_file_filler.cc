#include "source_file_filler.h"
SourceFileFiller::SourceFileFiller(){}

void SourceFileFiller::Fill(SourceFile& source_file, shared_ptr<Node> node){
	for(auto& pair : node->attributes())
		SetField(source_file, pair.first, pair.second);
}

void SourceFileFiller::SetField(SourceFile& source_file, string field_name, string field_value){
	if(field_name == "name") source_file.name(field_value);
}
