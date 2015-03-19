#ifndef MODELDESCRIPTION_ELEMENTTREE_DISPLAYUNITFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_DISPLAYUNITFILLER_H_

#include "../v2/DisplayUnit.h"
#include "Node.h"
#include <memory>

using std::shared_ptr;

class DisplayUnitFiller{
private:
    void SetField(DisplayUnit& display_unit, string field_name, string field_value);
public:
    DisplayUnitFiller();
    void Fill(DisplayUnit& display_unit, NodePointer node);
};


#endif
