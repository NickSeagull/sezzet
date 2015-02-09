#include "node.h"

Node::Node(){}
unordered_map<string, string> Node::attributes(){return attributes_;}
void Node::attributes(unordered_map<string, string> new_attributes){attributes_ = new_attributes;}

void Node::AddAttribute(string attribute_name, string value) {
	attributes_.insert(std::pair<string, string>(attribute_name, value));
}

string Node::GetAttribute(string attribute_name){
	auto result = attributes_.find(attribute_name);
	if (result != attributes_.end())
		return result->second;
	else
		return "Not Found";
}
