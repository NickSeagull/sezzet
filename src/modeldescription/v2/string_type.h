#ifndef MODELDESCRIPTION_V2_STRINGTYPE_H_
#define MODELDESCRIPTION_V2_STRINGTYPE_H_

#include <unordered_map>
#include <string>
#include "simple_type.h"

using std::unordered_map;
using std::string;


class StringType : public SimpleType{
private:
	unordered_map<string, string> attributes_;
public:
    StringType();
	template<class T>
	bool Equals(T object);
	int hash();
};


#endif
