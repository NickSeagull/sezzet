#ifndef MODELDESCRIPTION_ELEMENTTREE_STRINGTYPEFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_STRINGTYPEFILLER_H_

#include "StringType.h"
#include "Node.h"

class StringTypeFiller{
private:
    void SetField(StringType& string_type, string field_name, string field_value);
public:
    StringTypeFiller();
    void Fill(StringType& string_type, shared_ptr<Node> node);
};


#endif
