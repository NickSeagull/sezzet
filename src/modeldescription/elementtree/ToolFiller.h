#ifndef MODELDESCRIPTION_ELEMENTTREE_TOOLFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_TOOLFILLER_H_

#include "Tool.h"
#include "Node.h"
#include <memory>

using std::shared_ptr;

class ToolFiller{
private:
    void SetField(Tool& tool, string field_name, string field_value);
public:
    ToolFiller();
    void Fill(Tool& tool, shared_ptr<Node> node);
};


#endif
