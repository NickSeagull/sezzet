#ifndef MODELDESCRIPTION_ELEMENTTREE_NODEFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_NODEFILLER_H_

#include "Node.h"
#include <memory>
#include <boost/property_tree/ptree.hpp>

using std::shared_ptr;
using boost::property_tree::ptree;

class NodeFiller{
private:
	ptree MakeEmptyTree();
	ptree GetAttributeTree(ptree& xml_tree);
	void FillWithAttributes(Node& node, ptree& xml_tree);
	void FillWithChilds(Node& node, ptree& xml_tree);
	void MakeAndAddChild(Node& node, ptree::value_type& xml_element);
public:
	NodeFiller();
	void Fill(Node& node, string node_name, ptree& xml_tree);
};


#endif
