#ifndef MODELDESCRIPTION_ELEMENTTREE_NODEFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_NODEFILLER_H_

#include "node.h"
#include <boost/property_tree/ptree.hpp>
#include <memory>

using boost::property_tree::ptree;
using std::shared_ptr;

class NodeFiller{
private:
public:
    NodeFiller();
	void Fill(Node& node, ptree& xml_tree);
};


#endif
