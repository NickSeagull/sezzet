#ifndef MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_ELEMENT_H_
#define MODELDESCRIPTION_MODELDESCRIPTIONELEMENTTREE_ELEMENT_H_

#include "content.h"
#include "node.h"

class Element : public Content{
private:
    Node node_;
public:
    Element(Node node);
    Node node();
};


#endif
