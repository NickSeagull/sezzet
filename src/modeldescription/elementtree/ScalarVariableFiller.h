#ifndef MODELDESCRIPTION_ELEMENTTREE_SCALARVARIABLEFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_SCALARVARIABLEFILLER_H_

#include "../v2/ScalarVariable.h"
#include "Node.h"
#include "ToolFiller.h"

class ScalarVariableFiller{
private:
    void SetField(ScalarVariable& scalar_variable, string field_name, string field_value);
	void SetChild(ScalarVariable& scalar_variable, NodePointer child);
	void FillAndSetReal(ScalarVariable& scalar_variable, NodePointer child);
	void FillAndSetInteger(ScalarVariable& scalar_variable, NodePointer child);
	void FillAndSetBoolean(ScalarVariable& scalar_variable, NodePointer child);
	void FillAndSetString(ScalarVariable& scalar_variable, NodePointer child);
	void FillAndSetAnnotations(ScalarVariable& scalar_variable, NodePointer child);
	void FillAndAddAnnotation(ScalarVariable& scalar_variable, NodePointer child, ToolFiller filler);
public:
	ScalarVariableFiller();
	void Fill(ScalarVariable& scalar_variable, NodePointer node);
};


#endif
