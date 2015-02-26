#ifndef MODELDESCRIPTION_ELEMENTTREE_UNKNOWNFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_UNKNOWNFILLER_H_

#include "../v2/unknown.h"
#include "node.h"

class UnknownFiller{
private:
    void SetField(Unknown& unknown, string field_name, string field_value);
public:
    UnknownFiller();
    void Fill(Unknown& unknown, shared_ptr<Node> node);
};


#endif
