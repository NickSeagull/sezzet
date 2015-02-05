#include "node.h"
#include <boost/property_tree/ptree.hpp>

using boost::property_tree::ptree;

class NodeFiller{
private:
public:
    NodeFiller();
	void Fill(Node node, ptree::value_type element);
	ptree GetAttributesTree(ptree::value_type xml_element);
	Attribute BuildAttribute(ptree::value_type raw_attribute);
};
