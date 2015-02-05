#ifndef MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_NODEFACTORY_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_NODEFACTORY_H_

#include "node.h"
#include <boost/property_tree/ptree.hpp>

using boost::property_tree::ptree;

class NodeFactory{
public:
    NodeFactory();
    Node NewNode(string element_name, ptree::value_type xml_element);
	Node BuildNewModelDescriptionNode(ptree::value_type xml_element);
	ptree MakeEmptyPTree();
	ptree GetAttributesTree(ptree::value_type xml_element);
};


#endif
