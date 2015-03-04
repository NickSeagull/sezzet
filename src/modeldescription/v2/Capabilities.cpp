#include "Capabilities.h"
#include <algorithm>

using std::find;

const string Capabilities::kNeedsExecutionTool = "needsExecutionTool";
const string Capabilities::kCanHandleVariableCommunicationStepSize = "canHandleVariableCommunicationStepSize";
const string Capabilities::kCanInterpolateInputs = "canInterpolateInputs";
const string Capabilities::kCanRunAsynchronously = "canRunAsynchronously";
const string Capabilities::kCanBeInstantiatedOnlyOncePerProcess = "canBeInstantiatedOnlyOncePerProcess";
const string Capabilities::kCanNotUseMemoryManagmentFunction = "canNotUseMemoryManagmentFunction";
const string Capabilities::kCanGetAndSetFmuState = "canGetAndSetFmuState";
const string Capabilities::kCanSerializeFmuState = "canSerializeFmuState";
const string Capabilities::kProvidesDirectionalDerivative = "providesDirectionalDerivative";

Capabilities::Capabilities(){}

bool Capabilities::Check(string capability){
	return find(capabilities_.begin(), capabilities_.end(), capability) != capabilities_.end();
}

void Capabilities::Add(string capability){
	capabilities_.push_back(capability);
}
