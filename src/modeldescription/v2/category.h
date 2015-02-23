#ifndef MODELDESCRIPTION_V2_CATEGORY_H_
#define MODELDESCRIPTION_V2_CATEGORY_H_

#include <string>

using std::string;

struct Category{
private:
	string name_;
	string description_;
	
public:
	void description(string new_description);
	string description();
	void name(string new_name);
	string name();
};

#endif
