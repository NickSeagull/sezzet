#ifndef MODELDESCRIPTION_V2_STRINGTYPE_H_
#define MODELDESCRIPTION_V2_STRINGTYPE_H_

#include <string>
#include "simple_type.h"

using std::string;


class StringType : public SimpleType{
private:
	string declared_type_;
public:
	void declared_type(string new_declared_type);
	string declared_type();
    StringType();
	template<class T>
	bool Equals(T object);
	int hash();
};


#endif
