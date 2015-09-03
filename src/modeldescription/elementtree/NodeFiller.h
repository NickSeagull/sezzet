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
	void FillWithAttributes(const shared_ptr<Node>& node, const shared_ptr<ptree>& xml_tree);
	void FillWithChilds(const shared_ptr<Node>& node, const shared_ptr<ptree>& xml_tree);

	void MakeAndAddChildIfNotAttribute(ptree::value_type &xml_element, const shared_ptr<Node>& node);

	void MakeAndAddChild(const shared_ptr<Node>& node, ptree::value_type& xml_element);
public:
	NodeFiller();
	void Fill(const shared_ptr<Node> &node, string node_name, const shared_ptr<ptree>& xml_tree);
};


#endif
