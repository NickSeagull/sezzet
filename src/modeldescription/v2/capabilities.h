#ifndef MODELDESCRIPTION_V2_CAPABILITIES_H_
#define MODELDESCRIPTION_V2_CAPABILITIES_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class Capabilities{
private:	
	vector<string> capabilities_;
public:
    const static string kNeedsExecutionTool;
	const static string kCanHandleVariableCommunicationStepSize;
	const static string kCanInterpolateInputs;
	const static string kCanRunAsynchronously;
	const static string kCanBeInstantiatedOnlyOncePerProcess;
	const static string kCanNotUseMemoryManagmentFunction;
	const static string kCanGetAndSetFmuState;
	const static string kCanSerializeFmuState;
	const static string kProvidesDirectionalDerivative;
	
    Capabilities();
	bool Check(string capability);
	void Add(string capability);
};


#endif
