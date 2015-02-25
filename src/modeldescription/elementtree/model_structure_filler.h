#ifndef MODELDESCRIPTION_ELEMENTTREE_MODELSTRUCTUREFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_MODELSTRUCTUREFILLER_H_

#include "../v2/model_structure.h"
#include "node.h"

class ModelStructureFiller{
private:
    void SetChild(ModelStructure& model_structure, shared_ptr<Node> child);
public:
    ModelStructureFiller();
    void Fill(ModelStructure& model_structure, shared_ptr<Node> node);
};


#endif
