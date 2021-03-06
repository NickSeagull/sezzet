#include "CoSimulationFiller.h"
#include "SourceFileFiller.h"
#include <memory>

using std::make_shared;

CoSimulationFiller::CoSimulationFiller(){}

void CoSimulationFiller::Fill(CoSimulation& co_simulation, shared_ptr<Node> node){
	for(auto& pair : node->attributes())
		SetField(co_simulation, pair.first, pair.second);
	for(auto& child : node->childs())
		SetChild(co_simulation, child);
	SetCapabilities(co_simulation);
}

void CoSimulationFiller::SetField(CoSimulation& co_simulation, string field_name, string field_value){
	if(field_name == "modelIdentifier") co_simulation.model_identifier(field_value);
	if(field_name == "needsExecutionTool") co_simulation.needs_execution_tool(field_value == "true");
	if(field_name == "canHandleVariableCommunicationStepSize") co_simulation.can_handle_variable_communication_step_size(field_value == "true");
	if(field_name == "canInterpolateInputs") co_simulation.can_interpolate_inputs(field_value == "true");
	if(field_name == "maxOutputDerivativeOrder") co_simulation.max_output_derivative_order(stoi(field_value));
	if(field_name == "canRunAsynchronously") co_simulation.can_run_asynchronously(field_value == "true");
	if(field_name == "canBeInstantiatedOnlyOncePerProcess") co_simulation.can_be_instantiated_only_once_per_process(field_value == "true");
	if(field_name == "canNotUseMemoryManagementFunctions") co_simulation.can_not_use_memory_management_functions(field_value == "true");
	if(field_name == "canGetAndSetFmuState") co_simulation.can_get_and_set_fmu_state(field_value == "true");
	if(field_name == "canSerializeFmuState") co_simulation.can_serialize_fmu_state(field_value == "true");
	if(field_name == "providesDirectionalDerivative") co_simulation.provides_directional_derivative(field_value == "true");
}

void CoSimulationFiller::SetChild(CoSimulation& co_simulation, shared_ptr<Node> child){
	if(child->name() == "SourceFile") FillAndAddSourceFile(co_simulation, child);
}

void CoSimulationFiller::FillAndAddSourceFile(CoSimulation& co_simulation, shared_ptr<Node> node){
	SourceFileFiller filler;
	SourceFile source_file;
	filler.Fill(source_file, node);
	co_simulation.AddSourceFile(source_file);
}

void CoSimulationFiller::SetCapabilities(CoSimulation& co_simulation){
	Capabilities capabilities;
	if (co_simulation.needs_execution_tool()) capabilities.Add(Capabilities::kNeedsExecutionTool);
	if (co_simulation.can_interpolate_inputs()) capabilities.Add(Capabilities::kCanInterpolateInputs);
	if (co_simulation.can_run_asynchronously()) capabilities.Add(Capabilities::kCanRunAsynchronously);
	if (co_simulation.can_be_instantiated_only_once_per_process()) capabilities.Add(Capabilities::kCanBeInstantiatedOnlyOncePerProcess);
	if (co_simulation.can_not_use_memory_management_functions()) capabilities.Add(Capabilities::kCanNotUseMemoryManagmentFunction);
	if (co_simulation.can_get_and_set_fmu_state()) capabilities.Add(Capabilities::kCanGetAndSetFmuState);
	if (co_simulation.can_serialize_fmu_state()) capabilities.Add(Capabilities::kCanSerializeFmuState);
	if (co_simulation.provides_directional_derivative()) capabilities.Add(Capabilities::kProvidesDirectionalDerivative);
	co_simulation.capabilities(make_shared<Capabilities>(capabilities));
}
