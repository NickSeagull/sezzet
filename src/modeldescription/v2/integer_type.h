#ifndef MODELDESCRIPTION_V2_INTEGERTYPE_H_
#define MODELDESCRIPTION_V2_INTEGERTYPE_H_

#include <string>
#include <unordered_map>
#include "simple_type.h"

using std::string;
using std::unordered_map;

class IntegerType : public SimpleType{
private:
	unordered_map<string, string> attributes_;
public:
	IntegerType();
	template<class T>
	bool Equals(T object);
	int hash();
	unordered_map<string, string> attributes();
	void set_attributes(unordered_map<string, string> attributes);
};

#endif
