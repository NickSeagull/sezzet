#ifndef MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_NODE_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_NODE_H_

#include <vector>
#include "attribute.h"
#include "content.h"

using std::vector;

class Node{
private:
    vector<Attribute> attributes_;
	vector<Content> contents_;
public:
    Node();
	void AddAttribute(Attribute attribute);
	void AddContent(Content content);
};


#endif
