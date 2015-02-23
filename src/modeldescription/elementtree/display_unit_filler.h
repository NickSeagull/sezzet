#ifndef MODELDESCRIPTION_ELEMENTTREE_DISPLAYUNITFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_DISPLAYUNITFILLER_H_

#include "../v2/display_unit.h"
#include "node.h"
#include <memory>

using std::shared_ptr;

class DisplayUnitFiller{
private:
    void SetField(DisplayUnit& display_unit, string field_name, string field_value);
public:
    DisplayUnitFiller();
    void Fill(DisplayUnit& display_unit, shared_ptr<Node> node);
};


#endif
