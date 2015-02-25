#ifndef MODELDESCRIPTION_V2_REALTYPE_H_
#define MODELDESCRIPTION_V2_REALTYPE_H_

#include <string>
#include "simple_type.h"

using std::string;


class RealType : public SimpleType{
private:
	string declared_type_;
	string quantity_;
	string unit_;
	string display_unit_;
	bool relative_quantity_;
	double min_;
	double max_;
	double nominal_;
	bool unbound_;
	double start_;
	int derivative_;
	bool reinit_;
public:
	void reinit(bool new_reinit);
	bool reinit();
	void derivative(int new_derivative);
	int derivative();
	void start(double new_start);
	double start();
	void unbound(bool new_unbound);
	bool unbound();
	void nominal(double new_nominal);
	double nominal();
	void max(double new_max);
	double max();
	void min(double new_min);
	double min();
	void relative_quantity(bool new_relative_quantity);
	bool relative_quantity();
	void display_unit(string new_display_unit);
	string display_unit();
	void unit(string new_unit);
	string unit();
	void quantity(string new_quantity);
	string quantity();
	void declared_type(string new_declared_type);
	string declared_type();
	RealType();
	template<class T>
	bool Equals(T object);
	int hash();
};

#endif
