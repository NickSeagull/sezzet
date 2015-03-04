#ifndef MODELDESCRIPTION_ELEMENTTREE_COSIMULATIONFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_COSIMULATIONFILLER_H_

#include "CoSimulation.h"
#include "Node.h"
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
