#include "UnitFiller.h"
#include "BaseUnitFiller.h"
#include "DisplayUnitFiller.h"
#include <memory>

using std::make_shared;

UnitFiller::UnitFiller(){}

void UnitFiller::Fill(Unit& unit, NodePointer node){
	for(auto& pair : node->attributes())
		SetField(unit, pair.first, pair.second);
	for(auto& child : node->childs())
		SetChild(unit, child);
}

void UnitFiller::SetField(Unit& unit, string field_name, string field_value){
	if(field_name == "name") unit.name(field_value);
}

void UnitFiller::SetChild(Unit& unit, NodePointer child){
	if(child->name() == "baseUnit") FillAndSetBaseUnit(unit, child);
	if(child->name() == "displayUnit") FillAndAddDisplayUnit(unit, child);
}

void UnitFiller::FillAndSetBaseUnit(Unit& unit, NodePointer child){
	BaseUnitFiller filler;
	BaseUnit base_unit;
	filler.Fill(base_unit, child);
	unit.base_unit(make_shared<BaseUnit>(base_unit));
}

void UnitFiller::FillAndAddDisplayUnit(Unit& unit, NodePointer child){
	DisplayUnitFiller filler;
	DisplayUnit display_unit;
	filler.Fill(display_unit, child);
	unit.AddDisplayUnit(display_unit);
}
