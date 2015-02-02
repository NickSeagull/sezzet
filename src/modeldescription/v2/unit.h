#ifndef MODELDESCRIPTION_V2_UNIT_H_
#define MODELDESCRIPTION_V2_UNIT_H_

#include <string>
#include <vector>
#include "base_unit.h"
#include "display_unit.h"
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;

struct Unit{
private:
	shared_ptr<BaseUnit> base_unit_;
	vector<shared_ptr<DisplayUnit>> display_units_;
	string name_;
public:
	inline void name(string new_name);
	inline string name();
	BaseUnit base_unit();
	void base_unit(BaseUnit base_unit);
	vector<DisplayUnit> display_units();
	void display_units(vector<DisplayUnit> display_units);
};

#endif 
