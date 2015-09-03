#ifndef MODELDESCRIPTION_V2_MODELSTRUCTURE_H_
#define MODELDESCRIPTION_V2_MODELSTRUCTURE_H_

#include <unordered_map>
#include <string>
#include <vector>
#include "Unknown.h"

using std::unordered_map;
using std::string;
using std::vector;

class ModelStructure{
private:
	vector<Unknown> outputs_;
	vector<Unknown> derivatives_;
	vector<Unknown> unknowns_;
public:
    ModelStructure();
	vector<Unknown> outputs();
	void outputs(vector<Unknown> new_outputs);
	void AddOutput(Unknown output);
	vector<Unknown> derivatives();
	void derivatives(vector<Unknown> new_derivatives);
	void AddDerivative(Unknown output);
	vector<Unknown> unknowns();
	void unknowns(vector<Unknown> new_unknowns);
	void AddUnknown(Unknown unknown);
};


#endif
