#ifndef MODELDESCRIPTION_V2_BOOLEANTYPE_H_
#define MODELDESCRIPTION_V2_BOOLEANTYPE_H_

#include <string>
#include "simple_type.h"

using std::string;

class BooleanType : public SimpleType{
private:
	string declared_type_;
	bool start_;
public:
	inline void start(bool new_start);
	inline bool start();
	inline void declared_type(string new_declared_type);
	inline string declared_type();
    BooleanType();
	template<class T>
	bool Equals(T object);
	int hash();
};


#endif

