#ifndef MODELDESCRIPTION_ELEMENTTREE_INTEGERTYPEFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_INTEGERTYPEFILLER_H_

#include "../v2/integer_type.h"
#include "node.h"

class IntegerTypeFiller{
private:
    void SetField(IntegerType& integer_type, string field_name, string field_value);
public:
    IntegerTypeFiller();
    void Fill(IntegerType& integer_type, shared_ptr<Node> node);
};


#endif
