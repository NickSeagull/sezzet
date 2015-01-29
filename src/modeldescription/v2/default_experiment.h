#ifndef MODELDESCRIPTION_V2_DEFAULTEXPERIMENT_H_
#define MODELDESCRIPTION_V2_DEFAULTEXPERIMENT_H_

#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;

class DefaultExperiment{
private:
    unordered_map<string, string> attributes_;
public:
    DefaultExperiment();
	unordered_map<string, string> attributes();
};


#endif
