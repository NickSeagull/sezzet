#ifndef MODELDESCRIPTION_ELEMENTTREE_UNITFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_UNITFILLER_H_

#include "../v2/Unit.h"
#include "Node.h"

class UnitFiller{
private:
	void SetField(Unit& unit, string field_name, string field_value);
	void SetChild(Unit& unit, NodePointer child);
	void FillAndSetBaseUnit(Unit& unit, NodePointer child);
	void FillAndAddDisplayUnit(Unit& unit, NodePointer child);
public:
	UnitFiller();
	void Fill(Unit& unit, NodePointer node);
};


#endif
