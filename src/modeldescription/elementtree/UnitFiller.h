#ifndef MODELDESCRIPTION_ELEMENTTREE_UNITFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_UNITFILLER_H_

#include "Unit.h"
#include "Node.h"

class UnitFiller{
private:
    void SetField(Unit& unit, string field_name, string field_value);
	void SetChild(Unit& unit, shared_ptr<Node> child);
	void FillAndSetBaseUnit(Unit& unit, shared_ptr<Node> child);
	void FillAndAddDisplayUnit(Unit& unit, shared_ptr<Node> child);
public:
	UnitFiller();
	void Fill(Unit& unit, shared_ptr<Node> node);
};


#endif
