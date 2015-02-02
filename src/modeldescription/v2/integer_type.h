#ifndef MODELDESCRIPTION_V2_INTEGERTYPE_H_
#define MODELDESCRIPTION_V2_INTEGERTYPE_H_

#include <string>

#include "simple_type.h"

using std::string;


class IntegerType : public SimpleType{
private:
	string declared_type_;
	string quantity_;
	double min_;
	double max_;
	int start_;
public:
	inline void start(int new_start);
	inline int start();
	inline void max(double new_max);
	inline double max();
	inline void min(double new_min);
	inline double min();
	inline void quantity(string new_quantity);
	inline string quantity();
	inline void declared_type(string new_declared_type);
	inline string declared_type();
	IntegerType();
	template<class T>
	bool Equals(T object);
	int hash();
};

#endif
