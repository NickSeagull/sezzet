#ifndef MODELDESCRIPTION_ELEMENTTREE_SCALARVARIABLEFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_SCALARVARIABLEFILLER_H_

#include "ScalarVariable.h"
#include "Node.h"
#include "ToolFiller.h"

class ScalarVariableFiller{
private:
    void SetField(ScalarVariable& scalar_variable, string field_name, string field_value);
	void SetChild(ScalarVariable& scalar_variable, shared_ptr<Node> child);
	void FillAndSetReal(ScalarVariable& scalar_variable, shared_ptr<Node> child);
	void FillAndSetInteger(ScalarVariable& scalar_variable, shared_ptr<Node> child);
	void FillAndSetBoolean(ScalarVariable& scalar_variable, shared_ptr<Node> child);
	void FillAndSetString(ScalarVariable& scalar_variable, shared_ptr<Node> child);
	void FillAndSetAnnotations(ScalarVariable& scalar_variable, shared_ptr<Node> child);
	void FillAndAddAnnotation(ScalarVariable& scalar_variable, shared_ptr<Node> child, ToolFiller filler);
public:
	ScalarVariableFiller();
	void Fill(ScalarVariable& scalar_variable, shared_ptr<Node> node);
};


#endif
