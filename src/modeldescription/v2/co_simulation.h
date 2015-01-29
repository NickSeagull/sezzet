#ifndef MODELDESCRIPTION_V2_COSIMULATION_H_
#define MODELDESCRIPTION_V2_COSIMULATION_H_

#include <unordered_map>
#include <string>
#include <vector>
#include "source_file.h"
#include "capabilities.h"
#include <memory>

using std::unordered_map;
using std::string;
using std::vector;
using std::shared_ptr;

class CoSimulation{
private:
    unordered_map<string, string> attributes_;
	vector<SourceFile> source_files_;
	shared_ptr<Capabilities> capabilities_;
public:
    CoSimulation();
    unordered_map<string, string> attributes();
	shared_ptr<Capabilities> capabilities();
};


#endif
