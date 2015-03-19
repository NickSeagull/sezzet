#ifndef MODELDESCRIPTION_ELEMENTTREE_CATEGORYFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_CATEGORYFILLER_H_

#include "../v2/Category.h"
#include "Node.h"
#include <memory>

using std::shared_ptr;

class CategoryFiller{
private:
    void SetField(Category& category, string field_name, string field_value);
public:
    CategoryFiller();
    void Fill(Category& category, NodePointer node);
};


#endif
