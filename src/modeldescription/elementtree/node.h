#ifndef MODELDESCRIPTION_ELEMENTTREE_NODE_H_
#define MODELDESCRIPTION_ELEMENTTREE_NODE_H_

#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

class Node{
private:
	unordered_map<string, string> attributes_;
public:
	void attributes(unordered_map<string, string> new_attributes);
	unordered_map<string, string> attributes();
	void AddAttribute(string attribute_name, string value);
	string GetAttribute(string attribute_name);
	Node();
};


#endif
