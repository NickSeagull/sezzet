#ifndef MODELDESCRIPTION_ELEMENTTREE_BASEUNITFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_BASEUNITFILLER_H_

#include "../v2/BaseUnit.h"
#include "Node.h"
#include <string>
#include <memory>

using std::string;
using std::shared_ptr;

class BaseUnitFiller{
private:
    void SetField(BaseUnit& base_unit, string field_name, string field_value);
public:
	BaseUnitFiller();
    void Fill(BaseUnit& base_unit, shared_ptr<Node> node);
};


#endif
