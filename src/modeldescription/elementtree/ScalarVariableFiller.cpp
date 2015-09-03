#include "ScalarVariableFiller.h"
#include "RealTypeFiller.h"
#include "IntegerTypeFiller.h"
#include "BooleanTypeFiller.h"
#include "StringTypeFiller.h"
#include <memory>

using std::make_shared;

ScalarVariableFiller::ScalarVariableFiller(){}

void ScalarVariableFiller::Fill(ScalarVariable& scalar_variable, shared_ptr<Node> node){
	for(auto& pair : node->attributes())
		SetField(scalar_variable, pair.first, pair.second);
	for(auto& child : node->childs())
		SetChild(scalar_variable, child);
}

void ScalarVariableFiller::SetField(ScalarVariable& scalar_variable, string field_name, string field_value){
	if(field_name == "causality") scalar_variable.causality(field_value);
	if(field_name == "variability") scalar_variable.variability(field_value);
	if(field_name == "name") scalar_variable.name(field_value);
	if(field_name == "description") scalar_variable.description(field_value);
	if(field_name == "initial") scalar_variable.initial(field_value);
	if(field_name == "previous") scalar_variable.previous(stoi(field_value));
	if(field_name == "canHandleMultipleSetPerTimeInstant") scalar_variable.can_handle_multiple_set_per_time_instant(field_value == "true");
}

void ScalarVariableFiller::SetChild(ScalarVariable& scalar_variable, shared_ptr<Node> child){
	if(child->name() == "Real") FillAndSetReal(scalar_variable, child);
	if(child->name() == "Integer") FillAndSetInteger(scalar_variable, child);
	if(child->name() == "Boolean") FillAndSetBoolean(scalar_variable, child);
	if(child->name() == "String") FillAndSetString(scalar_variable, child);
	if(child->name() == "Annotations") FillAndSetAnnotations(scalar_variable, child);
}

void ScalarVariableFiller::FillAndSetReal(ScalarVariable& scalar_variable, shared_ptr<Node> child){
	RealTypeFiller filler;
	RealType real;
	filler.Fill(real, child);
	scalar_variable.real(make_shared<RealType>(real));
}

void ScalarVariableFiller::FillAndSetInteger(ScalarVariable& scalar_variable, shared_ptr<Node> child){
	IntegerTypeFiller filler;
	IntegerType integer;
	filler.Fill(integer, child);
	scalar_variable.integer(make_shared<IntegerType>(integer));
}

void ScalarVariableFiller::FillAndSetBoolean(ScalarVariable& scalar_variable, shared_ptr<Node> child){
	BooleanTypeFiller filler;
	BooleanType boolean;
	filler.Fill(boolean, child);
	scalar_variable.boolean(make_shared<BooleanType>(boolean));
}

void ScalarVariableFiller::FillAndSetString(ScalarVariable& scalar_variable, shared_ptr<Node> child){
	StringTypeFiller filler;
	StringType stringg;
	filler.Fill(stringg, child);
	scalar_variable.stringg(make_shared<StringType>(stringg));
}

void ScalarVariableFiller::FillAndSetAnnotations(ScalarVariable& scalar_variable, shared_ptr<Node> child){
	ToolFiller filler;
	for(auto& node : child->childs())
		FillAndAddAnnotation(scalar_variable, node, filler);
}

void ScalarVariableFiller::FillAndAddAnnotation(ScalarVariable& scalar_variable, shared_ptr<Node> child, ToolFiller filler){
	Tool annotation;
	filler.Fill(annotation, child);
	scalar_variable.AddAnnotation(annotation);
}
