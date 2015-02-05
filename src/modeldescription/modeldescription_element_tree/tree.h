#ifndef MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_ELEMENTTREE_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_ELEMENTTREE_H_

#include <memory>
#include "node.h"

using std::shared_ptr;

class Tree{
private:
    shared_ptr<Node> root_;
public:
	Tree();
};


#endif
