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
	inline void reinit(bool new_reinit);
	inline bool reinit();
	inline void derivative(int new_derivative);
	inline int derivative();
	inline void start(double new_start);
	inline double start();
	inline void unbound(bool new_unbound);
	inline bool unbound();
	inline void nominal(double new_nominal);
	inline double nominal();
	inline void max(double new_max);
	inline double max();
	inline void min(double new_min);
	inline double min();
	inline void relative_quantity(bool new_relative_quantity);
	inline bool relative_quantity();
	inline void display_unit(string new_display_unit);
	inline string display_unit();
	inline void unit(string new_unit);
	inline string unit();
	inline void quantity(string new_quantity);
	inline string quantity();
	inline void declared_type(string new_declared_type);
	inline string declared_type();
	RealType();
	template<class T>
	bool Equals(T object);
	int hash();
};

#endif
