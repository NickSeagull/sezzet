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
	vector<DisplayUnit> display_units_;
	string name_;
public:
	Unit();
	void name(string new_name);
	string name();
	shared_ptr<BaseUnit> base_unit();
	void base_unit(shared_ptr<BaseUnit> base_unit);
	vector<DisplayUnit> display_units();
	void display_units(vector<DisplayUnit> display_units);
	void AddDisplayUnit(DisplayUnit display_unit);
};

#endif 
