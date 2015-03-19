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
	ptree GetAttributeTree(const shared_ptr<ptree>& xml_tree);
	void FillWithAttributes(const NodePointer& node, const shared_ptr<ptree>& xml_tree);
	void FillWithChilds(const NodePointer& node, const shared_ptr<ptree>& xml_tree);

	void MakeAndAddChildIfNotAttribute(ptree::value_type &xml_element, const NodePointer& node);

	void MakeAndAddChild(const NodePointer& node, ptree::value_type& xml_element);
public:
	NodeFiller();
	void Fill(const NodePointer &node, string node_name, const shared_ptr<ptree>& xml_tree);
};


#endif
