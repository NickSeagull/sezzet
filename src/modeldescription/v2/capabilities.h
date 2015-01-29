#ifndef MODELDESCRIPTION_V2_CAPABILITIES_H_
#define MODELDESCRIPTION_V2_CAPABILITIES_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class Capabilities{
private:	
    class Capability{
	private:
		string name_;
	public:
		Capability();
		string name();
	};
	
	const static Capability kNeedsExecutionTool;
	const static Capability kCanHandleVariableCommunicationStepSize;
	const static Capability kCanInterpolateInputs;
	const static Capability kCanRunAsynchronously;
	const static Capability kCanBeInstantiatedOnlyOncePerProcess;
	const static Capability kCanNotUseMemoryManagmentFunction;
	const static Capability kCanGetAndSetFmuState;
	const static Capability kProvidesDirectionalDerivative;
	
	vector<Capability> capabilities_;
	
public:
    Capabilities();
    vector<Capability> contains();
	void add(Capability capability);
};


#endif
