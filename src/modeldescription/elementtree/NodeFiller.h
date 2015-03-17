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
	void FillWithAttributes(shared_ptr<Node> node, ptree& xml_tree);
	void FillWithChilds(shared_ptr<Node> node, ptree& xml_tree);
	void MakeAndAddChild(shared_ptr<Node> node, ptree::value_type& xml_element);
public:
	NodeFiller();
	void Fill(shared_ptr<Node> &node, string node_name, ptree& xml_tree);
};


#endif
