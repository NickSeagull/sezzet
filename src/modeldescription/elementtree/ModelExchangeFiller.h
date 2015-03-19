#ifndef MODELDESCRIPTION_ELEMENTTREE_MODELEXCHANGEFILLER_H_
#define MODELDESCRIPTION_ELEMENTTREE_MODELEXCHANGEFILLER_H_

#include "../v2/ModelExchange.h"
#include "Node.h"
#include <memory>

using std::shared_ptr;

class ModelExchangeFiller{
private:
	void SetField(ModelExchange& model_exchange, string field_name, string field_value);
	void SetChild(ModelExchange& model_exchange, NodePointer child);
	void FillAndAddSourceFile(ModelExchange& model_exchange, NodePointer node);
public:
	ModelExchangeFiller();
	void Fill(ModelExchange& model_exchange, NodePointer node); 
};


#endif
