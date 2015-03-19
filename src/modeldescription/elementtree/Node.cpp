#include "Node.h"
#include <iostream>

using std::make_shared;

Node::Node(){}
Node::~Node() {}

unordered_map<string, string> Node::attributes() { return attributes_; }
void Node::attributes(unordered_map<string, string> new_attributes){attributes_ = new_attributes;}
string Node::name(){return name_;}
void Node::name(string new_name){name_ = new_name;}
vector<NodePointer> Node::childs(){return childs_;}
void Node::childs(vector<NodePointer> new_childs){childs_ = new_childs;}


void Node::AddAttribute(string attribute_name, string value) {
	attributes_.insert(std::pair<string, string>(attribute_name, value));
}

string Node::GetAttribute(string attribute_name){
	auto result = attributes_.find(attribute_name);
	if (result == attributes_.end()) return "Not Found";
	return result->second;
}

void Node::AddChild(NodePointer& child){
	childs_.push_back(child);
}
