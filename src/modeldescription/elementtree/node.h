#ifndef MODELDESCRIPTION_ELEMENTTREE_NODE_H_
#define MODELDESCRIPTION_ELEMENTTREE_NODE_H_

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

using std::unordered_map;
using std::string;
using std::vector;
using std::shared_ptr;

class Node{
private:
	unordered_map<string, string> attributes_;
	string name_;
	vector<shared_ptr<Node>> childs_;
public:
	void childs(vector<shared_ptr<Node>> new_childs);
	vector<shared_ptr<Node>> childs();
	void name(string new_name);
	string name();
	void attributes(unordered_map<string, string> new_attributes);
	unordered_map<string, string> attributes();
	void AddAttribute(string attribute_name, string value);
	string GetAttribute(string attribute_name);
	void AddChild(Node child);
	Node();
};


#endif
