#ifndef MODELDESCRIPTION_ELEMENTTREE_INTEGERTYPEFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_INTEGERTYPEFILLER_H_

#include "../v2/IntegerType.h"
#include "Node.h"

class IntegerTypeFiller{
private:
    void SetField(IntegerType& integer_type, string field_name, string field_value);
public:
    IntegerTypeFiller();
    void Fill(IntegerType& integer_type, NodePointer node);
};


#endif
