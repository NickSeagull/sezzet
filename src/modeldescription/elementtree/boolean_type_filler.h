#ifndef MODELDESCRIPTION_ELEMENTTREE_BOOLEANTYPEFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_BOOLEANTYPEFILLER_H_

#include "../v2/boolean_type.h"
#include "node.h"

class BooleanTypeFiller{
private:
    void SetField(BooleanType& boolean_type, string field_name, string field_value);
public:
    BooleanTypeFiller();
    void Fill(BooleanType& boolean_type, shared_ptr<Node> node);
};


#endif
