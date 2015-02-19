#ifndef MODELDESCRIPTION_ELEMENTTREE_COSIMULATIONFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_COSIMULATIONFILLER_H_

#include "../v2/co_simulation.h"
#include "node.h"
#include <memory>

using std::shared_ptr;

class CoSimulationFiller{
private:
	void SetField(CoSimulation& co_simulation, string field_name, string field_value);
	void SetChild(CoSimulation& co_simulation, shared_ptr<Node> child);
	void FillAndAddSourceFile(CoSimulation& co_simulation, shared_ptr<Node> child);
	void SetCapabilities(CoSimulation& co_simulation);
public:
	CoSimulationFiller();
    void Fill(CoSimulation& co_simulation, shared_ptr<Node> node);
};


#endif
