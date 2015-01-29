#ifndef MODELDESCRIPTION_V2_ENUMERATIONTYPE_H_
#define MODELDESCRIPTION_V2_ENUMERATIONTYPE_H_

#include <unordered_map>
#include <string>
#include <vector>
#include "item.h"
#include "simple_type.h"

using std::unordered_map;
using std::string;
using std::vector;

class EnumerationType : public SimpleType{
private:
    unordered_map<string, string> attributes_;
	vector<shared_ptr<Item>> items_;
public:
    EnumerationType();
	vector<shared_ptr<Item>> items();
};


#endif
