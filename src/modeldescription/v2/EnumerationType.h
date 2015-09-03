#ifndef MODELDESCRIPTION_V2_ENUMERATIONTYPE_H_
#define MODELDESCRIPTION_V2_ENUMERATIONTYPE_H_

#include <string>
#include <vector>
#include "SimpleType.h"

using std::string;
using std::vector;

class EnumerationType : public SimpleType{
private:
	class Item{
	private:
		string name_;
		string value_;
		string description_;
	public:
		string name();
	};

	string declared_type_;
	string quantity_;
	int min_;
	int max_;
	int start_;
	
	vector<Item> items_;	
public:
	inline void start(int new_start);
	inline int start();
	inline void max(int new_max);
	inline int max();
	inline void min(int new_min);
	inline int min();
	inline void quantity(string new_quantity);
	inline string quantity();
	inline void declared_type(string new_declared_type);
	inline string declared_type();
    EnumerationType();
	vector<Item> items();
};


#endif
