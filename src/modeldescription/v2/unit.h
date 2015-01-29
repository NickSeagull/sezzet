#ifndef MODELDESCRIPTION_V2_UNIT_H_
#define MODELDESCRIPTION_V2_UNIT_H_

#include <string>
#include <vector>
#include "base_unit.h"
#include "display_unit.h"
#include <unordered_map>
#include <memory>

using std::string;
using std::vector;
using std::unordered_map;
using std::shared_ptr;

struct Unit{
private:
	unordered_map<string, string> attributes_;
	shared_ptr<BaseUnit> base_unit_;
	vector<shared_ptr<DisplayUnit>> display_units_;
public:
	unordered_map<string, string> attributes();
	void set_attributes(unordered_map<string, string> attributes);
	BaseUnit base_unit();
	void set_base_unit(BaseUnit base_unit);
	vector<DisplayUnit> display_units();
	void set_display_units(vector<DisplayUnit> display_units);
};

#endif 
