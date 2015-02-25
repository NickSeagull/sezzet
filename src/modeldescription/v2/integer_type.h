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
	void start(int new_start);
	int start();
	void max(double new_max);
	double max();
	void min(double new_min);
	double min();
	void quantity(string new_quantity);
	string quantity();
	void declared_type(string new_declared_type);
	string declared_type();
	IntegerType();
	template<class T>
	bool Equals(T object);
	int hash();
};

#endif
