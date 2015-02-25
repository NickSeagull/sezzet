#ifndef MODELDESCRIPTION_ELEMENTTREE_REALTYPEFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_REALTYPEFILLER_H_

#include "../v2/real_type.h"
#include "node.h"

class RealTypeFiller{
private:
    void SetField(RealType& real_type, string field_name, string field_value);
public:
    RealTypeFiller();
    void Fill(RealType& real_type, shared_ptr<Node> node);
};


#endif
