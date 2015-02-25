#ifndef MODELDESCRIPTION_ELEMENTTREE_DEFAULTEXPERIMENTFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_DEFAULTEXPERIMENTFILLER_H_

#include "../v2/default_experiment.h"
#include "node.h"
#include <memory>

using std::shared_ptr;

class DefaultExperimentFiller{
private:
    void SetField(DefaultExperiment& default_experiment, string field_name, string field_value);
public:
    DefaultExperimentFiller();
    void Fill(DefaultExperiment& default_experiment, shared_ptr<Node> node);
};


#endif
